#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    MainWindow w;
    w.setWindowIcon(QIcon("resources/icon.png")); 
    w.setWindowTitle("Qt Window with Icon");
    w.show();
    return a.exec();
}
