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
		int damage;
		std::string monster_name;
		int weapon_drop;									//damage value for the weapon that the monster will drop (will be the no of attributes)
		std::array<std::array<std::string, 20>, 20> image;
		Monster & operator=(const Monster & rhs) = default; //assignment operator
		Monster & operator=(Monster && rhs) = default;

	public:
		Monster();
		Monster(const Monster & original) = default;	//copy constructor
		Monster(Monster && original) = default;
		virtual ~Monster() noexcept = 0;
		virtual void reset_monster()=0;
		int get_max_health();
		void set_max_health(const int value);
		int get_current_health();
		void set_current_health(const int value);
		void set_damage(const int value);
		int get_damage();
		std::string get_monster_name();
		void set_monster_name(const std::string value);
		int get_weapon_drop();
		void set_weapon_drop(const int value);
		std::array<std::array<std::string, 20>, 20>  get_image();
	};
}
