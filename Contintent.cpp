#include "Continent.h"
#include <fstream>

int Continent::continents_number = 0;
void Continent::showContinentsNumber()
{
	cout << "There are " << continents_number  << " Continents" << endl;
}

Continent::Continent()
{
#ifdef _DEBUG
	std::cout << "Creating a default Continent object... " << endl;
#endif
	name = "Noname";
	area = 0;
	population = 0;
	continents_number++;
	GreatestCountries = NULL;
}

Continent::Continent(string name) :
	name(name)
{
#ifdef _DEBUG
	std::cout << "Creating a non-default Continent object... " << endl;
#endif
	area = 0;
	population = 0;
continents_number++;
GreatestCountries = NULL;
}

Continent::Continent(const Continent & c) :
	area(area), population(population)
{
	GreatestCountriesVector = c.GreatestCountriesVector; ///Copy of the Country object vector
}

Continent::~Continent()
{
#ifdef _DEBUG
	std::cout << "Destroing a Continent object... " << endl;
#endif
	GreatestCountriesVector.clear();
}

void Continent::showCountriesNumber(ostream& s)
{
	s << "Number of Countries: " << GreatestCountriesVector.size() << endl;
}

void Continent::showCountries(ostream& s)
{
	s << "Countries: " << endl;
	for (int i = 0; i != GreatestCountriesVector.size(); i++)
	{
		GreatestCountriesVector[i].show(s);
	}
	s << "countries-end" << endl;
}

void Continent::show(ostream& s)
{
	s << "Continent beginning" << endl
		<< "Continent name: " << name << endl;
	showCountriesNumber(s);
	showCountries(s);
	s << "Area: " << area << endl;
	s << "Population: " << population << endl << endl;
	s << "Continent-end" << endl << endl;
}

void Continent::retrieve(istream & s)
{
	string line;
	size_t find_in_line;
	string keyWords[] = { "Continent name: " , "Number of Countries: ", "Countries: " , "countries-end",
		"Area: ", "Population: ", "Continent-end" };
	bool continentEnd = false;
	while (!continentEnd)///While loop is going to go through every element of this table and assign appropiate values.
	{
		getline(s, line);
		for (int a = 0; a < 7; a++) ///Checking if the keyWord is in the line
		{
			find_in_line = line.find(keyWords[a]);
			///Index of the phrase we're looking for in the strings.
			if (find_in_line != string::npos)
			{
				///One of keyWords inscriptions found in the line
				line.erase(find_in_line, keyWords[a].length());
				switch (a)
				{
				case 0: ///"Continent name: "
					this->name = line; a = 7; break;
				case 1: ///"Number of Countries: "
					this->GreatestCountriesVector.resize(atoi(line.c_str())); a = 7; break;
				case 2: ///"Countries: "
					for (int j = 0; j < GreatestCountriesVector.size(); j++)
						GreatestCountriesVector[j].retrieve(s);
					a = 7;
					break;
				case 3: ///"countries-end"
					a = 7; break;
				case 4: ///"Area: "
					this->area = atoi(line.c_str()); a = 7; break;
				case 5: ///"Population: "
					this->population = atoi(line.c_str()); a = 7; break;
				case 6: ///"Continent-end"
					continentEnd = true; a = 7; break;
				default: ///I expect going over endlines etc.
					cout << "default..." << endl; a = 7; break;
				}
			}
		}
	}
}

void Continent::isCountry()
{
	if (GreatestCountriesVector.size() != 0)
		cout << "There are countries in " << name << endl;
	else
		cout << "No countries in " << name << endl;
}

void Continent::sumProperties()
{
	for (int i = 0; i < GreatestCountriesVector.size(); i++)
	{
		population += GreatestCountriesVector[i].population;
		area += GreatestCountriesVector[i].area;
	}
}

Continent::operator int()
{
	return continents_number;
}

void Continent::operator[](Country NewCountry) ///Adding a Country to the Continent
{
	bool is_here = false;

	for (int i = 0; i < GreatestCountriesVector.size(); i++) ///Checking if the Country is already in the Continent
		if (NewCountry  == GreatestCountriesVector[i])
			is_here = true;

	if (!is_here)
	{
		GreatestCountriesVector.push_back(NewCountry);
		this->population += NewCountry.population; ///Adding the population of the added Country to the Continent
		this->area += NewCountry.area;
	}
	else
		cout << "This country is already in" << name << "!" << endl;
}

void Continent::deleteCountry()
{
	int index;
	vector<Country>::iterator it;
	showCountries(cout);

	cout << "Enter the index of the country you want to delete." << endl;
	cin >> index;

	GreatestCountriesVector.erase(GreatestCountriesVector.begin() + index);
	cout << "deleting succesful!" << endl;
}
