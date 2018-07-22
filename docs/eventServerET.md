# Design document
# Project: **eventServer**

## Assumptions
It’s a server application working under headless mode (deamon). Application accepts direct connection from client and store data in database. Server will be respond on demand and transmit stored data to clients. Setting options will be done by configuration file and loaded on application start.

## Technology
- GNU/Linux
- C++11/14/17 
- STD
- Boost
- Protobuf
- SQLite

Main platform will be GNU/Linux, but major code must be loosle coupled with it.