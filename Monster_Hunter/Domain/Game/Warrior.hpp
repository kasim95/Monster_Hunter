#pragma once
#include "Character.hpp"

namespace Domain::Game
{
	class Warrior : public Domain::Game::Character
	{
	public:
		Warrior();
		void calculate_damage() override;
		~Warrior() noexcept override;
		void set_image() override;
	};

	//Inline implementation
	inline Warrior::~Warrior() noexcept
	{}

	inline Warrior::Warrior()
	{
		name = "WARRIOR";
		weapon_name = "CLAYMORE";
		attributes = 10;
		max_health = 150;
		current_health = max_health;
		potion = 3;
		base_damage = 5;
		damage = base_damage;
		weapon_attributes = 3;
	}

	inline void Warrior::calculate_damage()						//Assassin has these attributes stored so we used Information Expert to efficiently caclulate the damage.
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
}
