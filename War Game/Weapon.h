#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <sstream>

using namespace std;

#pragma once
class Weapon
{
private:
	string name;
	int damage;
	int durability;
	int weight;
	int rof;

public:
	Weapon();
	Weapon(string name, int damage, int weight, int rof, int durability);
	virtual ~Weapon();

	//Getters
	int getDamage() const;
	int getDurability() const;
	int getWeight() const;
	int getRof() const;
	string getName() const;
	
	//Setters
	void setDamage(int damage);
	void setDurability(int durability);
	void setWeight(int weight);
	void setRof(int rof);
	void setName(string name);

	string toString() const;
	string saveString() const;
};

#endif

