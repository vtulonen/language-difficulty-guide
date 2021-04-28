#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDesktopServices>
#include <QUrl>
#include <QSignalMapper>
#include "dialoglang.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    display_languages(languages.all);
    filterBtns[0] = ui->btn_filter_all;
    filterBtns[1] = ui->btn_filter_easiest;
    filterBtns[2] = ui->btn_filter_easy;
    filterBtns[3] = ui->btn_filter_medium;
    filterBtns[4] = ui->btn_filter_hard;
    filterBtns[5] = ui->btn_filter_hardest;

    QSignalMapper *signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(filterBtnPressed(int)));
    for(int i = 0; i < 6; i++){
        signalMapper->setMapping(filterBtns[i], i);
        connect(filterBtns[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::filterBtnPressed(int mapping)
{
    ui->listWidgetLanguages->clear();

    switch (mapping)
    {
    case 0: display_languages(languages.all); break;
    case 1: display_languages(languages.easiest); break;
    case 2: display_languages(languages.easy); break;
    case 3: display_languages(languages.medium); break;
    case 4: display_languages(languages.hard); break;
    case 5: display_languages(languages.hardest); break;

    default: display_languages(languages.all);
    }
}

void MainWindow::display_languages(QStringList languageList)
{
    for (int i=0; i<languageList.size(); i++) {
        ui->listWidgetLanguages->addItem(languageList[i]);
    }
}





void MainWindow::on_listWidgetLanguages_itemClicked(QListWidgetItem *item)
{

    QString selectedLang = item->text();

    DialogLang dialog(this, selectedLang, findCategoryOf(selectedLang));
    dialog.setModal(true);

    if (dialog.exec()) {
       std::cout << item->text().toStdString() << std::endl;
    }
}

Category MainWindow::findCategoryOf(QString language)
{
    if
            (languages.easiest.contains(language, Qt::CaseInsensitive)) return Category::easiest;
    else if
            (languages.easy.contains(language, Qt::CaseInsensitive)) return Category::easy;
    else if
            (languages.medium.contains(language, Qt::CaseInsensitive)) return Category::medium;
    else if
            (languages.hard.contains(language, Qt::CaseInsensitive)) return Category::hard;
    else if
            (languages.hardest.contains(language, Qt::CaseInsensitive)) return Category::hardest;


}

