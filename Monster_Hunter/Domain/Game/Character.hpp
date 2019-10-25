#pragma once
#include <string>
#include <array>
#include <iostream>

class Character
{
protected:
	int attributes;
	int max_health;
	int current_health;
	int potion;
	int base_damage;
	int damage;
	int weapon_attributes;
	std::string name;
	std::array<std::array<std::string, 20>, 20> image;
	std::string weapon_name;
	Character & operator=(const Character & rhs) = default;	//Assignment operator
	Character & operator=(Character && rhs) = default;		//Move constructor can be removed later
public:
	Character();
	Character(const Character & original) = default;	//Copy const
	Character(Character && original) = default;			//Move Constructor can be removed later
	~Character() = default;					//Virtual Destructor
	void gain_Attribute(int value, int value_health);
	void equip_Weapon(int wa, std::string wn);
	virtual void calculate_damage() = 0;
	int get_attributes();
	void set_attributes(const int value);
	int get_max_health();
	void set_max_health(const int value);
	int get_current_health();
	void set_current_health(const int value);
	int get_potion();
	void set_potion(const int value);
	int get_base_damage();
	void set_base_damage(const int value);
	int get_damage();
	void set_damage(const int value);
	int get_weapon_attributes();
	void set_weapon_attributes(const int value);
	std::string get_weapon_name();
	void set_weapon_name(const std::string value);
	std::string get_name();
	void set_name(const std::string value);
	std::array<std::array<std::string, 20>, 20>  get_image();
	virtual void set_image() = 0;
};
