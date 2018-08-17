//
// Created by dawid on 23.07.18.
//

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