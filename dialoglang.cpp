#include "dialoglang.h"
#include "ui_dialoglang.h"
#include <iostream>

DialogLang::DialogLang(QWidget *parent, QString language, Category category, bool random) :
    QDialog(parent),
    ui(new Ui::DialogLang)
{

    ui->setupUi(this);
    QString titleText = language;
    if (random) titleText.prepend(tr("Randomly Picked Language For You: "));
    this->setWindowTitle(titleText);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    language_ = language;
    LanguageInfo languageInfo(category);
    QString description = languageInfo.getDescription();
    description.prepend(language + " ");
    QString weeks = QString::number(languageInfo.getWeeksToLearn());
    QString hours = QString::number(languageInfo.getHoursToLearn());
    QString labelTimeToLearn = tr("Time to learn the language is approximately: ");
    labelTimeToLearn += hours + tr(" hours over ");
    labelTimeToLearn += weeks + tr(" weeks.");
    ui->labelDescription->setText(description);
    ui->labelTimeToLearn->setText(labelTimeToLearn);
    ui->buttonOpenBrowser->setToolTip(createUrl(language_));
    ui->buttonBox->button(QDialogButtonBox::Close)->setText(tr("Close"));
}

DialogLang::~DialogLang()
{
    delete ui;
}

QString DialogLang::createUrl(QString language)
{
    int index = languages_.all.indexOf(language);
    language = languagesNoTr_.all[index];

    language = language.toLower();
    QString baseUrl = "https://effectivelanguagelearning.com/language-guide/";
    QString basePostfix = "-language/";

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

