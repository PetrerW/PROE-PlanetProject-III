#pragma once
#include "Country.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Continent
{
public:
	Continent();
	Continent(string name);
	Continent(const Continent& c);
	~Continent();

	static void showContinentsNumber();
	void showCountriesNumber(ostream& s);
	void showCountries(ostream &s);
	void show(ostream& s);
	void retrieve(istream& s);
	void isCountry();
	void sumProperties();

	string name;
	int area; ///Sum of the countries' areas. Thousands of km^2.
	int population; ///Sum of the countries' populations. Millions of people
	Country *GreatestCountries;
	vector <Country> GreatestCountriesVector; ///A vector of Greatest Countries instead of dynamically allocated table of pointers

	operator int(); ///Return continents_number
	void operator[](Country NewCountry);
	void deleteCountry(); ///Delete a country from a continent

private:
	static int continents_number;
};