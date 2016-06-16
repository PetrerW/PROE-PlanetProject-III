#include "Satellite.h"
#include <iostream>
using namespace std;

int Satellite::satellites_number = 0;
void Satellite::showNumberOfSatellites()
{
	cout << "There are " << Satellite::satellites_number << " Satellite objects." << endl;
}

Satellite::Satellite()
{
#ifdef _DEBUG
	cout << "Creating a default Satellite object... " << name << endl;
#endif
	satellites_number++;
	name = "Orbiter";
	role = "TV Satellite";
	owner = "USA";
	radius = 50;
	velocity = 10;
	initiation_year = 1996;
}

Satellite::Satellite(string name, string role, string owner)
{
#ifdef _DEBUG
	cout << "Creating a non-default (1) Satellite object... " << name << endl;
#endif
	satellites_number++;

	this->name = name;
	this->role = role;
	this->owner = owner; 
	radius = 50;
	velocity = 10;
	initiation_year = 1996;
}

Satellite::Satellite(string name, string role, string owner, int radius, int velocity, int initiation_year) :
	name(name), role(role), owner(owner), radius(radius), velocity(velocity), initiation_year(initiation_year)
{
#ifdef _DEBUG
	std::cout << "Creating a non-default (2) Satellite object... " << name << endl;
#endif
	satellites_number++;
}

Satellite::Satellite(const Satellite & s)
{
	name = s.name;
	role = s.role;
	owner = s.owner;
	radius = s.radius;
	velocity = s.velocity;
	initiation_year = s.initiation_year;

	satellites_number++;
}

Satellite::~Satellite()
{
#ifdef _DEBUG
	std::cout << "Destroying a Satellite object... " << endl;
#endif
	satellites_number--;
}

void Satellite::show(ostream& s)
{
	if (this != NULL)
	{
		s << "Satellite beginning" << endl
			<< "Satellite addres: " << this << endl
			<< "Satellite name: " << name << endl
			<< "Satellite role: " << role << endl
			<< "Satellite owner: " << owner << endl
			<< "Satellite radius: " << radius << endl
			<< "Satellite velocity: " << velocity << endl
			<< "Satellite initiation year: " << initiation_year << endl
			<< "End of Satellite" << endl;
	}
	else
		s << "Satellite nullptr" << endl;
}

void Satellite::retrieve(istream & s)
{
	string line;
	size_t find_in_line;
	string keyWords[7] ={	"Satellite name: ",
							"Satellite role: ",
							"Satellite owner: ",
							"Satellite radius: ",
							"Satellite velocity: ",
							"Satellite initiation year: ",
							"End of Satellite"				};
	///While loop is going to go through every element of this table and assign appropiate values.
	bool satelliteEnd = false;
	while (!satelliteEnd)
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
					case 0: ///"Satellite name: "
						this->name = line; i = 7;  break;
					case 1: ///"Satellite role: "
						this->role = line; i = 7;  break;
					case 2: ///"Satellite owner: "
						this->owner = line; i = 7; break;
					case 3: ///"Satellite radius: "
						this->radius = atoi(line.c_str()); i = 7; break;
					case 4: ///"Satellite velocity: "
						this->velocity = atoi(line.c_str()); i = 7; break;
					case 5: ///"Satellite initiation year: "
						this->initiation_year = atoi(line.c_str()); i = 7;  break;
					case 6: ///"End of Satellite"
						satelliteEnd = true;  i = 7; break;
					default: ///I expect going over endlines etc.
						cout << "default... (satellite)" << endl; break;
					}
				}
			}
	}
}

int Satellite::findMin(int radius1, int radius2)
{
	if (radius1 < radius2)
		return radius1;
	else
		return radius2;
}

Satellite Satellite::operator-(const Satellite & s)
{
	return Satellite(name, owner, role, 5 + abs(radius - s.radius), 5 + abs(velocity - s.velocity), 2016);
}

Satellite& Satellite::operator=(const Satellite & s)
{
	if (&s != NULL)
	{
		name = s.name;
		role = s.role;
		owner = s.owner;
		radius = s.radius;
		velocity = s.velocity;
		initiation_year = s.initiation_year;
	}
	return *this;
}

bool Satellite::operator==(const Satellite &s)
{
	if (this->name == s.name)
		return true;
	else
		return false;
}

Satellite Satellite::operator-=(const Satellite & s)
{
	*this = *this - s;
	return *this;
}