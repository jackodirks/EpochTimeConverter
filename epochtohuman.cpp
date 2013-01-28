#include <QDateTime>
#include "epochtohuman.h"
#include "ui_epochtohuman.h"


EpochToHuman::EpochToHuman(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EpochToHuman)
{
    timeSpec = 0;
    ui->setupUi(this);
    ui->pushButtonConvert->setAutoDefault(false);
    connect(ui->pushButtonConvert,SIGNAL(clicked()),this,SLOT(convert()));
    connect(ui->lineEditInput,SIGNAL(textEdited(QString)),this,SLOT(checkInput(QString)));
}

EpochToHuman::~EpochToHuman()
{
    delete ui;
}

void EpochToHuman::useUTC(bool b){
    if (b){
        timeSpec = 1;
    } else {
        timeSpec = 0;
    }
    cleanFields();
}

void EpochToHuman::cleanFields(){
    ui->labelErrorOutput->clear();
    ui->lineEditInput->clear();
    ui->lineEditOutput->clear();
}

void EpochToHuman::convert(){
#ifdef QT_DEBUG
    qDebug() << "EpochToHuman::convert() says hello.";
#endif
    if(ui->lineEditInput->text().length() == 0){
        ui->labelErrorOutput->setText("<font color='red'>The input field is empty</font>");
        return;
    }
    bool ok;
    uint epochTime = ui->lineEditInput->text().toUInt(&ok);
#ifdef QT_DEBUG
    qDebug() << "EpochToHuman::convert() says epochtime = " + QString::number(epochTime) + ".\nThe boolean ok contains: " + (ok?"TRUE":"FALSE");
#endif
    if (!ok){
        ui->labelErrorOutput->setText("<font color='red'>Could not convert input to uint</font>");
        return;
    }
    QDateTime humanDateTime;
    humanDateTime.setTimeSpec(Qt::TimeSpec(timeSpec)); //0 is local, 1 is UTC, 2 is offset from UTC
    humanDateTime.setTime_t(epochTime);
    ui->lineEditOutput->setText(humanDateTime.toString("ddd dd MMMM yyyy, hh:mm:ss"));
}

void EpochToHuman::checkInput(const QString &text){
#ifdef QT_DEBUG
    qDebug() << "EpochToHuman::checkInput(const QString &text) says hello";
#endif
   bool ok;
   text.toUInt(&ok);
   if (!ok && text.length()>0){
    QString newText;
    ui->labelErrorOutput->setText("<font color='red'>Only numbers are alowed in this input</font>");
    for (int i = 0; i < text.length(); i++){
        if (text.at(i).digitValue() != -1){
            newText.append(text.at(i));
        }
    }
    ui->lineEditInput->setText(newText);
   }
}
