#pragma once
#include "Character.hpp"

class Assassin : public Character
{
public:
	void calculate_damage() override;
	~Assassin() noexcept override;
	void set_image() override;
};


//Inline implementation
inline Assassin::~Assassin() noexcept
{}

inline void Assassin::calculate_damage()
{
	damage = base_damage + (attributes + weapon_attributes) * 3;
}

inline void Assassin::set_image()
{
	//placeholder code
	//change later once the images are finalized
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			image[i][j] = std::to_string(i);
		}
	}
}
