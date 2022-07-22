#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "Weapon.h"

using namespace std;

#pragma once
class Enemy
{
private:
	string name;
	int health;
	int armor;
	Weapon weapon;
public:
	Enemy(string name, int health, int armor, Weapon weapon);
	Enemy();
	virtual ~Enemy();
	
	//Getters
	string getName() const;
	int getHealth() const;
	int getArmor() const;
	Weapon getWeapon() const;

	//Setters
	void setName(string name);
	void setHealth(int health);
	void setArmor(int armor);
	void setWeapon(Weapon weapon);

	void initiate(string name, int health, int armor, Weapon weapon);

	string toString() const;
};

#endif
