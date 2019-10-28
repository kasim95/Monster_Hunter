#include "PlayGame.hpp"
#include <iostream>
#include <stdio.h>
#include <conio.h>
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
			char _input;
			disp_map();
			_input = _getch();			//change this to getch for linux
			_input = toupper(_input);
			char previous_char = gamesess.get_previous_char();
			if (gamesess.get_player_health_percentage() != 100.0 && previous_char == 'C')
			{
				gamesess.heal_using_campfire();
			}
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
		system("cls");
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
		std::cout << "\nRemaining Potions: " << gamesess.get_no_of_potions() << "\tPlayer Health: " << gamesess.get_player_health_percentage() << " % " << "Player Damage:" << gamesess.get_player_damage()  << "\n";
		std::cout << "\nLEGEND: @ = Character position, C = Campfire, W = Weak Monster, M = Medium Monster, S = Strong Monster, D = Dragon\n";
		std::cout << "\nCONTROLS: W - Up, S - Down, A - Left, D - Right, F - Enter Camp, Z - Use Potion\n";
	}

	bool PlayGame::battle(int monster_type)
	{
		double player_health = gamesess.get_player_health_percentage();
		double monster_health;
		char _input2;
		if (monster_type == 1)
		{
			monster_health = gamesess.get_weak_monster_health_percentage();
			while (player_health > 0.0 && monster_health > 0.0)
			{
				disp_battle(1, player_health, monster_health);
				_input2 = _getch(); //wait for user input to press attack key
				_input2 = toupper(_input2);
				if (_input2 == 'G')
				{
					gamesess.attack(1, 1);
					disp_battle(0, player_health, monster_health);
					gamesess.attack(1, 0);
					disp_battle(1, player_health, monster_health);
				}
				player_health = gamesess.get_player_health_percentage();
				monster_health = gamesess.get_weak_monster_health_percentage();
				if (monster_health <= 0.0)
				{
					weapon_drop(1);
					return true;
				}
			}
			return false;
		}
		else if (monster_type == 2)
		{
			monster_health = gamesess.get_medium_monster_health_percentage();
			while (player_health > 0.0 && monster_health > 0.0)
			{
				disp_battle(1, player_health, monster_health);
				_input2 = _getch(); //wait for user input to press attack key
				_input2 = toupper(_input2);
				if (_input2 == 'G')
				{
					gamesess.attack(2, 1);
					disp_battle(0, player_health, monster_health);
					gamesess.attack(2, 0);
					disp_battle(1, player_health, monster_health);
				}
				player_health = gamesess.get_player_health_percentage();
				monster_health = gamesess.get_medium_monster_health_percentage();
				if (monster_health <= 0.0)
				{
					weapon_drop(2);
					return true;
				}
			}
			return false;
		}
		else if (monster_type == 3)
		{
			monster_health = gamesess.get_strong_monster_health_percentage();
			while (player_health > 0.0 && monster_health > 0.0)
			{
				disp_battle(1, player_health, monster_health);
				_input2 = _getch(); //wait for user input to press attack key
				_input2 = toupper(_input2);
				if (_input2 == 'G')
				{
					gamesess.attack(3, 1);
					disp_battle(0, player_health, monster_health);
					gamesess.attack(3, 0);
					disp_battle(1, player_health, monster_health);
				}
				player_health = gamesess.get_player_health_percentage();
				monster_health = gamesess.get_strong_monster_health_percentage();
				if (monster_health <= 0.0)
				{
					weapon_drop(3);
					return true;
				}
			}
			return false;
		}
		else if (monster_type == 4)
		{
			monster_health = gamesess.get_dragon_monster_health_percentage();
			while (player_health > 0.0 && monster_health > 0.0)
			{
				disp_battle(1, player_health, monster_health);
				_input2 = _getch(); //wait for user input to press attack key
				_input2 = toupper(_input2);
				if (_input2 == 'G')
				{
					gamesess.attack(4, 1);
					disp_battle(0, player_health, monster_health);
					gamesess.attack(4, 0);
					disp_battle(1, player_health, monster_health);
				}
				player_health = gamesess.get_player_health_percentage();
				monster_health = gamesess.get_dragon_monster_health_percentage();
				if (monster_health <= 0.0)
				{
					return true;
				}
			}
			return false;

		}
		else return false;
	}

	void PlayGame::disp_battle(bool char_turn, double char_health, double monster_health)
	{
		system("cls");
		std::cout << "\nPlayer Health: " << char_health << std::endl;
		std::cout << "\nMonster Health: " << monster_health << std::endl;
		if (char_turn) std::cout << "\nPlayer's turn to attack\n";
		else std::cout << "\nMonster's turn to attack\n";
	}
	void PlayGame::weapon_drop(int monster_type)
	{
		std::cout << "Weapon dropped by monster with damage " << gamesess.get_weapon_drop_attributes(monster_type);
		std::cout << "\nDo you want to pick up the weapon? (Y/N)";
		char _input3;
		std::cin >> _input3;
		_input3 = toupper(_input3);
		if (_input3 == 'Y') gamesess.equip_weapon(gamesess.get_weapon_drop_attributes(1));
	}
}
