//
// Created by dawid on 18.07.18.
//

#include "GlobalFlags.h"
const std::atomic<bool> &GlobalFlags::getDaemonizeServer() const {
  return mDaemonizeServer;
}
void GlobalFlags::setDaemonizeServer(const std::atomic<bool> &mDaemonizeServer) {
  GlobalFlags::mDaemonizeServer.store(mDaemonizeServer);
}
