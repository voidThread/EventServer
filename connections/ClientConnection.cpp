//
// Created by dawid on 23.07.18.
//

#include <boost/asio.hpp>
#include <iostream>
#include <vector>
#include <boost/bind.hpp>
#include <syslog.h>
#include "ClientConnection.h"

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
  readDataFromClient();
}
void ClientConnection::readDataFromClient() {
  async_read(mSocket, mBuffer, boost::bind(&ClientConnection::handleReadData,
      shared_from_this(), placeholders::error,
          placeholders::bytes_transferred));
}
void ClientConnection::handleReadData(boost::system::error_code errorCode,
    std::size_t length) {
  if (!errorCode) {
    std::cout << std::ostream(&mBuffer).rdbuf() << std::endl;
  } else {
    syslog(LOG_ERR, "Empty data send in connection.\nError Code: %s",
        errorCode.message().c_str());
  }
}