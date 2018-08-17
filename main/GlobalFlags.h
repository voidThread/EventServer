//
// Created by dawid on 18.07.18.
//

#pragma once

#include <atomic>

/** \brief Singleton class with flags that are access in server
 *
 */
class GlobalFlags final{
 private:
  GlobalFlags();
  GlobalFlags(GlobalFlags const&) = delete;
  void operator=(GlobalFlags const&) =delete;

  std::atomic<bool> mDaemonizeServer {true};

 public:
  static GlobalFlags& getInstance();

  const std::atomic<bool> &getDaemonizeServer() const;
  void setDaemonizeServer(const std::atomic<bool> &mDaemonizeServer);
};

