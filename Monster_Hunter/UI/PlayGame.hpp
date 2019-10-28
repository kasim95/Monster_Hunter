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
	};
}
