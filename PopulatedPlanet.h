#pragma once
#include "Continent.h"
#include "LivingPlanet.h"
#include <string>
#include <fstream>

using namespace std; 

class PopulatedPlanet : public LivingPlanet
{
public:
	PopulatedPlanet();
	PopulatedPlanet(string name);
	void beAlive();
	void save(ostream & s);
	void show();
	void sumProperties();
	Continent Continents[2];
	void PopulatedPlanet::retrieve(ifstream & s, string filename);
	friend ostream& operator<<(ostream& out, const PopulatedPlanet &PP);
private:
	int area;
	int population;
};

