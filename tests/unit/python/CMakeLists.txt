cmake_minimum_required(VERSION 3.16)
project(Pybind11Test)

# 强制使用C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置Python路径（使用绝对路径）
set(PYTHON_HOME "/home/guojifang/toolchain/python/python3.11.9-install")
set(PYTHON_INCLUDE_DIR "${PYTHON_HOME}/include/python3.11")
set(PYBIND11_INCLUDE_DIR "${PYTHON_HOME}/lib/python3.11/site-packages/pybind11/include")

# 手动指定包含路径（避免自动拼接错误）
include_directories(
    "${PYTHON_INCLUDE_DIR}"
    "${PYBIND11_INCLUDE_DIR}"
)

# 获取Python链接参数并分割为列表，避免空白问题
execute_process(
    COMMAND ${PYTHON_HOME}/bin/python3.11-config --ldflags
    OUTPUT_VARIABLE PYTHON_LDFLAGS_RAW
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
separate_arguments(PYTHON_LDFLAGS NATIVE_COMMAND "${PYTHON_LDFLAGS_RAW}")

# 添加可执行文件
add_executable(pybind11_test main.cpp)

# 链接库
target_link_libraries(pybind11_test PRIVATE
    ${PYTHON_LDFLAGS}
    "${PYTHON_HOME}/lib/libpython3.11.so"
)

# 确保运行时能找到Python库
set_target_properties(pybind11_test PROPERTIES
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH "${PYTHON_HOME}/lib"
)