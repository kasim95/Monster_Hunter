#pragma once
#include <string>
#include <array>

namespace Domain::Game
{
	class Monster
	{
	protected:
		double max_health;
		double current_health;
		double damage;
		std::string monster_name;
		double weapon_drop;									//damage value for the weapon that the monster will drop (will be the no of attributes)
		std::array<std::array<std::string, 20>, 20> image;
		Monster & operator=(const Monster & rhs) = default; //assignment operator
		Monster & operator=(Monster && rhs) = default;

	public:
		Monster() = default;
		Monster(const Monster & original) = default;	//copy constructor
		Monster(Monster && original) = default;
		virtual ~Monster() noexcept = 0;
		virtual void reset_monster()=0;
		double get_max_health();
		void set_max_health(const double value);
		double get_current_health();
		void set_current_health(const double value);
		double get_damage();
		void set_damage(const double value);
		std::string get_monster_name();
		void set_monster_name(const std::string value);
		double get_weapon_drop();
		void set_weapon_drop(const double value);
		std::array<std::array<std::string, 20>, 20>  get_image();
	};
}
