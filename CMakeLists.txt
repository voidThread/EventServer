cmake_minimum_required(VERSION 3.10)
project(eventServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lboost_system -lboost_thread -pthread")

find_package(Boost 1.65.1 COMPONENTS system thread program_options REQUIRED)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(SOURCE_FILES main.cpp)

add_subdirectory(main)
add_subdirectory(proto)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    message("Boost include dir: " ${Boost_INCLUDE_DIRS})
    add_executable(eventServer ${SOURCE_FILES})

    target_link_libraries(eventServer ${Boost_LIBRARIES})
    target_link_libraries(eventServer libMain)
    target_link_libraries(eventServer libProto)
    target_link_libraries(eventServer libConnections)
    target_link_libraries(eventServer libDB)

endif()