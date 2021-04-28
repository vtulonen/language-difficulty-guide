#ifndef DIALOGLANG_H
#define DIALOGLANG_H

#include <QDialog>
#include "Languages.h"
#include "languageinfo.h"

namespace Ui {
class DialogLang;
}

class DialogLang : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLang(QWidget *parent = nullptr, QString language = "", Category category = Category::all);
    ~DialogLang();


private:
    Languages languages;
    Ui::DialogLang *ui;
};

#endif // DIALOGLANG_H
