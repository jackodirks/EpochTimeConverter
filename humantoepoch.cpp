#include "humantoepoch.h"
#include "ui_humantoepoch.h"

HumanToEpoch::HumanToEpoch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HumanToEpoch)
{
    ui->setupUi(this);
    ui->pushButtonConvert->setAutoDefault(false);
    connect(ui->pushButtonConvert,SIGNAL(clicked()),this, SLOT(convert()));
}

HumanToEpoch::~HumanToEpoch()
{
    delete ui;
}

void HumanToEpoch::convert(){
#ifdef QT_DEBUG
    qDebug() << "HumanToEpoch::convert() says hello.";
#endif
}
