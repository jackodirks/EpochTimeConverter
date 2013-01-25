#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "preCompiled.h"
#include <QMainWindow>
#include <QObject>
#include "Forms.h"
#include <QStackedWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    //Gui related variables
    Ui::MainWindow *ui;
    EpochToHuman * epochToHuman;
    HumanToEpoch * humanToEpoch;
    QStackedWidget * stackedWidget;

private slots:
    void switchWidget();
    void setUTC(bool b);
};

#endif // MAINWINDOW_H
