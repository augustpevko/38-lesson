cmake_minimum_required(VERSION 3.0.0)
project(3-task VERSION 0.1.0)

set(SOURCES main.cpp blurMainWindow.cpp BlurWindow.ui)
set(HEADERS ${MY_INCLUDE_DIR}/blurMainWindow.h)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/home/pavel/Qt/5.15.2/gcc_64/lib/cmake")

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(3-task ${SOURCES} ${HEADERS})

target_link_libraries(3-task Qt5::Core Qt5::Gui Qt5::Widgets)
target_include_directories(3-task PUBLIC ${MY_INCLUDE_DIR})