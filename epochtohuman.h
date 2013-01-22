#ifndef EPOCHTOHUMAN_H
#define EPOCHTOHUMAN_H

#include <QWidget>

namespace Ui {
class EpochToHuman;
}

class EpochToHuman : public QWidget
{
    Q_OBJECT
    
public:
    explicit EpochToHuman(QWidget *parent = 0);
    ~EpochToHuman();
    
private:
    Ui::EpochToHuman *ui;
};

#endif // EPOCHTOHUMAN_H
