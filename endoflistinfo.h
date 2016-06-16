#ifndef ENDOFLISTINFO_H
#define ENDOFLISTINFO_H

#include <QDialog>

namespace Ui {
class EndOfListInfo;
}

class EndOfListInfo : public QDialog
{
    Q_OBJECT

public:
    explicit EndOfListInfo(QWidget *parent = 0);
    ~EndOfListInfo();

private:
    Ui::EndOfListInfo *ui;
};

#endif // ENDOFLISTINFO_H
