cmake_minimum_required(VERSION 3.5)
project(simplest_qt_demo)

# 启用 Qt 自动处理功能
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 查找 Qt5
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# 创建可执行文件
add_executable(simplest_qt_demo
    main.cpp
    resources.qrc
)

# 链接 Qt 库
target_link_libraries(simplest_qt_demo Qt5::Widgets)