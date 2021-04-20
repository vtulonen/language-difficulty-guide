#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDesktopServices>
#include <QUrl>
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


void MainWindow::on_pushButton_clicked()
{
    //QStringList sortedAll = languages.all;
    //sortedAll.sort(Qt::CaseInsensitive);
    //QString all = sortedAll.join(',');
    //return all.toStdString() << std::endl;

    std::cout << easiestInfo->getDescription().toStdString() << std::endl;
    std::cout << easiestInfo->getWeeksToLearn() << std::endl;
    std::cout << easiestInfo->getHoursToLearn() << std::endl;

}




