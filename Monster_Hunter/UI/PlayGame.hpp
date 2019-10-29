#pragma once
#include <string>
#include <array>

#include "../Domain/Game/GameSession.hpp"
#include "../Domain/Game/Character.hpp"
#include "../TechnicalServices/Payment/PaymentService.hpp"

namespace UI
{
	class PlayGame
	{
	private:
		Domain::Game::GameSession gamesess;
		TechnicalServices::Payment::PaymentService payservice; //delete this later and implement character selection and check if purchase was made in ConsoleUI class launch method
	public:
		PlayGame();
		~PlayGame() = default;
		void launch();
		std::string takeinput();
		void disp_map();
		bool battle(int monster_type); // 1 for weak, 2 for medium, 3 for strong, 4 for dragon
		void disp_battle(int monster_type, bool char_turn); //incomplete
		void weapon_drop(int monster_type);
	};
}
