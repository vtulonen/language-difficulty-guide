#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Languages.h"
#include "languageinfo.h"
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void filterBtnPressed(int mapping);
    void display_languages(QStringList languageList);

private:
    Ui::MainWindow *ui;
    Languages languages;
    LanguageInfo *easiestInfo = new LanguageInfo(Category::easiest);
    LanguageInfo *easyInfo = new LanguageInfo(Category::easy);
    LanguageInfo *mediumInfo = new LanguageInfo(Category::medium);
    LanguageInfo *hardInfo = new LanguageInfo(Category::hard);
    LanguageInfo *hardestInfo = new LanguageInfo(Category::hardest);
    QPushButton *filterBtns[6];
};
#endif // MAINWINDOW_H
