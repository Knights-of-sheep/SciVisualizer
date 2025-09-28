cmake_minimum_required(VERSION 3.15)
project(Desktop)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/client/ui ${CMAKE_BINARY_DIR}/src/client/ui)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
    clientui
)



