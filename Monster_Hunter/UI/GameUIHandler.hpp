#pragma once
#include <string>
#include <array>

#include "../Domain/Game/GameSessionHandler.hpp"

namespace UI
{
	class GameUIHandler
	{
	public:
		GameUIHandler() = default;
		virtual ~GameUIHandler() noexcept = 0;
		virtual double launch() = 0;				//returns score
		void disp_map();
		virtual bool battle(int monster_type) = 0; // 1 for weak, 2 for medium, 3 for strong, 4 for dragon
		void disp_battle(int monster_type, bool char_turn); //incomplete
		void weapon_drop(int monster_type);
	protected:
		Domain::Game::GameSessionHandler * gamesess;
	};

	inline GameUIHandler::~GameUIHandler() noexcept
	{}

	inline void GameUIHandler::disp_map()
	{
		std::array<std::array<std::string, 30>, 15> _map = gamesess->return_map();
		system("cls");		//to clear screen
		std::cout << "\nMONSTER HUNTER MAP\n";
		std::cout << "\nCharacter: " << gamesess->get_character_name() << std::endl;
		for (int i = 0; i < 15; ++i)
		{
			for (int j = 0; j < 30; ++j)
			{
				std::cout << _map[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << "\nRemaining Potions: " << gamesess->get_no_of_potions() << " | Player Health: " << gamesess->get_player_health_percentage() << "% | " << "Player's Attributes: " << gamesess->get_player_attributes() << std::endl;
		std::cout << "Weapon Equipped: " << gamesess->get_character_weapon_name() << " | Weapon Attributes: " << gamesess->get_character_weapon_attributes() << std::endl;
		std::cout << "Player Total Damage: " << gamesess->get_player_damage() << std::endl;
		std::cout << "\nLEGEND: @ = Character position, C = Campfire, W = Weak Monster, M = Medium Monster, S = Strong Monster, D = Dragon\n";
		std::cout << "\nCONTROLS: W - Up, S - Down, A - Left, D - Right, F - Enter Camp, Z - Use Potion\n";
	}

	inline void GameUIHandler::disp_battle(int monster_type, bool char_turn)
	{
		system("cls");
		double monster_health = gamesess->get_monster_health_percentage(monster_type);
		std::string monster_name = gamesess->get_monster_name(monster_type);
		double character_health = gamesess->get_player_health_percentage();
		std::string character_name = gamesess->get_character_name();
		std::cout << "\nPlaying Battle between " << character_name << " and " << monster_name;
		if (character_health < 0) character_health = 0.0;
		if (monster_health < 0) monster_health = 0.0;
		std::cout << "\nPlayer Health: " << character_health << std::endl;
		std::cout << "\nMonster Health: " << monster_health << std::endl;
		if (character_health > 0.0 && monster_health > 0.0)
		{
			if (char_turn) std::cout << "\nPlayer's turn to attack\n";
			else std::cout << "\nMonster's turn to attack\n";
		}
		else
		{
			if (monster_health <= 0.0) std::cout << "\nPlayer WON\n";
			else std::cout << "\n" + gamesess->get_monster_name(monster_type) + " WON\n";
		}
		std::cout << "\nCONTROLS: G - Attack\n";
	}

	inline void GameUIHandler::weapon_drop(int monster_type)
	{
		char _input3 = '_';
		std::cout << "\nWeapon dropped by monster with " << gamesess->get_weapon_drop_attributes(monster_type) << " attributes";
		while (!(_input3 == 'Y' || _input3 == 'N'))
		{
			std::cout << "\nDo you want to pick up the weapon? (Y/N): ";
			std::cin >> _input3;
			_input3 = toupper(_input3);
		}
		if (_input3 == 'Y') gamesess->equip_weapon(gamesess->get_weapon_drop_attributes(monster_type));
	}
}
