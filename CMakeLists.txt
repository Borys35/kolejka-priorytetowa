cmake_minimum_required(VERSION 3.28)
project(priority_queue_impl)

set(CMAKE_CXX_STANDARD 20)

add_executable(priority_queue_impl main.cpp
        PriorityQueueBase.hpp
        Menu.cpp
        Menu.h
        TestGenerator.cpp
        TestGenerator.hpp
        Utility.hpp)
