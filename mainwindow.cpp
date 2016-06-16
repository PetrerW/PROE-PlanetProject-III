#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "dialog.h"
#include <QString>
#include "alreadythere.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    UList = BList;
    ui->setupUi(this);
    QPixmap *pixmap = new QPixmap("C:\\Users\\oem\\Desktop\\Programowanie\\Dokumenty C++\\Planet\\PlanetApp\\Pictures\\Solar System.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pixmap->scaled(w, h, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(UList.getLastNodeIndex()!=-1)
    {
        QString Title = QString::fromStdString( this->UList[index]->Object->getName() );
        QString i_path = this->UList[index]->Object->getimage_path();
        Dialog D(Title, i_path, &UList);
        D.exec();
    }
    else
    {
        QMessageBox M;
        M.setText("Nothing on the list! Please add a Planet. (File->Add)");
        M.exec();
    }

}

void MainWindow::changeList(List<Planet>& L)
{
    this->BList = L;
    this->UList = L;
}

int MainWindow::getIndex()
{
     return this->index;
}

void MainWindow::changeIndex(int l)
{
    this->index = l;
}

void MainWindow::on_actionEarth_triggered()
{
    if(!isHere("Earth"))
        UList.add(BList[0], UList.getLastNodeIndex()+1);
}

void MainWindow::on_actionJupiter_triggered()
{
    if(!isHere("Jupiter"))
        UList.add(BList[1],  UList.getLastNodeIndex()+1);
}

void MainWindow::on_actionMars_triggered()
{
    if(!isHere("Mars"))
        UList.add(BList[2], UList.getLastNodeIndex()+1);
}

void MainWindow::on_actionMercury_triggered()
{
    if(!isHere("Mercury"))
        UList.add(BList[3], UList.getLastNodeIndex()+1);
}

void MainWindow::on_actionNeptun_triggered()
{
    if(!isHere("Neptun"))
        UList.add(BList[4], UList.getLastNodeIndex()+1);
}

void MainWindow::on_actionSaturn_triggered()
{
    if(!isHere("Saturn"))
        UList.add(BList[5], UList.getLastNodeIndex()+1);
}

void MainWindow::on_actionUran_triggered()
{
    if(!isHere("Uran"))
        UList.add(BList[6], UList.getLastNodeIndex()+1);
}

void MainWindow::on_actionVenus_triggered()
{
    if(!isHere("Venus"))
        UList.add(BList[7], UList.getLastNodeIndex()+1);
}

bool MainWindow::isHere(string s)
{
    for(int i=0; i<UList.getLastNodeIndex(); i++)
    {
        if(UList[i]->Object->getName()==s)
        {
            AlreadyThere A;
            A.exec();
            return true;
        }
    }
    return false;
}


