#include "GasPlanet.h"

GasPlanet::GasPlanet() : Planet()
{
	gas_concentration = 100; ///Concantrations of average one of CO2 on Earth
	beAlive();
	this->name = "DefaultGasPlanet";
	alive = false;
}

GasPlanet::GasPlanet(string name): Planet()	
{
	this->name = name;
	beAlive();
	gas_concentration = 100; ///Concantrations of average one of CO2 on Earth
	alive = false;
}

void GasPlanet::beAlive()
{
	cout << "beAlive virtual function of " << this->name << endl;
	alive = false;
}

ostream & operator<<(ostream & out, const GasPlanet & GP)
{
	out << *((Planet*)&GP); ///We cast << operator of the basic Planet class.
	out << "alive? " << GP.alive << endl;
	out << "Gas concentration: " << GP.gas_concentration << endl;
	return out;
}

void GasPlanet::save(ostream & s)
{
	s << (*this);
	s << "Planet end" << endl;
}

void GasPlanet::retrieve(ifstream & s, string filename)
{
	s.open(filename, ios::in);
	string keyWords[] = { "Name: ", "Planetary system: ", "alive? ", "Gas concentration: ", "Planet end" };
	string line;
	size_t find_in_line;
	int j = 0;
	bool planetEnd = false;
	while (!planetEnd)///While loop is going to go through every element of this table and assign appropiate values.
	{
		getline(s, line);
		for (int a = 0; a < 5; a++) ///Checking if the keyWord is in the line
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
					a = 5; 
					j = 1;
							break; ///a=5; go out of the for loop
				case 1: ///"Planetary system: "
					this->planetary_system = line; 
					a = 5; 
					j = 2;
							break;
				case 2: ///"alive? "
					if (line == "1") alive = true;
					else alive = false;
					a = 5; 
					j = 3;
							break;
				case 3: ///"Gas concentration: "
					a = 5; 
					j = 4;
							break;
				case 5: ///"Planet end"
					planetEnd = true; 
					a = 5;  
							break;
				default: ///I expect going over endlines etc.
					cout << "default..." << endl; 
					a = 5; 
							break;
				}
			}
		}
	}
	s.close();
}

void GasPlanet::show()
{
	cout << planetary_system << endl << name << endl << alive << endl << gas_concentration << endl;
}
