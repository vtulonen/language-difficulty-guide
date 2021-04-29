#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QTranslator translator;

    if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Translation", "Would you like to translate the app into Finnish?", QMessageBox::Yes|QMessageBox::No).exec())
    {
        translator.load("harjoitustyo_fi_FI");
        a.installTranslator(&translator);
    }


    MainWindow w;
    w.show();
    return a.exec();
}
