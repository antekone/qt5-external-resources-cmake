cmake_minimum_required(VERSION 3.2)
project(helloworld)

find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5Widgets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Absolute path to Qt5ExternalResources.cmake
include(${CMAKE_SOURCE_DIR}/../../Qt5ExternalResources.cmake)

# Generate `resources.rcc` from `resources.qrc`.
qt5_add_external_resources(resources.rcc resources.qrc)
qt5_add_external_resources(resources-small.rcc resources-small.qrc)

add_executable(helloworld helloworld.cc)
qt5_use_modules(helloworld Core Gui Widgets)
