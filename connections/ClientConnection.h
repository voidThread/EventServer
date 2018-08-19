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
  boost::asio::io_service &refToService;
  boost::asio::streambuf mBuffer;

  void readDataFromClient();
  void handleReadData(boost::system::error_code errorCode, std::size_t length);

 public:
  typedef std::shared_ptr<ClientConnection> connectionPointer;

  ClientConnection(boost::asio::io_service &ioService);
  ClientConnection(const ClientConnection &&moveConnection);
  ClientConnection& operator=(ClientConnection &&moveConnection) = default;
  virtual ~ClientConnection() {};

  boost::asio::ip::tcp::socket &getSocket();
  void run();
};

