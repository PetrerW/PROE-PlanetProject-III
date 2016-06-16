#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <QString>

using namespace std;

class Planet
{
public:
	Planet();
	Planet(string name);
	virtual ~Planet();
	virtual void beAlive() = 0;
	virtual void save(ostream& s); ///Saving whole object into a file.
	virtual void retrieve(ifstream& s, string filename); ///Retrieve whole object from a file.
	virtual void show(); ///Display every value of the object
	string getName(); ///return name of the object
    void changeImagePath(QString s);
    QString getimage_path();
	friend ostream& operator<<(ostream& s, const Planet& p);

protected:
	std::string planetary_system;
	std::string name;
	bool alive;
    QString image_path;
};
