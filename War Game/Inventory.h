#ifndef INVENTORY_H
#define INVENTORY_H

#include "Weapon.h"
#include <vector>
#include <string>

using namespace std;

class Inventory
{
private:
	int maxSize;
	vector<Weapon> weapons;
public:
	Inventory();
	Inventory(int maxSize);
	virtual ~Inventory();

	int getMaxSize() const;
	vector<Weapon> getWeapons() const;

	void setMaxSize(int maxSize);
	void setWeapons(vector<Weapon> weapons);

	void addWeapon(Weapon theWeapon);
	void removeWeapon(int pos);

	string toString() const;
	string saveString() const;
};
#endif

