#include "alreadythere.h"
#include "ui_alreadythere.h"

AlreadyThere::AlreadyThere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlreadyThere)
{
    ui->setupUi(this);
}

AlreadyThere::~AlreadyThere()
{
    delete ui;
}
