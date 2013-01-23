#ifndef EPOCHTOHUMAN_H
#define EPOCHTOHUMAN_H

#include "preCompiled.h"

namespace Ui {
class EpochToHuman;
}

class EpochToHuman : public QWidget
{
    Q_OBJECT
    
public:
    explicit EpochToHuman(QWidget *parent = 0);
    ~EpochToHuman();
    void cleanFields();
    
private:
    Ui::EpochToHuman *ui;

private slots:
    void convert();
    void checkInput( const QString & text);
};

#endif // EPOCHTOHUMAN_H
