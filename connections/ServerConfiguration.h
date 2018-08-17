//
// Created by dawid on 23.07.18.
//

#pragma once

#include <boost/asio.hpp>

/** \brief class for injection to connection server
 *
 */
class ServerConfiguration {
 private:
  unsigned mSocketNumber {65535};
  unsigned mThreadPoolSize {1};
  boost::asio::io_service &mIoService;

 public:
  ServerConfiguration(boost::asio::io_service &ioService, unsigned threadNumber,
                      unsigned socket);

  boost::asio::io_service &getIoService() const;
  unsigned getSocketNumber() const;
  unsigned getThreadPoolSize() const;
};

