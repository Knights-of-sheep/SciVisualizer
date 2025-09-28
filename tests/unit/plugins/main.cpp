#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QMainWindow>
#include <QIcon>
#include <QHBoxLayout>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // 创建主窗口
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Image Viewer");
    
    // 设置窗口图标（这会显示在标题栏左上角）
    mainWindow.setWindowIcon(QIcon(":/images/demo.png"));
    
    // 创建中央部件和布局
    QWidget *centralWidget = new QWidget(&mainWindow);
    QHBoxLayout *layout = new QHBoxLayout(centralWidget);
    
    // 在左上角添加图标（客户区内的图标）
    QLabel *cornerIcon = new QLabel(centralWidget);
    QPixmap cornerPixmap(":/images/demo.png"); // 使用和窗口图标相同的图片或不同的
    if(!cornerPixmap.isNull()) {
        cornerIcon->setPixmap(cornerPixmap.scaled(32, 32, Qt::KeepAspectRatio)); // 缩放图标大小
    }
    layout->addWidget(cornerIcon, 0, Qt::AlignLeft | Qt::AlignTop); // 左上角对齐
    
    // 添加主图片标签
    QLabel *mainImageLabel = new QLabel(centralWidget);
    // QPixmap mainPixmap(":/images/demo.png");
    // if(mainPixmap.isNull()) {
        mainImageLabel->setText("Failed to load image!");
    // } else {
    //     mainImageLabel->setPixmap(mainPixmap);
    // }
    mainImageLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(mainImageLabel, 1); // 占据剩余空间
    
    // 设置中央部件
    mainWindow.setCentralWidget(centralWidget);
    
    // 显示主窗口
    mainWindow.resize(800, 600); // 设置初始窗口大小
    mainWindow.show();
    
    return app.exec();
}