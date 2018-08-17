//
// Created by dawid on 23.07.18.
//

#pragma once

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/strand.hpp>
#include <boost/asio/streambuf.hpp>

/** \brief Connection handling
 *
 */
class ClientConnection : public std::enable_shared_from_this<ClientConnection> {
 private:
  boost::asio::ip::tcp::socket mSocket;
  boost::asio::io_service::strand mStrand;

  void readDataFromClient();

 public:
  typedef std::shared_ptr<ClientConnection> connectionPointer;

  ClientConnection(boost::asio::io_service &ioService);

  boost::asio::ip::tcp::socket &getSocket();
  void run();
};

