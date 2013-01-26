#include "humantoepoch.h"
#include "ui_humantoepoch.h"

HumanToEpoch::HumanToEpoch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HumanToEpoch)
{
    timeSpec = 0;
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

void HumanToEpoch::useUTC(bool b){
    if (b){
        timeSpec = 1;
    } else {
        timeSpec = 0;
    }
    cleanFields();
}

void HumanToEpoch::cleanFields(){
    QDateTime dateTime;
    if(timeSpec == 0){
        dateTime = QDateTime::currentDateTime();
    } else {
        dateTime = QDateTime::currentDateTimeUtc();
    }
    ui->dateTimeEdit->setDateTime(dateTime);
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
    dateTime.setTimeSpec(Qt::TimeSpec(timeSpec));
#ifdef QT_DEBUG
    qDebug() << "HumantoEpoch::convert() says: datetime: " + dateTime.toString("ddd dd MMMM yyyy, hh:mm:ss") + " Timespec is " + QString::number(timeSpec);
#endif
    ui->lineEditOutput->setText(QString::number(dateTime.toTime_t()));
}
