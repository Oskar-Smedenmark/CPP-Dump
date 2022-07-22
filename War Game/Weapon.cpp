#include "Weapon.h"

Weapon::Weapon()
{
	this->name = "Unknown";
	this->damage = 1;
	this->weight = 1;
	this->rof = 1;
	this->durability = 100;
}

Weapon::Weapon(string name, int damage, int weight, int rof, int durability)
{
	this->name = name;
	this->damage = damage;
	this->weight = weight;
	this->rof = rof;
	this->durability = durability;
}

Weapon::~Weapon()
{
}

//Getters
int Weapon::getDamage() const
{
	return this->damage;
}

int Weapon::getDurability() const
{
	return this->durability;
}

int Weapon::getWeight() const
{
	return this->weight;
}

int Weapon::getRof() const
{
	return this->rof;
}

string Weapon::getName() const
{
	return this->name;
}

//Setters
void Weapon::setDamage(int damage)
{
	this->damage = damage;
}

void Weapon::setDurability(int durability)
{
	this->durability = durability;
}

void Weapon::setWeight(int weight)
{
	this->weight = weight;
}

void Weapon::setRof(int rof)
{
	this->rof = rof;
}

void Weapon::setName(string name)
{
	this->name = name;
}

string Weapon::toString() const
{
	stringstream converter;
	converter << endl << "Weapon: " << this->name << endl << "Damage: " << this->damage << endl <<"Weight: " << this->weight << endl << "Rate of Fire: " << this->rof << endl << "Durability: " << this->durability << endl;
	return converter.str();
}

string Weapon::saveString() const
{
	stringstream converter;
	converter << this->name << endl << this->damage << endl << this->weight << endl << this->rof << endl << this->durability << endl;
	return converter.str();
}
