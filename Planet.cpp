#include "Planet.h"

using namespace std;

Planet::Planet()
{
	planetary_system = "solar system";
	name = "DefaultPlanet";
}

Planet::Planet(string name)
{
	this->name = name;
	planetary_system = "solar system";
}

Planet::~Planet()
{
}

void Planet::save(ostream & s)
{
	s << (*this);
}

void Planet::retrieve(ifstream & s, string filename)
{
	///We don't need to retrieve the abstract class objects.
}

void Planet::show()
{
	cout << planetary_system << endl << name << endl;
}

string Planet::getName()
{
	return this->name;
}

ostream & operator<<(ostream& out, const Planet & p)
{
	out << "Name: " << p.name << endl << "Planetary system: " << p.planetary_system << endl;
	return out;
}

QString Planet::getimage_path()
{
	return image_path;
}

void Planet::changeImagePath(QString s)
{
    this->image_path = s;
}
