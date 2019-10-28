#include "Monster.hpp"

namespace Domain::Game
{
	Monster::Monster()
	{
		max_health = 30;
		current_health = 30;
		base_damage = 8;
		damage = base_damage;
		monster_name = "NA";
		weapon_drop = 10;
	}

	Monster::~Monster() noexcept
	{
	}

	int Monster::get_max_health() {
		return max_health;
	}

	int Monster::get_current_health() {
		return current_health;
	}

	void Monster::set_current_health(const int value) {
		current_health = value;
	}

	int Monster::get_base_damage() {
		return base_damage;
	}

	void Monster::set_base_damage(const int value) {
		base_damage = value;
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
