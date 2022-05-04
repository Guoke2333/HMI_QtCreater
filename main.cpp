#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "HMI_QtCreater-20220415_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    QToolBar *mytoolbar;
    mytoolbar = new QToolBar;
    QAction *CloseAc;
    CloseAc = new QAction;
    mytoolbar->setWindowFlags(Qt::FramelessWindowHint);
    mytoolbar->addAction(CloseAc);
    mytoolbar->show();
    w.show();
    QObject::connect(CloseAc,SIGNAL(clicked()),mytoolbar,SLOT(closed()));
    return a.exec();
}
