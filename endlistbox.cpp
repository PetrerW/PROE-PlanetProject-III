#include "endlistbox.h"
#include "ui_endlistbox.h"

EndListBox::EndListBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndListBox)
{
    ui->setupUi(this);
}

EndListBox::~EndListBox()
{
    delete ui;
}
