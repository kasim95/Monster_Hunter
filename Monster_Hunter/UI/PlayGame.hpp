#pragma once
#include <string>
#include <array>

#include "../Domain/Game/GameSession.hpp"
#include "../Domain/Game/Character.hpp"

namespace UI
{
	class PlayGame
	{
	private:
		Domain::Game::GameSession gamesess;
	public:
		PlayGame();
		~PlayGame() = default;
		void launch();
		std::string takeinput();
		void disp_map();
		bool battle(int monster_type); // 1 for weak, 2 for medium, 3 for strong, 4 for dragon
		void disp_battle(bool char_turn, double char_health, double monster_health); //incomplete
		void weapon_drop(int monster_type);
	};
}
