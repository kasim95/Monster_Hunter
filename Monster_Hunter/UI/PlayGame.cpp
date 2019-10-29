#include "PlayGame.hpp"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>
//conio.h does not work for Linux, Change it to curses.h, or ncurses.h 
//#include <curses.h>
namespace UI
{
	PlayGame::PlayGame()
	{
		char _character;
		int chartoint = 100;
		do
		{
			try
			{
				std::cout << "Enter Character (1-3) for Characters (1 for Assassin, 2 for Warrior, 3 for Mage): ";
				std::cin >> _character;
				chartoint = _character - 48;	//convert char to int
			}
			catch (...)
			{
				chartoint = 100;
			}	
		} while (!(chartoint == 1 || chartoint == 2 || chartoint == 3));

		if (chartoint == 1)
		{
			Domain::Game::Assassin * z = new Domain::Game::Assassin();
			Domain::Game::GameSession _gamesess(z);
			gamesess = _gamesess;
		}
		else if (chartoint == 2)
		{
			Domain::Game::Warrior * z = new Domain::Game::Warrior;
			Domain::Game::GameSession _gamesess(z);
			gamesess = _gamesess;
		}
		else
		{
			Domain::Game::Mage * z = new Domain::Game::Mage;
			Domain::Game::GameSession _gamesess(z);
			gamesess = _gamesess;
		}
	}
	
	void PlayGame::launch()
	{
		bool playeralive = true;
		bool dragonalive = true;
		while (playeralive && dragonalive)
		{
			disp_map();
			char previous_char = gamesess.get_previous_char();
			char _input;
			if (gamesess.get_player_health_percentage() < 100.0 && previous_char == 'C') //check not working properly
			{
				while (gamesess.get_player_health_percentage() < 100.0)
				{
					gamesess.heal_using_campfire(10);
					disp_map();
					std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				}
			}
			_input = _getch();			//change this to getch for linux
			_input = toupper(_input);
			if (_input == 'A') gamesess.move_character(1);
			else if (_input == 'D') gamesess.move_character(3);
			else if (_input == 'W') gamesess.move_character(4);
			else if (_input == 'S') gamesess.move_character(2);
			else if (_input == 'Z') gamesess.usePotion();
			else if (_input == 'F')
			{
				if (previous_char == 'W') battle(1);
				else if (previous_char == 'M') battle(2);
				else if (previous_char == 'S') battle(3);
				else if (previous_char == 'D') battle(4);
				else;			//do nothing
				gamesess.reset_all_monsters();
			}
			else;
			//if playerdead end
			if (!gamesess.is_player_alive()) playeralive = false;
			if (!gamesess.is_dragon_alive()) dragonalive = false;
		}
		if (playeralive == false) std::cout << "\nGAME OVER";
		if (dragonalive == false) std::cout << "\nYOU WIN";
		gamesess.end_game();
		std::cout << "\nScore is: " << gamesess.calculate_score();			
	}

	std::string PlayGame::takeinput()
	{
		char _input;
		//wait for user input
		std::cin >> _input;
		return std::string();
	}

	void PlayGame::disp_map()
	{
		std::array<std::array<std::string, 30>, 15> _map = gamesess.return_map();
		system("cls");		//to clear screen
		std::cout << "\nMONSTER HUNTER MAP\n";
		for (int i = 0; i < 15; ++i)
		{
			for (int j = 0; j < 30; ++j)
			{
				std::cout << _map[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << "\nRemaining Potions: " << gamesess.get_no_of_potions() << " | Player Health: " << gamesess.get_player_health_percentage() << "% | " << "Player's Attributes: " << gamesess.get_player_attributes() << " | Player Damage: " << gamesess.get_player_damage()  << "\n";
		std::cout << "\nLEGEND: @ = Character position, C = Campfire, W = Weak Monster, M = Medium Monster, S = Strong Monster, D = Dragon\n";
		std::cout << "\nCONTROLS: W - Up, S - Down, A - Left, D - Right, F - Enter Camp, Z - Use Potion\n";
	}

	bool PlayGame::battle(int monster_type)
	{
		double player_health = gamesess.get_player_health_percentage();		
		double monster_health = gamesess.get_monster_health_percentage(monster_type);
		char _input2;

		while (gamesess.get_player_health_percentage() > 0.0 && gamesess.get_monster_health_percentage(monster_type) > 0.0)
		{
			disp_battle(monster_type, 1);
			_input2 = _getch(); //wait for user input to press attack key
			_input2 = toupper(_input2);
			if (_input2 == 'G')
			{
				gamesess.attack(monster_type, 1);
				disp_battle(monster_type, 0);
				if (gamesess.get_monster_health_percentage(monster_type) >= 0.0)
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(750));
					gamesess.attack(monster_type, 0);
					disp_battle(monster_type, 1);
				}
			}
			if (gamesess.get_monster_health_percentage(monster_type) <= 0.0)
			{
				if (monster_type != 4) weapon_drop(monster_type);
				return true;
			}
		}
		return false;
	}

	void PlayGame::disp_battle(int monster_type, bool char_turn)
	{
		system("cls");
		double monster_health = gamesess.get_monster_health_percentage(monster_type);
		std::string monster_name = gamesess.get_monster_name(monster_type);
		double character_health = gamesess.get_player_health_percentage();
		std::string character_name = gamesess.get_character_name();
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
			else std::cout << "\nMonster WON\n";
		}
		std::cout << "\nCONTROLS: G - Attack\n";
	}

	void PlayGame::weapon_drop(int monster_type)
	{
		std::cout << "\nWeapon dropped by monster with " << gamesess.get_weapon_drop_attributes(monster_type) << " attributes";
		std::cout << "\nDo you want to pick up the weapon? (Y/N): ";
		char _input3;
		std::cin >> _input3;
		_input3 = toupper(_input3);
		if (_input3 == 'Y') gamesess.equip_weapon(gamesess.get_weapon_drop_attributes(1));
	}
}
