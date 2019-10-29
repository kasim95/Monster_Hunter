#include "Character.hpp"

namespace Domain::Game
{
	Character::~Character() noexcept
	{}

	void Character::equip_Weapon(double value, double value_health)
	{
		weapon_attributes = value;
		max_health += value_health;
		calculate_damage();
	}

	double Character::get_attributes()
	{
		return attributes;
	}

	void Character::set_attributes(const double value)
	{
		attributes = value;
	}

	double Character::get_max_health()
	{
		return max_health;
	}

	void Character::set_max_health(const double value)
	{
		max_health = value;
	}

	double Character::get_current_health()
	{
		return current_health;
	}

	void Character::set_current_health(const double value)
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

	double Character::get_base_damage()
	{
		return base_damage;
	}

	void Character::set_base_damage(const double value)
	{
		base_damage = value;
	}

	double Character::get_damage()
	{
		return damage;
	}

	void Character::set_damage(const double value)
	{
		damage = value;
	}

	double Character::get_weapon_attributes()
	{
		return weapon_attributes;
	}

	void Character::set_weapon_attributes(const double value)
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
}
