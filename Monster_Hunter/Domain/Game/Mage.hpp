#pragma once
#include "Character.hpp"

class Mage : public Character
{
public:
	void calculate_damage() override;
	~Mage() noexcept override;
	void set_image() override;
};


//Inline implementation
inline Mage::~Mage() noexcept
{}

inline void Mage::calculate_damage()
{
	damage = base_damage + (attributes + weapon_attributes) * 4;
}

inline void Mage::set_image()
{
	//placeholder code
	//change later once the images are finalized
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			image[i][j] = std::to_string(i*j);
		}
	}
}
