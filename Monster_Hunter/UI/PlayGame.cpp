#include "PlayGame.hpp"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>
//conio.h does not work for Linux, Change it to curses.h, or ncurses.h 
//#include <curses.h>

#include "../Domain/Game/GameSession.hpp"

namespace UI
{
	
	PlayGame::PlayGame(int characterType)
	{
		if (characterType == 1) gamesess = new Domain::Game::GameSession("Assassin");
		else if (characterType == 2) gamesess = new Domain::Game::GameSession("Warrior");
		else if (characterType == 3) gamesess = new Domain::Game::GameSession("Mage");
		else gamesess = new Domain::Game::GameSession("Not Selected");
	}

	PlayGame::~PlayGame() noexcept
	{}

	double PlayGame::launch()
	{
		bool playeralive = true;
		bool dragonalive = true;
		while (playeralive && dragonalive)
		{
			disp_map();
			char previous_char = gamesess->get_previous_char();
			char _input;
			if (gamesess->get_player_health_percentage() < 100.0 && previous_char == 'C') //check not working properly
			{
				while (gamesess->get_player_health_percentage() < 100.0)
				{
					gamesess->heal_using_campfire(10);
					disp_map();
					std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				}
			}
			_input = _getch();			//change this to getch for linux
			_input = toupper(_input);
			if (_input == 'A') gamesess->move_character(1);
			else if (_input == 'D') gamesess->move_character(3);
			else if (_input == 'W') gamesess->move_character(4);
			else if (_input == 'S') gamesess->move_character(2);
			else if (_input == 'Z') gamesess->usePotion();
			else if (_input == 'F')
			{
				if (previous_char == 'W') battle(1);
				else if (previous_char == 'M') battle(2);
				else if (previous_char == 'S') battle(3);
				else if (previous_char == 'D') battle(4);
				else;			//do nothing
			}
			else;
			//if playerdead end
			if (!gamesess->is_player_alive()) playeralive = false;
			if (!gamesess->is_dragon_alive()) dragonalive = false;
		}
		if (playeralive == false) return 0.0;
		else if (dragonalive == false)
		{
			gamesess->end_game();
			return gamesess->calculate_score();
		}
		else return 0;
	}

	bool PlayGame::battle(int monster_type)
	{
		double player_health = gamesess->get_player_health_percentage();		
		double monster_health = gamesess->get_monster_health_percentage(monster_type);
		char _input2;

		while (gamesess->get_player_health_percentage() > 0.0 && gamesess->get_monster_health_percentage(monster_type) > 0.0)
		{
			disp_battle(monster_type, 1);
			_input2 = _getch(); //wait for user input to press attack key
			_input2 = toupper(_input2);
			if (_input2 == 'G')
			{
				gamesess->attack(monster_type, 1);
				disp_battle(monster_type, 0);
				if (gamesess->get_monster_health_percentage(monster_type) >= 0.0)
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(750));
					gamesess->attack(monster_type, 0);
					disp_battle(monster_type, 1);
				}
			}
			if (gamesess->get_monster_health_percentage(monster_type) <= 0.0)
			{
				if (monster_type != 4) weapon_drop(monster_type);
				gamesess->reset_monster(monster_type);
				return true;
			}
		}
		return false;
	}
}
