#include "pch.h"
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

void Character::loadvars()
{
	//placeholder code for image
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			image[i][j] = std::to_string(i + j);
		}

	}


}

void Character::gain_Attribute(int value)
{
	attributes += value;
}

void Character::equip_Weapon(int wa, std::string wn)
{
	weapon_attributes = wa;
	weapon_name = wn;
	attributes += weapon_attributes;
}

bool Character::use_Potion()
{
	if (potion > 0)
	{
		potion -= 1;
		return true;
	}
	return false;
}


void Character::heal_using_Campfires()
{
	int i = 0;
	while (current_health < max_health)
	{
		current_health += max_health * 10;
		Thread.sleep(1000);
	}
}

std::string** Character::get_image()
{
	return image;
}

int Character::get_attributes()
{
	return 0;
}

void Character::set_attributes(const int x)
{
}

int Character::get_health()
{
	return 0;
}

void Character::set_health(const int x)
{
}

int Character::get_potion()
{
	return 0;
}

void Character::set_potion(const int x)
{
}

int Character::get_damage()
{
	return 0;
}

void Character::set_damage(const int x)
{
}

int Character::get_weapon_attributes()
{
	return 0;
}
