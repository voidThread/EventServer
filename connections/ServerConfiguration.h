//
// Created by dawid on 23.07.18.
//

#pragma once

/** \brief class for injection to connection server
 *
 */
class ServerConfiguration {
 private:
  unsigned mSocketNumber {65535};
  unsigned mThreadPoolSize {1};

 public:
  ServerConfiguration();
};

