#ifndef EPOCHTOHUMAN_H
#define EPOCHTOHUMAN_H

#include "preCompiled.h"
#include <QKeyEvent>

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
    void useUTC(bool b);
    
private:
    Ui::EpochToHuman *ui;
    //private vars
    int timeSpec; //The timespec from Qt::TimeSpec. default 0 (local time) can become 1 (UTC)
    void keyPressEvent(QKeyEvent *);

private slots:
    void convert();
    void checkInput( const QString & text);
};

#endif // EPOCHTOHUMAN_H
