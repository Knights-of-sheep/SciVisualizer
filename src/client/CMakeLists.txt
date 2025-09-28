cmake_minimum_required(VERSION 3.15)
project(client)

include_directories(${SOURCE_DIR})
include_directories(${GLOG_INC_DIR})
include_directories(${THIRD_PARTY_DIR})

add_subdirectory(viewer)
add_subdirectory(app)


