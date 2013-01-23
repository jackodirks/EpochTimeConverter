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
    Ui::HumanToEpoch *ui;
private:

private slots:
    void convert();
};

#endif // HUMANTOEPOCH_H
