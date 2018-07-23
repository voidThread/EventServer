//
// Created by dawid on 18.07.18.
//

#include "GlobalFlags.h"
const std::atomic<bool> &GlobalFlags::getMDaemonizeServer() const {
  return mDaemonizeServer;
}
void GlobalFlags::setMDaemonizeServer(const std::atomic<bool> &mDaemonizeServer) {
  GlobalFlags::mDaemonizeServer.store(mDaemonizeServer);
}
const std::atomic<unsigned short> &GlobalFlags::getMSocketNumber() const {
  return mSocketNumber;
}
void GlobalFlags::setMSocketNumber(const std::atomic<unsigned short> &mSocketNumber) {
  GlobalFlags::mSocketNumber.store(mSocketNumber);
}
