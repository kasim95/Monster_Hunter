#pragma once
#include "Monster.hpp"
#include <array>
#include <string>

namespace Domain::Game
{
	class Goblin : public Domain::Game::Monster
		{
		public:
			~Goblin() noexcept override;
			void reset_monster() override;
		};
	//inline implementation
	inline Goblin::~Goblin() noexcept
	{}

	inline void Goblin::reset_monster()
	{
		max_health = 30 * 1;
		current_health = max_health;
		damage = 6 * 1;
		monster_name = "GOBLIN";
		weapon_drop = 10 * 1;
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