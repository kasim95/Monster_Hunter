#pragma once
#include "Monster.hpp"
#include <array>
#include <string>

namespace Domain::Game
{
	class Golem : public Domain::Game::Monster
	{
	public:
		~Golem() noexcept override;
		void reset_monster() override;
	};
	//inline implementation
	inline Golem::~Golem() noexcept
	{}

	inline void Golem::reset_monster()
	{
		max_health = 200 * 3;
		current_health = max_health;
		damage = 6 * 3;
		monster_name = "GOLEM";
		weapon_drop = 10 * 3;
		//enter code to set image
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				image[i][j] = std::to_string(j);
			}
		}
	}
}
