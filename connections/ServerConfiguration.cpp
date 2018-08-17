//
// Created by dawid on 23.07.18.
//

#include "ServerConfiguration.h"

ServerConfiguration::ServerConfiguration(boost::asio::io_service &ioService,
                                         unsigned threadNumber, unsigned socket)
  : mIoService(ioService),
    mThreadPoolSize(threadNumber),
    mSocketNumber(socket)
{
}
boost::asio::io_service &ServerConfiguration::getIoService() const {
  return mIoService;
};
unsigned ServerConfiguration::getSocketNumber() const {
  return mSocketNumber;
};
unsigned ServerConfiguration::getThreadPoolSize() const {
  return mThreadPoolSize;
};