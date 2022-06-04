#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QString>
#include <QDebug>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     QString PLC_Ip,PLC_Port;          //声明Ip和端口变量

private slots:

    // void on_Connect_pushButton_clicked(bool checked);

     void on_Connect_pushButton_clicked();

     void on_DisConnect_pushButton_clicked();

private:
   Ui::MainWindow *ui;
   QTcpSocket *TcpClient_ToPLC;     //创建客户端

};
#endif // MAINWINDOW_H
