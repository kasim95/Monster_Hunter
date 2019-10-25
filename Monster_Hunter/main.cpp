// Monster_Hunter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <array>
#include <string>
#include "Domain/Game/Map.hpp"
#include "Domain/Game/Assassin.hpp"
#include "Domain/Game/Warrior.hpp"
#include "Domain/Game/Mage.hpp"
#include "Domain/Game/GameSession.hpp"

void test_map()
{
	Map z;
	std::array<std::array<std::string, 30>, 15> _map = z.get_map();
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			std::cout << _map[i][j];
		}
		std::cout << std::endl;
	}
}

void test_assassin()
{
	Assassin assassin;
	std::cout << "\nAssassin's Base Damage is " << assassin.get_damage();
	assassin.calculate_damage();
	std::cout << "\nAssassin's Damage is " << assassin.get_damage();
}

void test_warrior()
{
	Warrior warrior;
	std::cout << "\nWarrior's Base Damage is " << warrior.get_damage();
	warrior.calculate_damage();
	std::cout << "\nWarrior's Damage is " << warrior.get_damage();
}

void test_mage()
{
	Mage mage;
	std::cout << "\nMage's Base Damage is " << mage.get_damage();
	mage.calculate_damage();
	std::cout << "\nMage's Damage is " << mage.get_damage();
}

void test_gamesession_move_character()
{
	std::array<std::array<std::string, 30>, 15> _map;
	GameSession gamesess;
	//std::cout << gamesess.usePotion();
	int x = 0;
	//move right twice
	std::cout << "\n\n\nmoving right twice\n";
	gamesess.move_character(3);
	gamesess.move_character(3);
	_map = gamesess.return_map();
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			std::cout << _map[i][j];
		}
		std::cout << std::endl;
	}

	//move left once
	std::cout << "\n\n\nmoving left once\n";
	gamesess.move_character(1);
	_map = gamesess.return_map();
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			std::cout << _map[i][j];
		}
		std::cout << std::endl;
	}
	
	//move top 15 times
	std::cout << "\n\n\nmoving top 15 times\n";
	gamesess.move_character(4);
	gamesess.move_character(4);
	gamesess.move_character(4);
	gamesess.move_character(4);
	gamesess.move_character(4);
	gamesess.move_character(4);
	gamesess.move_character(4);
	gamesess.move_character(4);
	gamesess.move_character(4);
	gamesess.move_character(4);
	gamesess.move_character(4);
	gamesess.move_character(4);
	gamesess.move_character(4);
	gamesess.move_character(4);
	gamesess.move_character(4);

	_map = gamesess.return_map();
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			std::cout << _map[i][j];
		}
		std::cout << std::endl;
	}

	//move bottom once
	std::cout << "\n\nmoving bottom once\n";
	gamesess.move_character(2);
	_map = gamesess.return_map();
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			std::cout << _map[i][j];
		}
		std::cout << std::endl;
	}
	
}


int main()
{
    std::cout << "Hello World!\n"; 
//	test_map();
//	test_assassin();
//	test_warrior();
//	test_mage();
	test_gamesession_move_character();
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
