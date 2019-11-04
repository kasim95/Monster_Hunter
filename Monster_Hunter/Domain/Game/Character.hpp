#pragma once
#include <string>
#include <array>
#include <iostream>

namespace Domain::Game
{
	class Character
	{
	protected:
		double attributes;
		double max_health;
		double current_health;
		int potion;
		double base_damage;
		double damage;
		double weapon_attributes;
		std::string name;
		std::array<std::array<std::string, 20>, 20> image;
		std::string weapon_name;
		Character & operator=(const Character & rhs) = default;	//Assignment operator
		Character & operator=(Character && rhs) = default;		//Move constructor can be removed later
	public:
		Character() = default;
		Character(const Character & original) = default;	//Copy const
		Character(Character && original) = default;			//Move Constructor can be removed later
		//~Character() = default;					//Virtual Destructor
		virtual ~Character() noexcept = 0;
		void equip_Weapon(double value, double value_health);
		virtual void calculate_damage() = 0;					//Virtual function that is defined in the individual character classes. Uses the Information Expert GRASP pattern.
		double get_attributes();
		void set_attributes(const double value);
		double get_max_health();
		void set_max_health(const double value);
		double get_current_health();
		void set_current_health(const double value);
		int get_potion();
		void set_potion(const int value);
		double get_base_damage();
		void set_base_damage(const double value);
		double get_damage();
		void set_damage(const double value);
		double get_weapon_attributes();
		void set_weapon_attributes(const double value);
		std::string get_weapon_name();
		void set_weapon_name(const std::string value);
		std::string get_name();
		void set_name(const std::string value);
		std::array<std::array<std::string, 20>, 20>  get_image();
		virtual void set_image() = 0;
	};
}
