cmake_minimum_required(VERSION 3.10)
project(eventServer)

add_definitions(-std=c++17)

set(HEADERS DaemonServer.h GlobalFlags.h OptionsHandler.h)
set(SOURCES DaemonServer.cpp GlobalFlags.cpp OptionsHandler.cpp)

add_library(libMain ${SOURCES} ${HEADERS})