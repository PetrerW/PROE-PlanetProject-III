#include "Country.h"
#include "Satellite.h"
#include <iostream>

using namespace std; 

int Country::countries_number = 0;
void Country::ShowCountriesNumber()
{
	cout << "There are " << Country::countries_number << " Country objects." << endl;
}

Country::Country():
	area(0), population(0), capital("No capital"), name("No name"), MainSatellite(nullptr)
{
#ifdef _DEBUG
	std::cout << "Creating a default Country object... " << name <<  endl;
#endif
	countries_number++;
}

Country::~Country()
{
#ifdef _DEBUG
	std::cout << "Destroying a Country object... " << endl;
#endif
	if(this->MainSatellite != nullptr)
		delete this->MainSatellite;
	countries_number--;
}

Country::Country(int population, int area, string name, string capital, Satellite * MainSatellite) :
	population(population), area(area), name(name), capital(capital), MainSatellite(MainSatellite)
{
#ifdef _DEBUG
	cout << "Creating a default Country object..." << name << endl;
#endif
	if (this->MainSatellite != nullptr)
	{
		this->MainSatellite->owner = this->name;
	}
	countries_number++;
}

Country& Country::operator=(const Country & c)
{
	if (this != nullptr)
	{
		if (c.MainSatellite != MainSatellite)
		{
			delete MainSatellite;
		}
		if (c.MainSatellite == nullptr)
			MainSatellite == nullptr;
		else
		{
			MainSatellite = new Satellite();
			*MainSatellite = *(c.MainSatellite);
		}
		name = c.name;
		population = c.population;
		area = c.area;
		capital = c.capital;
	}
	return *this;
}

Country::Country(const Country & c)
{
#ifdef _DEBUG
	cout << "Creating a Country object with a copying constructor..." << name << endl;
#endif
	if (&c != nullptr)
	{
		area = c.area;
		area = c.area;
		population = c.population;
		name = c.name;
		capital = c.capital;
		if (c.MainSatellite != nullptr)
		{
			MainSatellite = new Satellite;
			*MainSatellite = *(c.MainSatellite);
		}
		else
			MainSatellite = nullptr;
		countries_number++;
	}
	else
	{
		area = population = 0;
		capital = name = "";
		MainSatellite = nullptr;
	}
}

void Country::show(ostream& s)
{
	s << "Country beginning" << endl;
	s << "Country name: " << name << endl;
		s << "The capital city: " << capital << endl;
		s << "population: " << population << endl;
	s << "area: " << area << endl;
	MainSatellite->show(s);
	s << "country-end" << endl << endl;
}

void Country::ShowSatellite(ostream& s)
{
	if (MainSatellite != nullptr)
		MainSatellite->show(s);
	else
		cout << "MainSatellite of " << name << " is NULL!" << endl << endl;
}

void Country::retrieve(istream & s)
{
	string line;
	size_t find_in_line;
	string keyWords[] = { "Country name: ", "The capital city: ", "population: ", "area: ",
		"Satellite beginning",  "Satellite nullptr", "country-end",  };
	int j = 0;
	bool countryEnd = false;
	while (!countryEnd) ///While loop is going to go through every element of this table and assign appropiate values.
	{
		getline(s, line);
		for (int i = 0; i < 7; i++) ///Checking if a keyWord is in the line
		{
			find_in_line = line.find(keyWords[i]); ///Index of the phrase we're looking for in the strings.
			if (find_in_line != string::npos) ///The keyWord is in the line
			{
				///One of keyWords inscriptions found in the line
				line.erase(find_in_line, keyWords[i].length());
				switch (i)
				{
				case 0: ///"Country name: "
					this->name = line; 
					j = 1;
					i = 7; 
							break;
				case 1: ///"The capital city: "
					this->capital = line; 
					j = 2;
					i = 7;
							break;
				case 2: ///"population: "
					this->population = atoi(line.c_str()); 
					j = 3;
					i = 7;
							break;
				case 3: ///"area: "
					this->area = atoi(line.c_str()); 					
					j = 4;
					i = 7;
					break;
				case 4: ///"Satellite beginning"
					if (MainSatellite == nullptr)
					{
						MainSatellite = new Satellite();
					}
					MainSatellite->retrieve(s); 					
					j = 5;
					i = 7;
					break;
				case 5: ///"Satellite nullptr"
					this->MainSatellite = nullptr; 
					j = 6;
					i = 7;
					break;
				case 6: ///"country-end"
					countryEnd = true;  					
					j = 7;
					i = 7;
					break; break;
				default: ///I expect going over endlines etc.
					cout << "default... (country)" << endl; break;
				}
			}
		}
	}
}

Country Country::operator+(Satellite & s)
{
	Country Copy(*this);
	if (Copy.MainSatellite != nullptr)
	{
		if (	 !(		*(Copy.MainSatellite) == s	)		 )
			delete Copy.MainSatellite;
	}
	Copy.MainSatellite = &s;
	s.owner = Copy.name;

	return Copy;
}

Country Country::operator-=(Satellite & s)
{
	if (s == *MainSatellite && MainSatellite != NULL)	
	{
		delete this->MainSatellite;
		this->MainSatellite = NULL;
		s.owner = "";
	}
	return *this;
}

Country Country::operator+=(Satellite & s)
{
	*this = *this + s;
	if (this != nullptr)
		this->MainSatellite->owner = this->name;
	return *this;
}

bool Country::operator==(const Country & c)
{
	bool satellites_are_equal = false;

	if (MainSatellite == nullptr && c.MainSatellite == nullptr)
		satellites_are_equal = true;
	else
	{
		satellites_are_equal = false;
		return false;
	}
		if (area == c.area && capital == c.capital && satellites_are_equal && name == c.name && population == c.population)
			return true;
		else
			return false;
}

void Country::ThereIsSatellite()
{
	if (MainSatellite != nullptr)
		cout << "There is a satellite in " << name << "." << endl;
	else
		cout << "No Satellites in " << name << "." << endl;
}
