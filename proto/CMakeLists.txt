cmake_minimum_required(VERSION 3.10)
project(eventServer)

add_definitions(-std=c++17)

set(HEADERS messages.pb.h)
set(SOURCES messages.pb.cc)

add_library(libProto ${SOURCES} ${HEADERS})