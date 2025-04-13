#include "mainwindow.h"
#include <QApplication>
#include <QIcon>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon appIcon(":/resources/icon.png");
    if (appIcon.isNull()) {
        qDebug() << "Failed to load application icon!";
    } else {
        qDebug() << "Application icon loaded successfully.";
    }
    a.setWindowIcon(appIcon);

    MainWindow w;
    QIcon windowIcon(":/resources/icon.png");
    if (windowIcon.isNull()) {
        qDebug() << "Failed to load window icon!";
    } else {
        qDebug() << "Window icon loaded successfully.";
    }
    w.setWindowIcon(windowIcon);
    w.setWindowTitle("Qt Window with Icon");
    w.show();
    return a.exec();
}