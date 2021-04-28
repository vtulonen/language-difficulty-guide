#include "dialoglang.h"
#include "ui_dialoglang.h"


DialogLang::DialogLang(QWidget *parent, QString language, Category category) :
    QDialog(parent),
    ui(new Ui::DialogLang)
{

    ui->setupUi(this);
    this->setWindowTitle(language);

    LanguageInfo languageInfo(category);
    QString description = languageInfo.getDescription();
    QString weeks = QString::number(languageInfo.getWeeksToLearn());
    QString hours = QString::number(languageInfo.getHoursToLearn());
    QString labelTimeToLearn = "Time to learn the language is approximately: ";
    labelTimeToLearn += hours + " hours over ";
    labelTimeToLearn += weeks + " weeks.";
    ui->labelDescription->setText(description);
    ui->labelTimeToLearn->setText(labelTimeToLearn);



}

DialogLang::~DialogLang()
{
    delete ui;
}
