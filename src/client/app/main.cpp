#include <glog/logging.h>
#include <sys/stat.h>

#include <QApplication>
#include <QFont>
#include <QFontDatabase>
#include <QIcon>

#include "client/viewer/mainwindow.h"
void initLogger(const std::string& logDir, const std::string& appName, bool logToStderr, int maxLogSizeMB,
                int maxLogFiles) {
    // 创建日志目录
    mkdir(logDir.c_str(), 0777);

    // 初始化 Glog
    google::InitGoogleLogging(appName.c_str());
    google::SetLogDestination(google::INFO, (logDir + "/INFO_").c_str());
    google::SetLogDestination(google::WARNING, (logDir + "/WARNING_").c_str());
    google::SetLogDestination(google::ERROR, (logDir + "/ERROR_").c_str());
    google::SetLogDestination(google::FATAL, (logDir + "/FATAL_").c_str());

    // 控制台输出开关
    FLAGS_logtostderr = logToStderr;
    FLAGS_alsologtostderr = true;

    // 文件日志配置
    FLAGS_max_log_size = maxLogSizeMB;  // 单个文件大小（MB）
    FLAGS_logbuflevel = -1;             // 立即刷新日志到文件
    FLAGS_stop_logging_if_full_disk = true;
    LOG(INFO) << "Logger initialized. Logs saved to: " << logDir;
    LOG(ERROR) << "Logger initialized. Logs saved to: " << logDir;
    LOG(WARNING) << "Logger initialized. Logs saved to: " << logDir;
    google::FlushLogFiles(google::INFO);  // 立即刷新日志
}

void deinitLogger() { google::ShutdownGoogleLogging(); }

void initFont(QApplication& app) {
    QFontDatabase::addApplicationFont(":/fonts/Roboto-Regular.ttf");
    int fontId = QFontDatabase::addApplicationFont(":/fonts/Roboto-Regular.ttf");
    if (fontId == -1) {
        LOG(ERROR) << "Failed to load font: Roboto-Regular.ttf" << std::endl;
    } else {
        LOG(INFO) << "Loaded font: Roboto-Regular.ttf" << std::endl;
    }

    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);

    QFont defaultFont(fontFamily, 11);
    app.setFont(defaultFont);
}

int main(int argc, char* argv[]) {
    initLogger("./logs", "SciVisualizer", false, 10, 5);
    QApplication app(argc, argv);
    initFont(app);
    MainWindow window;
    window.showMaximized();
    int ret = app.exec();
    deinitLogger();
    return ret;
}