cmake_minimum_required(VERSION 3.1)

project(game)

include_directories(.)
include_directories(include)
include_directories(src)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")


add_executable(
        ./include/message.h
        ./include/secure_queue.h
        ./include/connection.h
        ./src/server.cpp
        ./src/secure_queue.cpp
        ./src/connection.cpp)
