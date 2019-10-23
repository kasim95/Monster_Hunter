#pragma once
#include <iostream>
#include <string>

class Character
{
protected:
	int attributes;
	int max_health;
	int current_health;
	int potion;
	int damage;
	int weapon_attributes;
	std::string name;
	std::string image[20][20];
	std::string weapon_name;
public:
	Character();
	~Character() = default;
	virtual void loadimage();
	void gain_Attribute(int value, int value_health);
	void equip_Weapon(int wa, std::string wn);
	bool use_Potion();
	virtual void heal_using_Campfires();
	
	int get_attributes();
	void set_attributes(const int x);
	int get_health();
	void set_health(const int x);
	int get_potion();
	void set_potion(const int x);
	int get_damage();
	void set_damage(const int x);
	int get_weapon_attributes();
	std::string** get_image();
};

