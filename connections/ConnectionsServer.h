//
// Created by dawid on 23.07.18.
//

#pragma once

#include <boost/asio.hpp>
#include "ServerConfiguration.h"
#include "ClientConnection.h"

/** \brief Main class support tcp connections
 *
 */
class ConnectionsServer {
 private:
  void startAccept();
  void handleAccept(ClientConnection::connectionPointer connection,
      const boost::system::error_code &code);

  boost::asio::ip::tcp::acceptor mAcceptor;
  boost::asio::io_service &mServiceIO;
  unsigned mThreadPoolSize {1};

 public:
  explicit ConnectionsServer(ServerConfiguration &config);
};

