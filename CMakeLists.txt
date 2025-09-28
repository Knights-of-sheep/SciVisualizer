cmake_minimum_required(VERSION 3.15)
project(scivisualizer)

# 包含环境配置文件
include(cmake/environment.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 启用自动 moc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOMOC_MOC_OPTIONS "-DQT_NO_KEYWORDS")

# 设置全局输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/output/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/output/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/output/lib)

set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_LIST_DIR}/thirdparty)
cmake_policy(SET CMP0144 NEW)
cmake_policy(SET CMP0074 NEW)

# add_subdirectory(src/utils)
add_subdirectory(src/client)
# add_subdirectory(tests/unit/python)
# add_subdirectory(tests/unit/plugins)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()