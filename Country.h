#pragma once
#include <string>
#include "Satellite.h"
class Country
{
public:
	Country();
	Country(int population, int area, string name, string capital, Satellite *MainSatellite);
	Country(const Country &c); ///copying constructor
	~Country();

	void show(ostream& s);
	void ThereIsSatellite();
	void ShowSatellite(ostream& s);
	void retrieve(istream& s);
	static void ShowCountriesNumber();

	int population; ///Millions of people (10^6)
	int area; ///Thousands of km^2
	std::string name;
	std::string capital;
	Satellite *MainSatellite;

	Country& Country::operator=(const Country &c);
	Country Country::operator+(Satellite &s);
	Country Country::operator-=(Satellite &s);
	Country Country::operator+=(Satellite &s);
	bool Country::operator==(const Country &c);

private:
	static int countries_number;
};