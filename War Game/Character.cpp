#include "Character.h"
#include <sstream>

//Konstruktorerna
Character::Character(string name, string type, int health, int baseHealth, int weight, int experience, int level, int armor, int explosives, Weapon weapon, int score)
{
	this->name = name;
	this->type = type;
	this->health = health;
	this->weight = weight;
	this->experience = experience;
	this->level = level;
	this->armor = armor;
	this->explosives = explosives;
	this->weapon = weapon;

	this->baseHealth = baseHealth;

	this->score = score;
}
Character::Character()
{
	this->name = "unknown";
	this->type = "unknown";
	this->health = 0;
	this->weight = 0;
	this->experience = 0;
	this->level = 0;
	this->armor = 0;
	this->explosives = 0;
	this->baseHealth = 0;
	this->score = 0;
}
//Destruktorn
Character::~Character()
{

}

//Get funktioner
string Character::getName() const
{
	return this->name;
}
string Character::getType() const
{
	return this->type;
}
int Character::getHealth() const
{
	return this->health;
}
int Character::getWeight() const
{
	return this->weight;
}
int Character::getExperience() const
{
	return this->experience;
}
int Character::getLevel() const
{
	return this->level;
}
int Character::getArmor() const
{
	return this->armor;
}
int Character::getExplosives() const
{
	return this->explosives;
}

int Character::getBaseHealth() const
{
	return this->baseHealth;
}

Weapon Character::getWeapon() const
{
	return this->weapon;
}

Inventory Character::getInventory() const
{
	return this->items;
}

int Character::getScore() const
{
	return this->score;
}

//Set funktioner
void Character::setName(string name)
{
	this->name = name;
}
void Character::setType(string type)
{
	this->type = type;
}
void Character::setHealth(int health)
{
	this->health = health;
}
void Character::setWeight(int weight)
{
	this->weight = weight;
}
void Character::setExperience(int experience)
{
	this->experience = experience;
}
void Character::setLevel(int level)
{
	this->level = level;
}
void Character::setArmor(int armor)
{
	this->armor = armor;
}
void Character::setExplosives(int explosives)
{
	this->explosives = explosives;
}

void Character::setBaseHealth(int baseHealth)
{
	this->baseHealth = baseHealth;
}

void Character::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

void Character::setScore(int score)
{
	this->score = score;
}

void Character::destroyWeapon()
{
	if (this->items.getWeapons().size() > 0)
	{
		this->weapon = this->items.getWeapons().back();
	}
	else
	{
		this->weapon = Weapon("Hands", 2, 0, 2, 100);
	}
}

void Character::addWeapon(Weapon addedWeapon)
{
	this->items.addWeapon(addedWeapon);
}

void Character::removeWeaponAt(int index)
{
	if (index < this->items.getWeapons().size())
	{
		this->items.removeWeapon(index);
	}
}

void Character::equipWeapon(int index)
{
	if (index < this->items.getWeapons().size())
	{
		Weapon temp;
		temp = this->weapon;
		this->weapon = this->items.getWeapons().at(index);
		this->items.removeWeapon(index);
		this->items.addWeapon(temp);
	}
}

void Character::loseDurability(int durabilityLoss)
{
	this->weapon.setDurability(this->weapon.getDurability() - durabilityLoss);
}

void Character::gainExp(int amount)
{
	this->experience += amount;

	while(this->experience >= 100 * (this->level * this->level))
	{
		this->experience -= 100 * (this->level * this->level);
		this->level++;
		this->weapon.setDamage(this->weapon.getDamage() + 5);
		this->baseHealth += 100;
		this->health = this->baseHealth;
		this->armor += 20;
	}
}

//Convertera allt till en sträng
string Character::toString() const
{
	stringstream converter;
	converter << "Name: " << this->name << "\nType: " << this->type << "\nWeight: " << this->weight << "\nHealth: " << this->health << "/" << this->baseHealth << " | Armor: " << this->armor << "\nExperience: " << this->experience << "\nLevel: " << this->level << " | Required XP for next level: " << 100 * (this->level * this->level) << endl << this->weapon.toString();
	return converter.str();
} 

string Character::saveString() const
{
	stringstream converter;
	converter << this->score << endl << this->name << endl << this->type << endl << this->health << endl << this->baseHealth << endl << this->weight << endl << this->experience << endl << this->level << endl << this->armor << endl << this->explosives << endl << this->weapon.saveString() << endl << this->items.saveString();
	return converter.str();
}