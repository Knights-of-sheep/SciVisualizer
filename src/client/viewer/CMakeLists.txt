cmake_minimum_required(VERSION 3.15)
project(clientui)

find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)

find_package(GLOG REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(SRC_FILES
    ../resource/resources.qrc
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

include_directories(${GLOG_INC_DIR})
link_directories(${GLOG_LIB_DIR})

add_library(${PROJECT_NAME} SHARED
    ${SRC_FILES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::Core Qt5::Gui)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})





