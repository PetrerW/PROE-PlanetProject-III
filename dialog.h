#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "List.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    int index=0;
    explicit Dialog(QWidget *parent = 0);
    Dialog(QString Title, QString i_path, List<Planet> *Lptr, QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_nextButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::Dialog *ui;
    List<Planet> *LD;
};

#endif // DIALOG_H
