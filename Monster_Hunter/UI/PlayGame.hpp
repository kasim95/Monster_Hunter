#pragma once
#include <string>
#include <array>
#include "../Domain/Game/GameSessionHandler.hpp"
#include "../Domain/Game/GameSession.hpp"
#include "../Domain/Game/Character.hpp"
#include "../TechnicalServices/Payment/PaymentService.hpp"
#include "../Domain/Game/Assassin.hpp"
#include "../Domain/Game/Warrior.hpp"
#include "../Domain/Game/Mage.hpp"

namespace UI
{
	class PlayGame
	{
	public:
		PlayGame() = default;
		PlayGame(int characterType);
		~PlayGame() = default;
		double launch();				//returns score
		void disp_map();
		bool battle(int monster_type); // 1 for weak, 2 for medium, 3 for strong, 4 for dragon
		void disp_battle(int monster_type, bool char_turn); //incomplete
		void weapon_drop(int monster_type);

	private:
		Domain::Game::GameSession * gamesess;
	};
}
