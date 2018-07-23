cmake_minimum_required(VERSION 3.10)
project(eventServer)

add_definitions(-std=c++17)

set(HEADERS ConnectionsServer.h ClientConnection.h)
set(SOURCES ConnectionsServer.cpp ClientConnection.cpp )

add_library(libConnections ${SOURCES} ${HEADERS})