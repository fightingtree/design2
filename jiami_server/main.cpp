#include "mainwindow.h"
#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFile qssFile("qt.css");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen()){
        QString qss = QLatin1String(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
    }
    w.show();

    return a.exec();
}
