//
// Created by dawid on 23.07.18.
//

#include "ConnectionsServer.h"

using namespace boost::asio;

void ConnectionsServer::startAccept() {

}
ConnectionsServer::ConnectionsServer(const ServerConfiguration &config)
  : mAcceptor(config.getIoService(),
              ip::tcp::endpoint(ip::tcp::v4(), config.getSocketNumber())),
    mServiceIO(config.getIoService()),
    mThreadPoolSize(config.getThreadPoolSize()) {
  startAccept();
}
