#pragma once
#include <QTextEdit>
#include <pybind11/embed.h>

namespace py = pybind11;

class PythonConsole : public QTextEdit {
    Q_OBJECT
public:
    PythonConsole(QWidget* parent = nullptr) : QTextEdit(parent) {
        setReadOnly(false);
        setStyleSheet("font-family: Monospace; font-size: 12pt;");
        
        // 初始化Python解释器
        py::initialize_interpreter();
        
        // 重定向Python输出到QTextEdit
        py::module sys = py::module::import("sys");
        sys.attr("stdout") = this;
        sys.attr("stderr") = this;
        
        // 初始化IPython
        py::exec(R"(
            from IPython import embed
            __ipython = embed  # 保留IPython引用
        )");
    }

    ~PythonConsole() {
        py::finalize_interpreter();
    }

    // 捕获Python输出
    void write(const QString& text) {
        moveCursor(QTextCursor::End);
        insertPlainText(text);
        ensureCursorVisible();
    }

public slots:
    void execute(const QString& code) {
        try {
            py::exec(code.toStdString());
        } catch (py::error_already_set &e) {
            append("Error: " + QString::fromStdString(e.what()));
        }
    }
};