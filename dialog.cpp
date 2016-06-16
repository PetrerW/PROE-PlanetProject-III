#include "dialog.h"
#include "ui_dialog.h"
#include <QPixmap>
#include "List.h"
#include <QMessageBox>
#include "endlistbox.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}
Dialog::Dialog(QString Title, QString i_path, List<Planet> *Lptr, QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog),
    LD(Lptr) //LD will be pointing at the same list, as UList in MainWindow
{
    ui->setupUi(this);
    QPixmap *pixmap = new QPixmap( i_path);
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pixmap->scaled(w, h, Qt::KeepAspectRatio)); //Picture will be sized as label

    ui->label_name->setText(Title);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_nextButton_clicked()
{
        index++;
        if(index > LD->getLastNodeIndex())
        {
             index = LD->getLastNodeIndex();
             EndListBox E;
             E.exec();
        }

        QString Title = QString::fromStdString( (LD->operator [](index))->Object->getName()  );
        ui->label_name->clear();
        ui->label_name->setText(Title);
        //LD[index]->Object->getName() didn't work :(
        QString i_path = (LD->operator [](index))->Object->getimage_path();

        ui->label_pic->clear(); //Clear the label
        QPixmap *pixmap = new QPixmap(i_path); //Create new Pixmap
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();
        ui->label_pic->setPixmap(pixmap->scaled(w, h, Qt::KeepAspectRatio)); //Set pixmap to the label
        this->exec();
}

void Dialog::on_deleteButton_clicked()
{
    LD->deleteNode(index);
    bool isnull = false;
        //Same stuff as above
        if(index > LD->getLastNodeIndex())
        {
             cout << "index: " << index << endl;
             index = LD->getLastNodeIndex();
             cout << "index after change: " << index << endl;
             EndListBox E;
             E.exec();
             if(index == -1) //-1 is an index of First pointer in the List.
             {
                QMessageBox M;
                M.setText("Nothing here!");
                M.exec();
                isnull = true;
                this->close();
             }
        }
        if(!isnull)
        {
            QString Title = QString::fromStdString( (LD->operator [](index))->Object->getName()  );
            ui->label_name->clear();
            ui->label_name->setText(Title);
            //LD[index]->Object->getName() didn't work :(
            QString i_path = (LD->operator [](index))->Object->getimage_path();

            ui->label_pic->clear(); //Clear the label
            QPixmap *pixmap = new QPixmap(i_path); //Create new Pixmap
            int w = ui->label_pic->width();
            int h = ui->label_pic->height();
            ui->label_pic->setPixmap(pixmap->scaled(w, h, Qt::KeepAspectRatio)); //Set pixmap to the label
            this->exec();
        }
}\

