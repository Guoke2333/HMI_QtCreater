#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QTime>
#include <QToolBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   // void Bt_1_Clicked();
//    void on_action_E_triggered();
//    void on_action_S_triggered();
//    void on_action_O_triggered();
    void about();
    void timerEvent(QTimerEvent *event);
    void on_Bt_1_clicked();

private:
   Ui::MainWindow *ui;
//   QMenu *aboutMenu;
//   QAction *aboutAct;
   //QToolBar *FileToolbar;
};
#endif // MAINWINDOW_H
