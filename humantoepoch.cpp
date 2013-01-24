#include "humantoepoch.h"
#include "ui_humantoepoch.h"

HumanToEpoch::HumanToEpoch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HumanToEpoch)
{
    ui->setupUi(this);
    ui->pushButtonConvert->setAutoDefault(false);
    connect(ui->pushButtonConvert,SIGNAL(clicked()),this, SLOT(convert()));
    ui->dateTimeEdit->setMaximumDateTime(QDateTime(QDate(1970,1,1),QTime(0,0,0,0),Qt::TimeSpec(0)));
    ui->dateTimeEdit->setMaximumDateTime(QDateTime(QDate(2106,2,7), QTime(6,28,15,0),Qt::TimeSpec(0)));

    cleanFields();
}

HumanToEpoch::~HumanToEpoch()
{
    delete ui;
}

void HumanToEpoch::cleanFields(){
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTimeUtc());
    ui->labelError->clear();
    ui->lineEditOutput->clear();
}

void HumanToEpoch::convert(){
#ifdef QT_DEBUG
    qDebug() << "HumanToEpoch::convert() says hello.";
#endif
    QDateTime dateTime;
    //dateTime = ui->dateTimeEdit->dateTime();
    dateTime.setTime(ui->dateTimeEdit->time());
    dateTime.setDate( ui->dateTimeEdit->date());
    dateTime.setUtcOffset(0);
#ifdef QT_DEBUG
    qDebug() << "HumantoEpoch::convert() says: datetime: " + dateTime.toString("ddd dd MMMM yyyy, hh:mm:ss");
#endif
    ui->lineEditOutput->setText(QString::number(dateTime.toTime_t()));
}
