//
// Created by dawid on 23.07.18.
//

#include <boost/asio.hpp>
#include <iostream>
#include <vector>
#include <boost/bind.hpp>
#include <syslog.h>
#include <google/protobuf/stubs/common.h>
#include "ClientConnection.h"
#include "../proto/messages.pb.h"

using namespace boost::asio;

ClientConnection::ClientConnection(boost::asio::io_service &ioService) :
  mStrand(ioService),
  mSocket(ioService),
  refToService(ioService)
{
}
ClientConnection::ClientConnection(const ClientConnection &&moveConnection) :
  mSocket(moveConnection.refToService),
  mStrand(moveConnection.refToService),
  refToService(moveConnection.refToService)
{
}
boost::asio::ip::tcp::socket &ClientConnection::getSocket() {
  return mSocket;
}
void ClientConnection::run() {
  //connection data operation
  readHeaderMessage();
}
void ClientConnection::readHeaderMessage() {
  async_read(mSocket, mBuffer, boost::bind(&ClientConnection::handleReadHeaderMessage,
      shared_from_this(), placeholders::error, placeholders::bytes_transferred));
};
void ClientConnection::handleReadHeaderMessage(boost::system::error_code errorCode,
    std::size_t length) {
  if (mBuffer.size() == length) {
    //TODO pack to struct
    int8_t *messageDatalength {0};
    int8_t *messageDataType {0};

    std::vector<char> len;

    auto mutableBuffer = mBuffer.prepare(6);
    std::copy(len.begin(), len.end(), boost::asio::buffer_cast<char*>(mutableBuffer));
    mBuffer.commit(6);

    mutableBuffer = mBuffer.prepare(sizeof(int8_t));
    messageDataType = buffer_cast<int8_t*>(mutableBuffer);
    std::cout << *messageDataType;
    mBuffer.commit(sizeof(int8_t));

    if (mBuffer.size() != 0) {
      syslog(LOG_INFO, "Some data stay in buffer after read header!");
    }

    readDataFromClient();
  }
}
void ClientConnection::readDataFromClient() {
  async_read(mSocket, mBuffer, boost::bind(&ClientConnection::handleReadData,
      shared_from_this(), placeholders::error, placeholders::bytes_transferred));
}
void ClientConnection::handleReadData(boost::system::error_code errorCode,
    std::size_t length) {
  //verify version of the library
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  events::EventMessage newEvent;

  if ((errorCode == boost::asio::error::eof && length > 0) && (!errorCode && length > 0)) {

    //TODO extract to other class
    std::istream dataFromClient(&mBuffer);
    std::cout << dataFromClient.rdbuf() << std::endl;
    if (!newEvent.ParseFromIstream(&dataFromClient)) {
      syslog(LOG_INFO, "Can not parse input data.");
      mSocket.close();
    }

    if (dataFromClient.eof()) {
      long position = dataFromClient.tellg();
      std::cout << "Buffer is empty, parser consume all" << std::endl;
    } else {
      long position = dataFromClient.tellg();
      syslog(LOG_ERR,
      "Something wrong with input data from socket. Some data still in buffer\n");
    }
  } else if (!(errorCode == boost::asio::error::eof)) {
    syslog(LOG_ERR, "Empty data send in connection.\nError Code: %s",
        errorCode.message().c_str());
  }
}