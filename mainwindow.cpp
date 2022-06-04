#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TcpClient_ToPLC = new QTcpSocket;


}

MainWindow::~MainWindow()
{
    delete ui;
   // delete TcpClient_ToPLC;
}





void MainWindow::on_Connect_pushButton_clicked()
{
    PLC_Ip = ui->IP_lineEdit->text();
    PLC_Port = ui->Port_lineEdit->text();

    qDebug() << PLC_Ip << PLC_Port;

    TcpClient_ToPLC->connectToHost(QHostAddress(PLC_Ip),PLC_Port.toShort());
    connect(TcpClient_ToPLC,&QTcpSocket::connected,[this](){
        ui->Connect_pushButton->setText("已连接");
        QMessageBox::information(this,"连接提示","连接成功");
    });
    connect(TcpClient_ToPLC,&QTcpSocket::disconnected,[this](){
        ui->Connect_pushButton->setText("连接失败");
        QMessageBox::warning (this,"连接提示","连接失败");
    });
   // if (TcpClient_ToPLC->connected())



}


void MainWindow::on_DisConnect_pushButton_clicked()
{
    TcpClient_ToPLC->disconnectFromHost();
}

