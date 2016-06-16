#include "endoflistinfo.h"

EndOfListInfo::EndOfListInfo(QWidget *parent) :
    QDialog(parent),
    ui( new Ui::EndOfListInfo)
{

    ui->setupUi(this);
}

EndOfListInfo::~EndOfListInfo()
{
    delete ui;
}
