#pragma once
#include <array>
#include <ctime>
#include <memory>
#include <string>
#include "GameSessionHandler.hpp"
#include "Character.hpp"
#include "Assassin.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Monster.hpp"
#include "Goblin.hpp"
#include "Orc.hpp"
#include "Golem.hpp"
#include "Dragon.hpp"
#include "MapHandler.hpp"
#include "CharacterCreator.hpp"

namespace Domain::Game
{
	class GameSession : public Domain::Game::GameSessionHandler
	{
	public:
		GameSession() = default;
		GameSession(std::string characterName);
		~GameSession() noexcept override;
		void heal_using_campfire(double percentage) noexcept override;
		void move_character(int direction) noexcept override; //1 for left, 2 for bottom, 3 for right, 4 for top
		void attack(int monster_type, bool char_turn) noexcept override; //incomplete
	};
}
