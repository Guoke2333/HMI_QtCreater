#include "mainwindow.h"
#include "ui_mainwindow.h"

/*      Qt5中兼容中文的头文件,Qt已自动兼容 */
//#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}




