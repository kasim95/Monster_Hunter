//#include "pch.h"
#include "Character.hpp"

Character::Character()
{
	name = "NA";
	weapon_name = "NA";
	attributes = 1;
	max_health = 50;
	current_health = max_health;
	potion = 3;
	damage = 1;
	weapon_attributes = 1;
}

void Character::gain_Attribute(int value, int value_health)
{
	attributes += value;
	max_health += value_health;
}

void Character::equip_Weapon(int wa, std::string wn)
{
	weapon_attributes = wa;
	weapon_name = wn;
	attributes += weapon_attributes;
}

int Character::get_attributes()
{
	return 0;
}

void Character::set_attributes(const int value)
{
	attributes = value;
}

int Character::get_max_health()
{
	return max_health;
}

void Character::set_max_health(const int value)
{
	max_health = value;
}

int Character::get_current_health()
{
	return current_health;
}

void Character::set_max_health(const int value)
{
	current_health = value;
}


int Character::get_potion()
{
	return potion;
}

void Character::set_potion(const int value)
{
	potion = value;
}

int Character::get_base_damage()
{
	return base_damage;
}

void Character::set_base_damage(const int value)
{
	base_damage = value;
}

int Character::get_damage()
{
	return damage;
}

void Character::set_damage(const int value)
{
	damage = value;
}

int Character::get_weapon_attributes()
{
	return weapon_attributes;
}

void Character::set_weapon_attributes(const int value)
{
	weapon_attributes = value;
}

std::string Character::get_weapon_name()
{
	return weapon_name;
}

void Character::set_weapon_name(const std::string value)
{
	weapon_name = value;
}

std::string Character::get_name()
{
	return name;
}

void Character::set_name(const std::string value)
{
	name = value;
}


std::array<std::array<std::string, 20>, 20> Character::get_image()
{
	return image;
}
