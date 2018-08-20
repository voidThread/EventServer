//
// Created by dawid on 18.07.18.
//

#include "DaemonServer.h"
#include "../connections/ServerConfiguration.h"
#include "../connections/ConnectionsServer.h"
#include <unistd.h>
#include <signal.h>
#include <cstring>
#include <stdexcept>
#include <sys/stat.h>
#include <array>
#include <google/protobuf/stubs/common.h>


void DaemonServer::loadConfig(const std::string &path) {

}
void DaemonServer::daemonize() {
  pid_t pid{0};
  pid_t oryginalPid = getpid();
  sigset_t mask;
  sigemptyset(&mask);
  sigaddset(&mask, SIGUSR1);
  sigprocmask(SIG_BLOCK, &mask, nullptr);

  //fork first time to create grandchild
  pid = fork();

  //if pid is more then 0 we have successful forked process
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }
  //something goes wrong check errno and throw exception
  if (pid < 0) {
    throw std::runtime_error("Error while forking " +
        std::string(std::strerror(errno)));
  }

  setsid();
  signal(SIGCHLD, SIG_IGN);

  //fork second time
  pid = fork();

  if (pid > 0) {
    kill(oryginalPid, SIGUSR1);
    exit(EXIT_SUCCESS);
  }
  if (pid < 0) {
    throw std::runtime_error("Error while forking " +
        std::string(std::strerror(errno)));
  }

  //owner rwx; group rwx
  umask(0007);
  //switch to root
  chdir("/");

  const std::array<int, 3> standardFileDescriptors = {STDERR_FILENO,
                                                      STDIN_FILENO,
                                                      STDOUT_FILENO};
  for (auto item : standardFileDescriptors) {
    close(item);
  }
}
void DaemonServer::run() {
  //run subsystems

  //TODO change hardcode values to from config file
  ServerConfiguration serverConfig(2, 9988);
  ConnectionsServer connectionsServer(serverConfig);
//  sleep(30);
//  google::protobuf::ShutdownProtobufLibrary();
}