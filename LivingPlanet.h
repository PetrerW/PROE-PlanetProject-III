#pragma once
#include "Planet.h"
#include <iostream>
#include <fstream>

class LivingPlanet : public Planet
{
public:
	LivingPlanet();
	LivingPlanet(string name);
	void beAlive();
	void save(ostream & s);
	void retrieve(ifstream & s, string filename);
	void show();
	friend ostream& operator<<(ostream& out, const LivingPlanet &LP);
};