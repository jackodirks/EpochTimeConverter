#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //i->pushButtonConvert->setAutoDefault(false);
    connect(ui->actionSwitch, SIGNAL(triggered()), this, SLOT(switchWidget()));
    EpochToHuman * epochToHuman = new EpochToHuman();
    HumanToEpoch *  humanToEpoch = new HumanToEpoch();
    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(humanToEpoch);
    stackedWidget->addWidget(epochToHuman);
    this->setCentralWidget(stackedWidget);
    //So, indexwise: Human to Epoch is standard opening screen
}

void MainWindow::switchWidget(){
#ifdef QT_DEBUG
    qDebug() << "switchWidget says hello.";
#endif
    if (stackedWidget->currentIndex() == 0){
        stackedWidget->setCurrentIndex(1);
    } else {
        stackedWidget->setCurrentIndex(0);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
