#ifndef CHARACTER_H
#define CHARACTER_H
#include "Weapon.h"
#include "Inventory.h"

class Character
{
private:
//Medlemsvariabler
	string name;
	string type;
	int health;
	int weight;
	int experience;
	int level;
	int armor;
	int explosives;
	Weapon weapon;

	Inventory items;
	int baseHealth;

	int score;

public:
//Konstruktor
	Character(string name, string type, int health, int baseHealth, int weight, int experience, int level, int armor, int explosives, Weapon weapon, int score);
//Defaultkonstruktor
	Character();
//Destruktor
	~Character();

//Medlemsfunktioner
	string getName() const;
	string getType() const;
	int getHealth() const;
	int getWeight() const;
	int getExperience() const;
	int getLevel() const;
	int getArmor() const;
	int getExplosives() const;
	int getBaseHealth() const;
	Weapon getWeapon() const;
	Inventory getInventory() const;
	int getScore() const;

	void setName(string name);
	void setType(string type);
	void setHealth(int health);
	void setWeight(int weight);
	void setExperience(int experience);
	void setLevel(int level);
	void setArmor(int armor);
	void setExplosives(int explosives);
	void setBaseHealth(int baseHealth);
	void setWeapon(Weapon weapon);
	void setScore(int score);

	void destroyWeapon();

	void addWeapon(Weapon addedWeapon);
	void removeWeaponAt(int index);
	
	void equipWeapon(int index);

	void loseDurability(int durabilityLoss);

	void gainExp(int amount);

	string toString() const;
	string saveString() const;







};

#endif