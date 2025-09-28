#!/bin/bash

# 创建根目录
cd /home/guojifang/project/scivisualizer

# 创建一级目录
mkdir -p build docs include libs resources scripts src apps external tests

# 创建docs子目录
mkdir -p docs/architecture docs/api/cpp docs/api/python

# 创建include子目录
mkdir -p include/Core include/Server include/Python

# 创建resources子目录
mkdir -p resources/icons resources/shaders resources/templates

# 创建scripts子目录
mkdir -p scripts/build scripts/tools

# 创建src子目录结构
mkdir -p src/core/data src/core/algorithms src/core/rendering
mkdir -p src/server/api/Native src/server/api/Remote src/server/internal src/server/lib
mkdir -p src/python/bindings/core src/python/bindings/server src/python/wrappers
mkdir -p src/client/app/PythonEngine src/client/ui/ScriptConsole
mkdir -p src/common/utils src/common/protocols

# 创建apps子目录
mkdir -p apps/server apps/desktop apps/cli

# 创建external子目录
mkdir -p external/pybind11 external/protobuf external/cmake

# 创建tests子目录
mkdir -p tests/unit/{core,server,python}
mkdir -p tests/integration/{client_server,python_binding}
mkdir -p tests/performance/{core_benchmark,network_benchmark}
