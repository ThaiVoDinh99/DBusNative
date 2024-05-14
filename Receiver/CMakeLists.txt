cmake_minimum_required(VERSION 3.16)
project(DBusReceiver)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Quick Core DBus Qml REQUIRED)

qt6_add_qml_module(UI
    URI UI
    VERSION 1.0
    QML_FILES main.qml
    NO_PLUGIN
)

qt6_add_executable(DBusReceiver main.cpp Receiver.h Receiver.cpp)

target_link_libraries(DBusReceiver PRIVATE Qt6::Quick Qt6::Core Qt6::DBus Qt6::Qml UI)



