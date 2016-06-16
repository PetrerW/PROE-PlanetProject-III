#pragma once
#include <string>

using namespace std;
class Satellite
{
public:

	Satellite();
	Satellite(string name, string role, string owner);
	Satellite(string name, string role, string owner, int radius, int velocity, int initiation_year);
	Satellite(const Satellite &s);
	void show(ostream& s);
	void retrieve(istream& s);
	static void showNumberOfSatellites();
	int findMin(int radius1, int radius2);
	~Satellite(); 
	string name; 
	string role; ///It's destination
	string owner; ///Which country the Satellite belongs to
	
	Satellite Satellite::operator-(const Satellite &s); /// (3) Basic satellite difference. Changes radius and velocity.
	Satellite& Satellite::operator=(const Satellite &s); /// (4) It allows us to make a = b = c; instruction
	bool Satellite::operator==(const Satellite &s);		/// (5) Check if names are the same
	Satellite Satellite::operator-=(const Satellite &s); /// (7) look upwards


private:
	int radius; ///Average radius at the orbit. (Given in megameters )
	int velocity; ///Average velocity at the orbit (Given in kilometers per second)
	int initiation_year; ///When it was sent into space
	static int satellites_number; /// How much Satellites we have?
};
