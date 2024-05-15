cmake_minimum_required(VERSION 3.10)
project(DBusClone)

add_subdirectory(Interface)

add_executable(DBusClone main.cpp)

target_link_libraries(DBusClone PUBLIC Interface)

