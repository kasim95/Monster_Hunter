#pragma once
#include "Character.hpp"

class Warrior : public Character
{
public:
	void calculate_damage() override;
	//~Warrior() noexcept override;
	void set_image() override;
};


//Inline implementation
/*
inline Warrior::~Warrior() noexcept
{}
*/

inline void Warrior::calculate_damage()
{
	damage = base_damage + (attributes + weapon_attributes) * 2;
}

inline void Warrior::set_image()
{
	//placeholder code
	//change later once the images are finalized
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			image[i][j] = std::to_string(j);
		}
	}
}
