#pragma once
#include <string>
#include <array>

namespace Domain::Game
{
	class Monster
	{
	protected:
		int max_health;
		int current_health;
		int base_damage;
		int damage;
		std::string monster_name;
		int weapon_drop;									//damage value for the weapon that the monster will drop
		std::array<std::array<std::string, 20>, 20> image;
		Monster & operator=(const Monster & rhs) = default; //assignment operator
		Monster & operator=(Monster && rhs) = default;

	public:
		Monster();
		Monster(const Monster & original) = default;	//copy constructor
		Monster(Monster && original) = default;
		//~Monster() = default;
		virtual ~Monster() noexcept = 0;

		virtual void set_damage() = 0;
		virtual void set_image() = 0;
		virtual void set_max_health() = 0;

		int get_max_health();
		int get_current_health();
		void set_current_health(const int value);
		int get_base_damage();
		void set_base_damage(const int value);
		int get_damage();
		std::string get_monster_name();
		void set_monster_name(const std::string value);
		int get_weapon_drop();
		void set_weapon_drop(const int value);
		std::array<std::array<std::string, 20>, 20>  get_image();

	};
}
