#ifndef HUMANTOEPOCH_H
#define HUMANTOEPOCH_H


#include "preCompiled.h"


namespace Ui {
class HumanToEpoch;
}

class HumanToEpoch : public QWidget
{
    Q_OBJECT
    
public:
    explicit HumanToEpoch(QWidget *parent = 0);
    ~HumanToEpoch();
    void cleanFields();
    void useUTC(bool b);
private:
    //private vars
    Ui::HumanToEpoch *ui;
    int timeSpec = 0; //The timespec from Qt::TimeSpec. default 0 (local time) can become 1 (UTC)

private slots:
    void convert();
};

#endif // HUMANTOEPOCH_H
