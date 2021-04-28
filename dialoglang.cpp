#include "dialoglang.h"
#include "ui_dialoglang.h"
#include <iostream>

DialogLang::DialogLang(QWidget *parent, QString language, Category category) :
    QDialog(parent),
    ui(new Ui::DialogLang)
{

    ui->setupUi(this);
    this->setWindowTitle(language);


    language_ = language;
    LanguageInfo languageInfo(category);
    QString description = languageInfo.getDescription();
    description.prepend(language + " ");
    QString weeks = QString::number(languageInfo.getWeeksToLearn());
    QString hours = QString::number(languageInfo.getHoursToLearn());
    QString labelTimeToLearn = "Time to learn the language is approximately: ";
    labelTimeToLearn += hours + " hours over ";
    labelTimeToLearn += weeks + " weeks.";
    ui->labelDescription->setText(description);
    ui->labelTimeToLearn->setText(labelTimeToLearn);


    ui->buttonOpenBrowser->setToolTip(createUrl(language_));
}

DialogLang::~DialogLang()
{
    delete ui;
}

QString DialogLang::createUrl(QString language)
{
    language = language.toLower();
    QString baseUrl = "https://effectivelanguagelearning.com/language-guide/";
    QString basePostfix = "-language/";
    std::cout << (baseUrl + language + basePostfix).toStdString() << std::endl;

    if (language == "french" || language == "italian" || language == "spanish" || language == "german") {
        return baseUrl + language;
    }
    else if (language == "cantonese" || language == "mandarin") {
        return baseUrl + language + "-chinese" + basePostfix;
    }

    return baseUrl + language + basePostfix;
}

void DialogLang::on_buttonOpenBrowser_clicked()
{
    QString url = createUrl(language_);
    QDesktopServices::openUrl(QUrl(url));
}

