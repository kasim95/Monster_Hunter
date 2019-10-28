#include "Monster.hpp"

namespace Domain::Game
{
	Monster::Monster()
	{
		max_health = 1;
		current_health = max_health;
		damage = 8;
		monster_name = "NA";
		weapon_drop = 0;
	}

	Monster::~Monster() noexcept
	{}

	int Monster::get_max_health() {
		return max_health;
	}

	void Monster::set_max_health(const int value)
	{
		max_health = value;
	}

	int Monster::get_current_health() {
		return current_health;
	}

	void Monster::set_current_health(const int value) {
		current_health = value;
	}

	void Monster::set_damage(const int value)
	{
		damage = value;
	}

	int Monster::get_damage() {
		return damage;
	}

	std::string Monster::get_monster_name() {
		return monster_name;
	}

	void Monster::set_monster_name(const std::string value) {
		monster_name = value;
	}

	int Monster::get_weapon_drop() {
		return weapon_drop;
	}

	void Monster::set_weapon_drop(const int value) {
		weapon_drop = value;
	}

	std::array<std::array<std::string, 20>, 20> Monster::get_image() {
		return image;
	}
}
