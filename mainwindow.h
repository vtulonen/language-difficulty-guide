#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Languages.h"
#include "languageinfo.h"
#include <QPushButton>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QCloseEvent>
#include <QRandomGenerator>
#include <QLocale>

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
    void on_listWidgetLanguages_itemClicked(QListWidgetItem *item);
    void on_btn_random_clicked();

private:
    Ui::MainWindow *ui;
    Languages languages_;
    Category findCategoryOf(QString language);
    QPushButton *filterBtns[6];
    QRandomGenerator *randomGenerator_ = QRandomGenerator::system();
    void closeEvent(QCloseEvent *event);
    QString locale_ = QLocale::system().name();

};
#endif // MAINWINDOW_H
