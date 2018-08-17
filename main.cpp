#include <iostream>
#include <syslog.h>
#include "main/DaemonServer.h"
#include "main/OptionsHandler.h"

int main(int argc, char **argv) {
  //start logging to system log
  openlog("eventServerDaemon", LOG_PID, LOG_DAEMON);

  OptionsHandler options(argc, argv);
  DaemonServer daemon;
  try {
    syslog(LOG_INFO, "Load config file");
    daemon.loadConfig("path/to/config");
    syslog(LOG_INFO, "Start daemonize");
//TODO: add switch to demonize
    //daemon.daemonize();
    syslog(LOG_INFO, "Run all subsystems");
    daemon.run();
  }catch (std::exception &e) {
    syslog(LOG_ERR, "Error while daemonizing: %s", e.what());
  }

  closelog();
  return 0;
}