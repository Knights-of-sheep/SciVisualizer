cmake_minimum_required(VERSION 3.15)
project(scivisualizer)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

find_package(GLOG REQUIRED)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

include_directories(${GLOG_INC_DIR})
link_directories(${GLOG_LIB_DIR})

add_executable(${PROJECT_NAME}
    main.cpp
    ../resource/resources.qrc
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
    clientui
    glog::glog
    )



