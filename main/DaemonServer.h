//
// Created by dawid on 18.07.18.
//

#pragma once

#include <string>

/** \brief Class for daemonize server process
 *
 */
class DaemonServer {
 private:
  std::string mConfigPath;

 public:
  void loadConfig(const std::string &path);
  void daemonize();
  void run();
};

