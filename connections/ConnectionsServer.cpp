//
// Created by dawid on 23.07.18.
//

#include <boost/bind.hpp>
#include "ConnectionsServer.h"
#include "ClientConnection.h"

using namespace boost::asio;

void ConnectionsServer::startAccept() {
  ClientConnection::connectionPointer newConnection =
      std::make_shared<ClientConnection>(ClientConnection(mServiceIO));

  mAcceptor.async_accept(newConnection->getSocket(), boost::bind(
      &ConnectionsServer::handleAccept, this, newConnection,
      placeholders::error));
}

void ConnectionsServer::handleAccept(ClientConnection::connectionPointer connection,
                                    const boost::system::error_code &code) {

}

ConnectionsServer::ConnectionsServer(const ServerConfiguration &config)
  : mAcceptor(config.getIoService(),
              ip::tcp::endpoint(ip::tcp::v4(), config.getSocketNumber())),
    mServiceIO(config.getIoService()),
    mThreadPoolSize(config.getThreadPoolSize()) {
  startAccept();
}
