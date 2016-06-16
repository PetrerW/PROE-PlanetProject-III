#pragma once
#include "Planet.h"
#include <iostream>
#include <fstream>

class GasPlanet : public Planet
{
public:
	GasPlanet();
	GasPlanet(string name);
	void beAlive();
	void save(ostream & s);
	void retrieve(ifstream & s, string filename);
	void show();
	friend ostream& operator<<(ostream& out, const GasPlanet &GP);
private:
	int gas_concentration;
};