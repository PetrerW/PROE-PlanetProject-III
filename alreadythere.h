#ifndef ALREADYTHERE_H
#define ALREADYTHERE_H

#include <QDialog>

namespace Ui {
class AlreadyThere;
}

class AlreadyThere : public QDialog
{
    Q_OBJECT

public:
    explicit AlreadyThere(QWidget *parent = 0);
    ~AlreadyThere();

private:
    Ui::AlreadyThere *ui;
};

#endif // ALREADYTHERE_H
