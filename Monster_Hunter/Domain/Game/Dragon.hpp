#pragma once
#include "Monster.hpp"
#include <array>
#include <string>

namespace Domain::Game
{
	class Dragon : public Domain::Game::Monster
	{
	public:
		~Dragon() noexcept override;
		void set_damage() override;
		void set_image() override;
		void set_max_health() override;

	};
	//inline implementation
	inline Dragon::~Dragon() noexcept
	{
	}

	inline void Dragon::set_damage() {
		damage = base_damage * 4;
	}

	inline void Dragon::set_image() {
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

	inline void Dragon::set_max_health() {
		max_health = 30 * 4;
	}

}