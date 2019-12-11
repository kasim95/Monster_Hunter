#pragma once
#include <string>
#include <array>
#include "GameUIHandler.hpp"

namespace UI
{
	class PlayGame : public GameUIHandler
	{
	public:
		PlayGame() = default;
		PlayGame(int characterType);
		~PlayGame() noexcept override;
		double launch();				//returns score
		bool battle(int monster_type); // 1 for weak, 2 for medium, 3 for strong, 4 for dragon
	};
}
