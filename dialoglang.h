#ifndef DIALOGLANG_H
#define DIALOGLANG_H

#include <QDialog>
#include "Languages.h"
#include "languageinfo.h"
#include <QUrl>
#include <QDesktopServices>

/**
 *
 * This dialog handles displaying specific data about a language
 *
 */


namespace Ui {
class DialogLang;
}

class DialogLang : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLang(QWidget *parent = nullptr, QString language = "", Category category = Category::all, bool random = false);
    ~DialogLang();


private slots:
    void on_buttonOpenBrowser_clicked();

private:
    Languages languages_;
    LanguagesNoTr languagesNoTr_;
    QString language_;
    QString createUrl(QString language);
    Ui::DialogLang *ui;
};

#endif // DIALOGLANG_H
