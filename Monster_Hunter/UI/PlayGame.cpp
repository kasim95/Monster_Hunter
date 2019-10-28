#include "PlayGame.hpp"
#include <iostream>
#include <stdio.h>
#include <conio.h>

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
			Domain::Game::Assassin z;
			Domain::Game::GameSession _gamesess(&z);
			gamesess = _gamesess;
		}
		else if (chartoint == 2)
		{
			Domain::Game::Warrior z;
			Domain::Game::GameSession _gamesess(&z);
			gamesess = _gamesess;
		}
		else
		{
			Domain::Game::Mage z;
			Domain::Game::GameSession _gamesess(&z);
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
			_input = _getch();
			_input = toupper(_input);
			if (_input == 'A') gamesess.move_character(1);
			else if (_input == 'D') gamesess.move_character(3);
			else if (_input == 'W') gamesess.move_character(4);
			else if (_input == 'S') gamesess.move_character(2);
			else if (_input == 'Z') gamesess.usePotion();
			else if (_input == 'F')
			{
				char previous_char = gamesess.get_previous_char();
				if (previous_char == 'W') gamesess.fight(1);
				else if (previous_char == 'M') gamesess.fight(2);
				else if (previous_char == 'S') gamesess.fight(3);
				else if (previous_char == 'D') gamesess.fight(4);
				else;			//do nothing
			}
			else;
		}
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
		std::cout << "\nLEGEND: @ = Character position, C = Campfire, W = Weak Monster, M = Medium Monster, S = Strong Monster, D = Dragon\n";
		std::cout << "\nCONTROLS: W - Up, S - Down, A - Left, D - Right, F - Enter Camp, Z - Use Potion\n";
	}

}
