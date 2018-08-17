//
// Created by dawid on 23.07.18.
//

#include "ServerConfiguration.h"

ServerConfiguration::ServerConfiguration(unsigned threadNumber, unsigned socket)
  : mThreadPoolSize(threadNumber),
    mSocketNumber(socket),
    mIoService()
{
}
boost::asio::io_service &ServerConfiguration::getIoService() {
  return mIoService;
};
unsigned ServerConfiguration::getSocketNumber() const {
  return mSocketNumber;
};
unsigned ServerConfiguration::getThreadPoolSize() const {
  return mThreadPoolSize;
};