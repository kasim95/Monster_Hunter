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
#include "TechnicalServices/Payment/PaymentService.hpp"
#include "UI/PlayGame.hpp"
#include "UI/ConsoleUI.hpp"
#include "Domain/Game/CharacterCreator.hpp"

void test_map()
{
	Domain::Game::Map z;
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
	Domain::Game::Assassin assassin;
	std::cout << "\nAssassin's Base Damage is " << assassin.get_damage();
	assassin.calculate_damage();
	std::cout << "\nAssassin's Damage is " << assassin.get_damage();
}

void test_warrior()
{
	Domain::Game::Warrior warrior;
	std::cout << "\nWarrior's Base Damage is " << warrior.get_damage();
	warrior.calculate_damage();
	std::cout << "\nWarrior's Damage is " << warrior.get_damage();
}

void test_mage()
{
	Domain::Game::Mage mage;
	std::cout << "\nMage's Base Damage is " << mage.get_damage();
	mage.calculate_damage();
	std::cout << "\nMage's Damage is " << mage.get_damage();
}

void test_gamesession_move_character()
{
	std::array<std::array<std::string, 30>, 15> _map;
	Domain::Game::GameSession gamesess;
	//std::cout << gamesess.usePotion();
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

void test_gamesession_select_character()
{
	Domain::Game::Warrior warrior;
	Domain::Game::GameSession gamesess("Warrior");
}

void test_game_equip_weapon()
{
	//this test was failing for default constructor of GameSession -FIXED
	std::cout << "\n\nDefault constructor";
	Domain::Game::GameSession gamesess;
	std::cout << "\nearlier damage is " << gamesess.get_player_damage();
	gamesess.equip_weapon(100);
	std::cout << "\nequipped weapon damage is " << gamesess.get_player_damage();
	
	std::cout << "\n\nSelect character constructor";
	//Domain::Game::Mage warr;
	Domain::Game::GameSession gamesess1("Warrior");
	std::cout << "\nearlier damage is " << gamesess1.get_player_damage();
	gamesess1.equip_weapon(100);
	std::cout << "\nequipped weapon damage is " << gamesess1.get_player_damage();


}

void test_payment_handler()
{
	std::cout << "Payment Handler test\n";
	TechnicalServices::Payment::PaymentService payservice;
	std::cout << payservice.findPurchaseByName("Kasim") << std::endl;
	std::cout << payservice.purchaseItem("Kasim","100A") << std::endl;
}


void test_play_game()
{

	//Domain::Game::Character * _char = new Domain::Game::Assassin();
	UI::PlayGame playgame(1);
	playgame.disp_map();
	std::cout << playgame.launch();
}


void test_console_ui()
{
	UI::ConsoleUI consoleui;
	consoleui.launch();
}

void test_factory_pattern()
{
	Domain::Game::CharacterCreator * theCreator = Domain::Game::CharacterCreator::createCreator("Warrior");
	Domain::Game::Character * newCharacter = theCreator->createCharacter();
	std::cout << "Character's name is " << newCharacter->get_name() << std::endl;
}

int main()
{
//    std::cout << "Hello World!\n"; 
//	test_map();
//	test_assassin();
//	test_warrior();
//	test_mage();
//	test_gamesession_move_character();
//	test_gamesession_select_character();
//	test_game_equip_weapon();
//	test_payment_handler();
//	test_play_game();
	test_console_ui();
//	test_factory_pattern();
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
