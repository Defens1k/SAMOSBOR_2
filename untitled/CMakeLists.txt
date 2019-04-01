cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(src)


add_executable(untitled include/message.h
        include/secure_queue.h
        include/connection.h
        src/server.cpp
        src/connection.cpp
        src/secure_queue.cpp)