#include "humantoepoch.h"
#include "ui_humantoepoch.h"

HumanToEpoch::HumanToEpoch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HumanToEpoch)
{
    ui->setupUi(this);
}

HumanToEpoch::~HumanToEpoch()
{
    delete ui;
}
