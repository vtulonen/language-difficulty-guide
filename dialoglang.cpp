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
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint); // remove '?' button

    language_ = language;
    LanguageInfo languageInfo(category);

    // Set language descreption and time to learn the language
    QString description = languageInfo.getDescription();
    if (language_ == "Saksa" || language_ == "German") { //easteregg for 'easy' category
        description += tr(". Yes, this is the only language in this category!");
    }
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

/**
 * @brief DialogLang::createUrl creates an url to effectivelanguagelearning -> language page
 * @param language modifies the url based on this param
 * @return complete url that can be used as a link
 */
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

/**
 * @brief DialogLang::on_buttonOpenBrowser_clicked
 * creates link based on selected language and opens the page in users default browser
 */
void DialogLang::on_buttonOpenBrowser_clicked()
{
    QString url = createUrl(language_);
    QDesktopServices::openUrl(QUrl(url));
}

