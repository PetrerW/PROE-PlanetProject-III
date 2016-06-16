#include "PopulatedPlanet.h"
#include "Satellite.h"

using namespace std;

PopulatedPlanet::PopulatedPlanet() : LivingPlanet()
{
	Continents[0].name = "Europe";
	Continents[1].name = "North America";
	area = 0;
	population = 0;
	beAlive();
	this->name = "DefaultPopulatedPlanet";
}

PopulatedPlanet::PopulatedPlanet(string name) : LivingPlanet()
{
	this->name = name;
	area = 0;
	population = 0;
	beAlive();
}

void PopulatedPlanet::beAlive()
{
	cout << "beAlive virtual function of " << this->name << endl;
	alive = "yes";
}

ostream & operator<<(ostream & out, const PopulatedPlanet & PP)
{
	out << (*(LivingPlanet*)&PP); ///We use << operator of the base class LivinPlanet.
	out << "Planet area: " << PP.area << endl << "Planet population: " << PP.population << endl;
	return out;
}

void PopulatedPlanet::save(ostream & s)
{
	s << (*this);
	this->Continents[0].show(s);
	this->Continents[1].show(s);
	s << "Planet end" << endl;
}

void PopulatedPlanet::show()
{
	cout << planetary_system << endl << name << endl << alive << endl << area << endl << population << endl;
}

void PopulatedPlanet::sumProperties()
{
	area += Continents[0].area + Continents[1].area;
	population += Continents[0].population + Continents[1].population;
}

void PopulatedPlanet::retrieve(ifstream & s, string filename)
{
	s.open(filename, ios::in);
	string keyWords[] = { "Name: ", "Planetary system: ", "alive? ", "Planet area: ", "Planet population: ", "Continent beginning", "Planet end" };
	string line;
	size_t find_in_line;
	int j = 0; ///If we have already changed the name, planetary_system or anything, we increment j. 
			   ///Then in the for loop a = j
	int i = 0; ///Continents [0] and [1]
	bool planetEnd = false;
	while (!planetEnd)///While loop is going to go through every element of this table and assign appropiate values.
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
				case 0: ///"Name: "
					this->name = line; 
					a = 7; 
					//j = 1; 
							break; ///a=7: go out of the for loop
				case 1: ///"Planetary system: "
					this->planetary_system = line; 
					//j = 2; 
					a = 7; 
							break;
				case 2: ///"alive? "
					if (line == "1") this->alive = true;
					else this->alive = false;
					a = 7; 
					//j = 3; 
							break;
				case 3: ///"Planet area: "
					this->area = atoi(line.c_str()); 
					a = 7; 
					//j = 4; 
							break;
				case 4: ///"Planet population: "
					this->population = atoi(line.c_str()); 
					a = 7; 
					//j = 5;
							break;
				case 5: ///"Continent beginning"
					Continents[i].retrieve(s);
					i++;
					a = 7;
					//j = 6;
							break;
				case 6: ///"Planet end"
					planetEnd = true; 
					a = 7;  
							break;
				default: ///I expect going over endlines etc.
					cout << "default..." << endl; 
					a = 7; 
							break;
				}
			}
		}
	}
	s.close();
}

