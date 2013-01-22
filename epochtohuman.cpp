#include "epochtohuman.h"
#include "ui_epochtohuman.h"

EpochToHuman::EpochToHuman(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EpochToHuman)
{
    ui->setupUi(this);

}

EpochToHuman::~EpochToHuman()
{
    delete ui;
}
