#include "mainwindow.h"
#include "ui_mainwindow.h"

/*      Qt5中兼容中文的头文件,Qt已自动兼容 */
//#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//  aboutAct =new QAction(QIcon(":/1.jpg"), tr("&A关于"),this);
   //QAction aboutAct  (QIcon(":/1.jpg"), tr("&A关于"),this);
//    QObject::connect(aboutAct, SIGNAL(triggered()),   this,   SLOT(about()));
//    aboutMenu=menuBar()->addMenu(tr("&关于"));
//     aboutMenu->addAction(aboutAct);
//    aboutMenu=menuBar()->addMenu(tr("&关"));
//    aboutMenu->addAction(aboutAct);
    ui->Sys_Time->setDigitCount(15);
    this->startTimer(1000);



    QToolBar *FileToolbar = addToolBar(tr("文件"));
    FileToolbar->addAction(ui->action_New);
    FileToolbar->addAction(ui->action_Open);
    FileToolbar->addAction(ui->action_Save);
    FileToolbar->addWidget(ui->Sys_Time);


  //  connect(ui->Bt_1,SIGNAL(clicked(bool)),this,SLOT(on_Bt_1_clicked()));

   // QPushButton *Bt_1 = new QPushButton;
  //  connect(Bt_1,   SIGNAL(clicked())   ,this,  SLOT(closed()));
    /*      Qt5中兼容中文的头文件,Qt已自动兼容 */
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));

    this->setWindowTitle("我修改了窗口");
    //this->setCentralWidget(ui->menubar);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::about()
{
   // QMessageBox::about(this, "消息","选择了菜单项");
}
/*//  void MainWindow::on_action_O_triggered()
//  {

//  }

//  void MainWindow::on_action_E_triggered()
//  {

//  }
//  void MainWindow::on_action_S_triggered()
//  {

//  }*/

void MainWindow::on_Bt_1_clicked()

{
    QMessageBox::information(this,"提示","要关闭了");
    this->close();
}
void MainWindow::timerEvent(QTimerEvent *event)
{

    QTime C_time = QTime::currentTime();

    //ui->Sys_Time->setDigitCount(15)
    //ui->Sys_Time->setFrameStyle(QFrame::Shape(QFrame::Box));
    ui->Sys_Time->setFrameStyle(QFrame::Box);
   // ui->Sys_Time->setFrameStyle(QFrame::Panel);
    ui->Sys_Time->setFrameStyle(QFrame::Shape_Mask);

    ui->Sys_Time->setPalette(QPalette(QPalette::Active));
    ui->Sys_Time->display(C_time.toString("HH:mm:ss . zzz"));

}
