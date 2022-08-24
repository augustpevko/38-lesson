cmake_minimum_required(VERSION 3.0.0)
project(2-task VERSION 0.1.0)

set(SOURCES main.cpp htmlEditorMainWindow.cpp htmlEditor.ui)
set(HEADERS ${MY_INCLUDE_DIR}/htmlEditorMainWindow.h)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/home/pavel/Qt/6.3.1/gcc_64/lib/cmake/")

find_package(Qt6 COMPONENTS Core Gui Widgets WebEngineWidgets REQUIRED)

add_executable(2-task ${SOURCES} ${HEADERS})

target_link_libraries(2-task Qt6::Core Qt6::Widgets Qt6::WebEngineCore Qt6::WebEngineWidgets)
target_include_directories(2-task PUBLIC ${MY_INCLUDE_DIR})