#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //i->pushButtonConvert->setAutoDefault(false);
    connect(ui->actionSwitch, SIGNAL(triggered()), this, SLOT(switchWidget()));
    connect(ui->actionUse_UTC_time, SIGNAL(triggered(bool)), this, SLOT(setUTC(bool)));
    epochToHuman = new EpochToHuman();
    humanToEpoch = new HumanToEpoch();
    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(humanToEpoch);
    stackedWidget->addWidget(epochToHuman);
    this->setCentralWidget(stackedWidget);
    //So, indexwise: Human to Epoch is standard opening screen
}

void MainWindow::switchWidget(){
#ifdef QT_DEBUG
    qDebug() << "MainWindow::switchWidget() says hello.";
#endif
    if (stackedWidget->currentIndex() == 0){
        stackedWidget->setCurrentIndex(1);
        humanToEpoch->cleanFields();
    } else {
        stackedWidget->setCurrentIndex(0);
        epochToHuman->cleanFields();
    }


}

void MainWindow::setUTC(bool b){
#ifdef QT_DEBUG
    qDebug() << "MainWindow::setUTC(bool b) says hello. The value of b is" << b ;
#endif
    humanToEpoch->useUTC(b);
    epochToHuman->useUTC(b);
}

MainWindow::~MainWindow()
{
    delete ui;
}
