#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Forms.h"
#ifdef QT_DEBUG
#include <QDebug>
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //i->pushButtonConvert->setAutoDefault(false);
    //connect(ui->pushButtonConvert,SIGNAL(clicked()), this,SLOT(convert()));
    //Form * test = new Form();
    //this->setCentralWidget(test);
    EpochToHuman * epochToHuman = new EpochToHuman();
    HumanToEpoch * humanToEpoch = new HumanToEpoch();
    humanToEpoch->ui->label->setText("Test");
}
void MainWindow::convertFromEpochToHuman(){
#ifdef QT_DEBUG
    qDebug() << "convertFromEpochToHuman says hello.";
#endif
}

void MainWindow::convertFromHumanToEpoch(){
#ifdef QT_DEBUG
    qDebug << "convertFromHumanToEpoch says hello";
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}
