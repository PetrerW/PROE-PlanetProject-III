#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>
#include "stdafx.h"
#include "Satellite.h"
#include "Country.h"
#include "Continent.h"
#include "Planet.h"
#include "LivingPlanet.h"
#include "PopulatedPlanet.h"
#include "GasPlanet.h"
#include "List.h"
#include "Node.h"
#include <iostream>
#include <fstream>

List<Planet> L;
int index;

Planet* Earth = new PopulatedPlanet("Earth");
Planet* Jupiter = new GasPlanet("Jupiter");
Planet* Mars = new LivingPlanet("Mars");
Planet* Neptun = new GasPlanet("Neptun");
Planet* Uran = new GasPlanet("Uran");
Planet* Mercury = new LivingPlanet("Mercury");
Planet* Saturn = new GasPlanet("Saturn");
Planet* Venus = new LivingPlanet("Venus");


Node<Planet> EarthNode(Earth);
Node<Planet> JupiterNode(Jupiter);
Node<Planet> MarsNode(Mars);
Node<Planet> NeptunNode(Neptun);
Node<Planet> UranNode(Uran);
Node<Planet> MercuryNode(Mercury);
Node<Planet> SaturnNode(Saturn);
Node<Planet> VenusNode(Venus);


int main(int argc, char *argv[])
{
    index=0;

    Earth->changeImagePath("C:\\Users\\oem\\Desktop\\Programowanie\\Dokumenty C++\\Planet\\PlanetApp\\Pictures\\Earth.jpg");
    Jupiter->changeImagePath("C:\\Users\\oem\\Desktop\\Programowanie\\Dokumenty C++\\Planet\\PlanetApp\\Pictures\\Jupiter.jpg");
    Mars->changeImagePath("C:\\Users\\oem\\Desktop\\Programowanie\\Dokumenty C++\\Planet\\PlanetApp\\Pictures\\Mars.jpg");
    Neptun->changeImagePath("C:\\Users\\oem\\Desktop\\Programowanie\\Dokumenty C++\\Planet\\PlanetApp\\Pictures\\Neptun.jpg");
    Uran->changeImagePath("C:\\Users\\oem\\Desktop\\Programowanie\\Dokumenty C++\\Planet\\PlanetApp\\Pictures\\Uran.jpg");
    Mercury->changeImagePath("C:\\Users\\oem\\Desktop\\Programowanie\\Dokumenty C++\\Planet\\PlanetApp\\Pictures\\Mercury.jpg");
    Saturn->changeImagePath("C:\\Users\\oem\\Desktop\\Programowanie\\Dokumenty C++\\Planet\\PlanetApp\\Pictures\\Saturn.jpg");
    Venus->changeImagePath("C:\\Users\\oem\\Desktop\\Programowanie\\Dokumenty C++\\Planet\\PlanetApp\\Pictures\\Venus.jpg");

    L.add( &EarthNode, 0);
    L.add( &JupiterNode, 1);
    L.add( &MarsNode, 2);
    L.add( &MercuryNode, 3);
    L.add( &NeptunNode, 4);
    L.add( &SaturnNode, 5);
    L.add( &UranNode, 6);
    L.add( &VenusNode, 7);

    QApplication a(argc, argv);
    MainWindow w;
    w.changeList(L);
    w.show();

    return a.exec();
}
