#pragma once
#include "Monster.hpp"
#include <array>
#include <string>

namespace Domain::Game
{
	class Golem : public Domain::Game::Monster
	{
	public:
		Golem();
		~Golem() noexcept override;
		void reset_monster() override;
	};

	//inline implementation
	inline Golem::Golem()
	{
		max_health = 200 * 3;
		current_health = max_health;
		damage = 8 * 3;
		monster_name = "GOLEM";
		weapon_drop = 40;
		//enter code to set image
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				image[i][j] = std::to_string(j);
			}
		}
	}
	
	inline Golem::~Golem() noexcept
	{}

	inline void Golem::reset_monster()
	{
		current_health = max_health;
		weapon_drop += 2 * 3;
	}
}
