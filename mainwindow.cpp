#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnOk, SIGNAL(clicked()),this,SLOT(on_btnOk_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOk_clicked()
{
    qDebug() << "Ok button clicked";
    QMessageBox::information(this, "Information", "Hello World usingQt!");
}

