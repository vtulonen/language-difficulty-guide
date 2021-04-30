#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <iostream>
#include <QInputDialog>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /**
     * @brief translator
     * On app startup a input dialog is show and user prompted to choose language
     * based on user choise, the translator is either installed or not
     * if user quits here, the app wont start at all
     */
    QTranslator translator;

    QStringList languages;
    languages << "English" << "Suomi";
    bool ok;
    QString language = QInputDialog::getItem(NULL, "Choose Language", "Language", languages, 0, 1, &ok);

    if (ok) {
        if (language == "Suomi")  translator.load("harjoitustyo_fi_FI");
        if ( language != "English")
        {
            a.installTranslator(&translator);
        }

        MainWindow w;
        w.show();
        return a.exec();
    }
    //Else
    return 0;
}
