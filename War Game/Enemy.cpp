#include "Enemy.h"
#include <sstream>
Enemy::Enemy(string name, int health, int armor, Weapon weapon)
{
	this->name = name;
	this->health = health;
	this->armor = armor;
	this->weapon = weapon;
}

Enemy::Enemy()
{
	this->name = "Unknown";
	this->health = 0;
	this->armor = 0;
}

Enemy::~Enemy()
{
}

//Getters
string Enemy::getName() const
{
	return this->name;
}
int Enemy::getHealth() const
{
	return this->health;
}
int Enemy::getArmor() const
{
	return this->armor;
}
Weapon Enemy::getWeapon() const
{
	return this->weapon;
}

//Setters
void Enemy::setName(string name)
{
	this->name = name;
}
void Enemy::setHealth(int health)
{
	this->health = health;
}
void Enemy::setArmor(int armor)
{
	this->armor = armor;
}
void Enemy::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

void Enemy::initiate(string name, int health, int armor, Weapon weapon)
{
	this->name = name;
	this->health = health;
	this->armor = armor;
	this->weapon = weapon;
}

string Enemy::toString() const
{
	stringstream converter;
	converter << "Name: " << this->name << endl << "Health: " << this->health << endl << "Armor: " << this->armor << endl << "Attack: " << this->weapon.getDamage() << "| Rof: " << this->weapon.getRof() << endl;
	return converter.str();
}

