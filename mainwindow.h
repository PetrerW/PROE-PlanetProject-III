#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "List.h"
#include "Planet.h"
#include "Node.h"
#include "alreadythere.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void changeList(List<Planet> &L);
    int getIndex();
    void changeIndex(int l);
    void addElement(List<Planet> &L);
    bool isHere(string s);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_actionEarth_triggered();
    void on_actionJupiter_triggered();
    void on_actionMars_triggered();
    void on_actionMercury_triggered();
    void on_actionNeptun_triggered();
    void on_actionSaturn_triggered();
    void on_actionUran_triggered();
    void on_actionVenus_triggered();

private:
    Ui::MainWindow *ui;
    List<Planet> UList; //UList - list for User,
    List<Planet> BList; //BList- Base List. It will include every planet in order to add it to UList
    int index = 0;
};

#endif // MAINWINDOW_H
