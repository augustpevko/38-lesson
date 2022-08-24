cmake_minimum_required(VERSION 3.0.0)
project(1-task VERSION 0.1.0)

set(SOURCES main.cpp button.cpp)
set(HEADERS ${MY_INCLUDE_DIR}/button.h)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_PREFIX_PATH "/home/pavel/Qt/5.15.2/gcc_64/lib/cmake")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets Multimedia MultimediaWidgets REQUIRED)
qt5_wrap_cpp (MOC_SOURCES ${HEADERS})

add_executable(1-task ${SOURCES} ${MOC_SOURCES})

target_link_libraries(1-task Qt5::Core Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)
target_include_directories(1-task PUBLIC ${MY_INCLUDE_DIR})