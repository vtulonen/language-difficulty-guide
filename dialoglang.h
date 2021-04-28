#ifndef DIALOGLANG_H
#define DIALOGLANG_H

#include <QDialog>
#include "Languages.h"
#include "languageinfo.h"
#include <QUrl>
#include <QDesktopServices>

namespace Ui {
class DialogLang;
}

class DialogLang : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLang(QWidget *parent = nullptr, QString language = "", Category category = Category::all);
    ~DialogLang();


private slots:


    void on_buttonOpenBrowser_clicked();



private:
    Languages languages;
    QString language_;
    QString createUrl(QString language);
    Ui::DialogLang *ui;
};

#endif // DIALOGLANG_H
