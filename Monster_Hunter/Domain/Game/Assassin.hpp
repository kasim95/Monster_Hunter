#pragma once
#include "Character.hpp"

namespace Domain::Game
{
	class Assassin : public Domain::Game::Character
	{
	public:
		Assassin();
		void calculate_damage() override;
		~Assassin() noexcept override;
		void set_image() override;
	};

	//Inline implementation
	inline Assassin::~Assassin() noexcept
	{}

	inline Assassin::Assassin()
	{
		name = "ASSASSIN";
		weapon_name = "DAGGER";
		attributes = 10;
		max_health = 100;
		current_health = max_health;
		potion = 3;
		base_damage = 10;
		damage = base_damage;
		weapon_attributes = 5;
	}

	inline void Assassin::calculate_damage()
	{
		damage = base_damage + ((attributes + weapon_attributes) * 3);
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
}
