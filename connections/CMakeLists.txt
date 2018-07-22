cmake_minimum_required(VERSION 3.10)
project(eventServer)

add_definitions(-std=c++17)

set(HEADERS )
set(SOURCES )

add_library(libConnections ${SOURCES} ${HEADERS})