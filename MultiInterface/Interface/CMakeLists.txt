cmake_minimum_required(VERSION 3.10)
project(Interface)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Qml DBus Core Gui REQUIRED)

qt6_add_library(Interface SHARED Interface.h Interface.cpp)

target_link_libraries(Interface PUBLIC Qt6::Qml Qt6::DBus Qt6::Core Qt6::Gui)
target_include_directories(Interface PUBLIC ./)
