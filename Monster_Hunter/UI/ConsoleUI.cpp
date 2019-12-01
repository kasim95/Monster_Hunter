 #include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <stdlib.h>
#include <vector>

#include "ConsoleUI.hpp"
#include "../Domain/AccountManagement/UserAccounts.hpp"
#include "../Domain/Menu/SessionHandler.hpp"
#include "../TechnicalServices/Logging/LoggerHandler.hpp"
#include "../TechnicalServices/Logging/SimpleLogger.hpp"
#include "../TechnicalServices/Persistence/SimpleDB.hpp"
#include "../TechnicalServices/Payment/PaymentService.hpp"
#include "PlayGame.hpp"
#include "../Domain/Game/Character.hpp"
#include "../Domain/Game/Assassin.hpp"
#include "../Domain/Game/Warrior.hpp"
#include "../Domain/Game/Mage.hpp"
#include "../Domain/Game/GameSession.hpp"
#include "../Domain/Game/CharacterCreator.hpp"

namespace UI
{
	ConsoleUI::ConsoleUI()
		: _accounts(std::make_unique<Domain::AccountManagement::UserAccounts>() ),
		_loggerPtr(std::make_unique<TechnicalServices::Logging::SimpleLogger>() ),
		_persistentData(std::make_unique<TechnicalServices::Persistence::SimpleDB>() ),
		_purchase_history(std::make_unique<TechnicalServices::Payment::PaymentService>() )
	{
		_logger << "Simple UI being used and has been successfully initialized";
	}
	

	ConsoleUI::~ConsoleUI() noexcept
	{
		_logger << "Console UI shutdown successfully";
	}

	void ConsoleUI::launch()
	{
		std::vector<std::string> roleLegalValues = _persistentData->findRoles();
		std::string selectedRole;
		std::string username;

		do 
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			char accfn;
			do
			{
				std::cout << "\n0 - Login";
				std::cout << "\n1 - Create Account";
				std::cout << "\nPick one: ";
				std::cin >> accfn;
				accfn -= 48;
			} 
			while (!(accfn == 0 || accfn == 1));			
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			if (accfn == 1)
			{
				std::cout << "\nCreate Account\n";
			}

			std::cout << "\nLogin Screen\n";
			std::string userName;
			std::cout << "Enter your username: ";
			std::getline(std::cin, userName);

			std::string passPhrase;
			std::cout << "Enter your password: ";
			std::getline(std::cin, passPhrase);

			unsigned menuSelection;
			do
			{
				for (unsigned i = 0; i != roleLegalValues.size(); ++i)
				{
					std::cout << std::setw(2) << i << " - " << roleLegalValues[i] << '\n';
				}
				std::cout << " role (0-" << roleLegalValues.size() - 1 << "): ";
				std::cin >> menuSelection;
			} while (menuSelection >= roleLegalValues.size() );

			selectedRole = roleLegalValues[menuSelection];

			if (_accounts->isAuthenticated({ userName, passPhrase, {selectedRole} }))
			{
				username = userName;
				_logger << "Login Successful for \"" + userName + "\" as role \"" + selectedRole + "\"";
				break;
			}

			std::cout << "** Login failed\n";
			_logger << "Login failure for \"" + userName + "\" as role \"" + selectedRole + "\"";
		} while (true);

		//enter menu code for play game, shop, help etc
		std::unique_ptr<Domain::Menu::SessionHandler> sessionControl = Domain::Menu::SessionHandler::createSession(selectedRole);
		std::vector<std::string> commands = sessionControl->getCommands();
		char menuSelection;
		do
		{
			for (unsigned i = 0; i < commands.size(); ++i)
			{
				std::cout << std::setw(2) << i << " - " << commands[i] << '\n';
			}
			std::cout << "  role (0-" << commands.size() - 1 << "): ";
			std::cin >> menuSelection;
			menuSelection -= 48;	//convert menuSelection to int
		} while (menuSelection >= commands.size());

		std::string selectedCommand = commands[menuSelection];
		_logger << "Selected command \"" + selectedCommand + "\" chosen";
		std::vector<double> Scores;
		if (selectedCommand == "Start Game")
		{
			_logger << "Player Selection Screen";
			
			//Implemented character selection in ConsoleUI Controller to control the overall flow of the game 
			char _character;
			int chartoint = 100;
			do
			{
				try
				{
					std::cout << "Enter Character (1-3) for Characters (1 for Assassin, 2 for Warrior, 3 for Mage): ";
					std::cin >> _character;
					chartoint = _character - 48;	//convert char to int
					if (chartoint == 3)
					{
						if (_purchase_history->findPurchaseByName(username))
						{
							break;
						}
						for (unsigned i = 0; i < _purchase_history->displayItemsforpurchase().size(); ++i)
						{
							std::cout << "Item available for purchase\n" << i << " : " << _purchase_history->displayItemsforpurchase()[i].item_name << " | Price: $9.99" << std::endl;
						}
						unsigned choice;
						std::cout << "Select the item number you want to purchase: ";
						std::cin >> choice;
						if (choice < _purchase_history->displayItemsforpurchase().size() && _purchase_history->purchaseItem(username, _purchase_history->displayItemsforpurchase()[choice].item_id)) std::cout << "Successfully purchased the item\n";
						else std::cout << "Purchase process didn't go through\n";
					}
				}
				catch (...)
				{
					chartoint = 100;
				}
			} while (!(chartoint == 1 || chartoint == 2));
			_logger << "Game Started";
			//
			/*
			UI::PlayGame * playgame;
			if (chartoint == 3) playgame = new UI::PlayGame(new Domain::Game::Mage());
			else if (chartoint == 2) playgame = new UI::PlayGame(new Domain::Game::Warrior());
			else playgame = new UI::PlayGame(new Domain::Game::Assassin());
			*/
			//
			// Character Factory Pattern
			std::string characterType;
			if (chartoint == 3) characterType = "Mage";
			else if (chartoint == 2) characterType = "Warrior";
			else if (chartoint == 1) characterType = "Assassin";
			else characterType = "Not Selected";
			Domain::Game::CharacterCreator * theCreator = Domain::Game::CharacterCreator::createCreator(characterType);
			Domain::Game::Character * theCharacter = theCreator->createCharacter();
			UI::PlayGame * playgame = new UI::PlayGame(theCharacter);
			//


			playgame->disp_map();
			double score = playgame->launch();
			Scores.push_back(score);
			if (score > 0.0) std::cout << "\nYOU WIN\nScore is " << score << std::endl << std::endl;
			else std::cout << "\nGAME OVER\nYOU LOSE\nScore is 0" << std::endl << std::endl;
			_logger << "Closing Game";
		}
		else if (selectedCommand == "Quit Game")
		{
			_logger << "Game quit";
			_Exit(10);
		}
		else if (selectedCommand == "Scores")
		{
			_logger << "Displaying Scores";
			std::cout << "Your scores history are: \n";
			for (int i = Scores.size() - 1; i >= 0; --i)
				std::cout << Scores[i] << "\n";
		}
		else if (selectedCommand == "Help")
		{
			_logger << "Displaying Help";
			//enter code to show help
			//incomplete
		}
		else;
	}
}


