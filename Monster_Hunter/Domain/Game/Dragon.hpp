#pragma once
#include "Monster.hpp"
#include <array>
#include <string>

namespace Domain::Game
{
	class Dragon : public Domain::Game::Monster
	{
	public:
		Dragon();
		~Dragon() noexcept override;
		void reset_monster() override;
	};

	//inline implementation
	inline Dragon::Dragon()
	{
		max_health = 200 * 10;
		current_health = max_health;
		damage = 8 * 6;
		monster_name = "DRAGON";
		weapon_drop = 0;
		//enter code to set image
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				image[i][j] = std::to_string(j);
			}
		}
	}
	
	inline Dragon::~Dragon() noexcept
	{}

	inline void Dragon::reset_monster()
	{
		current_health = max_health;
	}
}