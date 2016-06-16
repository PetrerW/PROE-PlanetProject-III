#ifndef ENDLISTBOX_H
#define ENDLISTBOX_H

#include <QDialog>

namespace Ui {
class EndListBox;
}

class EndListBox : public QDialog
{
    Q_OBJECT

public:
    explicit EndListBox(QWidget *parent = 0);
    ~EndListBox();

private:
    Ui::EndListBox *ui;
};

#endif // ENDLISTBOX_H
