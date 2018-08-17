//
// Created by dawid on 23.07.18.
//

#pragma once

#include <boost/asio.hpp>
#include "ServerConfiguration.h"

/** \brief Main class support tcp connections
 *
 */
class ConnectionsServer {
 private:
  void startAccept();

  boost::asio::ip::tcp::acceptor mAcceptor;
  boost::asio::io_service mServiceIO;
  unsigned mThreadPoolSize {1};

 public:
  explicit ConnectionsServer(const ServerConfiguration &config);
};

