//
// Created by dawid on 23.07.18.
//

#include <boost/asio.hpp>
#include <iostream>
#include "ClientConnection.h"

using namespace boost::asio;

ClientConnection::ClientConnection(boost::asio::io_service &ioService) :
  mStrand(ioService),
  mSocket(ioService)
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
  //auto self(shared_from_this());

  boost::asio::streambuf buffer;

  async_read(mSocket, buffer,
      [&](boost::system::error_code errorCode, std::size_t) {
//        std::cout << std::string(std::istreambuf_iterator<char>(&buffer),
//            std::istreambuf_iterator<char>());
  });

  std::string s(std::istreambuf_iterator<char>(&buffer), std::istreambuf_iterator<char>());
  std::cout << s;
}