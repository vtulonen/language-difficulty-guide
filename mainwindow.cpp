#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDesktopServices>
#include <QUrl>
#include <QSignalMapper>
#include "dialoglang.h"
#include <QWindow>
#include <QIcon>
#include <QAction>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIcon icon(":/icons/window_icon.ico");
    setWindowIcon(icon);
    setWindowTitle(tr("Language Difficulties"));

    display_languages( languages_.all);
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
    case 0: display_languages(languages_.all); break;
    case 1: display_languages(languages_.easiest); break;
    case 2: display_languages(languages_.easy); break;
    case 3: display_languages(languages_.medium); break;
    case 4: display_languages(languages_.hard); break;
    case 5: display_languages(languages_.hardest); break;

    default: display_languages(languages_.all);
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
    dialog.exec();

}

Category MainWindow::findCategoryOf(QString language)
{
    if
            ( languages_.easiest.contains(language, Qt::CaseInsensitive)) return Category::easiest;
    else if
            ( languages_.easy.contains(language, Qt::CaseInsensitive)) return Category::easy;
    else if
            ( languages_.medium.contains(language, Qt::CaseInsensitive)) return Category::medium;
    else if
            ( languages_.hard.contains(language, Qt::CaseInsensitive)) return Category::hard;
    else if
            ( languages_.hardest.contains(language, Qt::CaseInsensitive)) return Category::hardest;
        else return Category::all;

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();

    QMessageBox messageBox(QMessageBox::Question,
                tr("Closing Appliaction"),
                tr("Are you sure you want to Exit?"),
                QMessageBox::Yes | QMessageBox::No,
                this);
        messageBox.setButtonText(QMessageBox::Yes, tr("Yes"));
        messageBox.setButtonText(QMessageBox::No, tr("No"));

    if (messageBox.exec() == QMessageBox::Yes) {
        event->accept();
    }

}

void MainWindow::on_btn_random_clicked()
{
    QListWidget *list = ui->listWidgetLanguages;
    int randomNum = randomGenerator_->bounded(list->count());
    QString randomLanguage = list->item(randomNum)->text();

    DialogLang dialog(this, randomLanguage, findCategoryOf(randomLanguage), true);
    dialog.setModal(true);
    dialog.exec();

}
