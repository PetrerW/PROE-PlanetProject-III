#include "LivingPlanet.h"

LivingPlanet::LivingPlanet() : Planet()
{
	this->name = "DefaultLivingPlanet";
	beAlive();
}

LivingPlanet::LivingPlanet(string name) : Planet()
{
	this->name = name;
	beAlive();
}

void LivingPlanet::beAlive()
{
	std::cout << "beAlive virtual function of " << this->name << endl;
	alive = "yes";
}

ostream & operator<<(ostream & out, const LivingPlanet & LP)
{
	out << *((Planet*)&LP); ///Casting << operator of the base class.
	out << "alive? " << LP.alive << endl;
	return out;
}

void LivingPlanet::save(ostream & s)
{
	s << (*this);
	s << "Planet end" << endl;
}

void LivingPlanet::retrieve(ifstream & s, string filename)
{
	s.open(filename, ios::in);
	string keyWords[] = { "Name: ", "Planetary system: ", "alive? ", "Planet end" };
	string line;
	size_t find_in_line;
	int j = 0;
	bool planetEnd = false;
	while (!planetEnd)///While loop is going to go through every element of this table and assign appropiate values.
	{
		getline(s, line);
		for (int a = j; a < 4; a++) ///Checking if the keyWord is in the line
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
					a = 4; 
					j = 1;
							break; ///a=4: go out of the for loop
				case 1: ///"Planetary system: "
					this->planetary_system = line; 
					a = 4; 
					j = 2;
							break;
				case 2: ///"alive? "
					if (line == "1") alive = true;
					else alive = false; 
					a = 4;
					j = 3;
							break;
				case 3: ///"Planet end"
					planetEnd = true; 
					a = 4;  
							break;
				default: ///I expect going over endlines etc.
					cout << "default..." << endl; 
					a = 4;
							break;
				}
			}
		}
	}
	s.close();
}

void LivingPlanet::show()
{
	cout << planetary_system << endl << name << endl << alive << endl;
}