#include "mainwindow.h"

#include <glog/logging.h>

#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/icon.png"));

    if (windowIcon().isNull()) {
        LOG(ERROR) << "Error: Failed to load window icon!" << std::endl;
    } else {
        LOG(INFO) << "Window icon loaded successfully!" << std::endl;
    }
    setWindowIcon(QIcon(":/images/logo2.png"));  // 设置窗口图标

    QLabel* icon2 = new QLabel(this);
    QString png2 = ":/images/logo.png";
    QPixmap pix2(png2);
    pix2 = pix2.scaled(icon2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    icon2->setPixmap(pix2);
    icon2->setStyleSheet("background-color: transparent");
    ui->menubar->setCornerWidget(icon2, Qt::TopLeftCorner);
}

MainWindow::~MainWindow() { delete ui; }