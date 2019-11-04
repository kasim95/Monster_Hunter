#pragma once
#include "Character.hpp"

namespace Domain::Game
{
	class Mage : public Domain::Game::Character
	{
	public:
		Mage();
		void calculate_damage() override;
		~Mage() noexcept override;
		void set_image() override;
	};

	//Inline implementation
	inline Mage::~Mage() noexcept
	{}

	inline Mage::Mage()
	{
		name = "MAGE";
		weapon_name = "STAFF";
		attributes = 10;
		max_health = 80;
		current_health = max_health;
		potion = 3;
		base_damage = 20;
		damage = base_damage;
		weapon_attributes = 10;
	}

	inline void Mage::calculate_damage()						//Assassin has these attributes stored so we used Information Expert to efficiently caclulate the damage.
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
}
