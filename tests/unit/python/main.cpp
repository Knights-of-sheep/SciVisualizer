// 1
// #include <pybind11/embed.h>
// #include <iostream>

// namespace py = pybind11;

// int main() {
//     py::scoped_interpreter guard{}; // 启动Python解释器
    
//     // 测试Python代码执行
//     py::exec("print('Hello from Python!')");
    
//     return 0;
// }

// 2
#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;

int main() {
    py::scoped_interpreter guard{};
    
    // 测试基础Python功能
    py::exec(R"(
        print("1 + 1 =", 1 + 1)
        import sys
        print("Python路径:", sys.path)
    )");

    // 保持终端交互
    std::cout << "\n按Enter键退出...";
    std::cin.get();
    return 0;
}