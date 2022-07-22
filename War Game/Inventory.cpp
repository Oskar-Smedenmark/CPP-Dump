#include "Inventory.h"
#include <sstream>


Inventory::Inventory()
{
	this->maxSize = 10;
}
Inventory::Inventory(int maxSize)
{
	this->maxSize = maxSize;
}
Inventory::~Inventory()
{
}

int Inventory::getMaxSize() const
{
	return this->maxSize;
}

vector<Weapon> Inventory::getWeapons() const
{
	return this->weapons;
}

void Inventory::setMaxSize(int maxSize)
{
	this->maxSize = maxSize;
}

void Inventory::setWeapons(vector<Weapon> weapons)
{
	this->weapons = weapons;
}

void Inventory::addWeapon(Weapon theWeapon)
{
	this->weapons.push_back(theWeapon);
}

void Inventory::removeWeapon(int pos)
{
	if (pos == 0)
	{
		this->weapons.erase(this->weapons.begin());
	}
	else if (pos < this->weapons.size())
	{
		this->weapons.erase(this->weapons.begin() + pos);
	}
}

string Inventory::toString() const
{
	stringstream converter;
	for (int i = 0; i < this->weapons.size(); i++)
	{
		converter << "----------------------------------------------" << endl;
		converter << i << "." << endl << this->weapons.at(i).toString();
		converter << "----------------------------------------------" << endl;
	}
	return converter.str();
}

string Inventory::saveString() const
{
	stringstream converter;
	converter << this->weapons.size() << endl;
	for (int i = 0; i < this->weapons.size(); i++)
	{
		converter << this->weapons.at(i).saveString();
	}
	return converter.str();
}

