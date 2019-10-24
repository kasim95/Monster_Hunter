#pragma once
#include <array>
#include "Character.hpp"
#include "Assassin.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Goblin.hpp"
#include "Orc.hpp"
#include "Golem.hpp"
#include "Dragon.hpp"

class GameSession
{
private:
	std::array<int, 2> player_position;
	Character* player_character;
	//Goblin weak_monster;
	//Orc medium_monster;
	//Golem strong_monster;
	//Dragon dragon_monster;

public:
	GameSession();
	~GameSession();
	bool usePotion();
	void heal_using_campfire();
};
