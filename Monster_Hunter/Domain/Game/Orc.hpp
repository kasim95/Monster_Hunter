#pragma once
#include "Monster.hpp"
#include <array>
#include <string>
namespace Domain::Game
{
	class Orc : public Domain::Game::Monster
	{
	public:
		Orc();
		~Orc() noexcept override;
		void reset_monster() override;
	};

	//inline implementation
	inline Orc::Orc()
	{
		max_health = 200 * 2;
		current_health = max_health;
		damage = 8 * 1.5;
		monster_name = "ORC";
		weapon_drop = 25;
		//enter code to set image
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				image[i][j] = std::to_string(j);
			}
		}
	}
	
	inline Orc::~Orc() noexcept
	{}

	inline void Orc::reset_monster()
	{
		current_health = max_health;
		weapon_drop += 2 * 2;
	}
}