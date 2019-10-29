#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <stdlib.h>

#include "ConsoleUI.hpp"
#include "../Domain/AccountManagement/UserAccounts.hpp"
#include "../Domain/Menu/SessionHandler.hpp"
#include "../TechnicalServices/Logging/LoggerHandler.hpp"
#include "../TechnicalServices/Logging/SimpleLogger.hpp"
#include "../TechnicalServices/Persistence/SimpleDB.hpp"
#include "../TechnicalServices/Payment/PaymentService.hpp"
#include "../Domain/Shop/Shop.hpp"
#include "PlayGame.hpp";
#include "../Domain/Game/Character.hpp"
#include "../Domain/Game/Assassin.hpp"
#include "../Domain/Game/Warrior.hpp"
#include "../Domain/Game/Mage.hpp"

namespace UI
{
	ConsoleUI::ConsoleUI()
		: _accounts(std::make_unique<Domain::AccountManagement::UserAccounts>() ),
		_loggerPtr(std::make_unique<TechnicalServices::Logging::SimpleLogger>() ),
		_persistentData(std::make_unique<TechnicalServices::Persistence::SimpleDB>() )
		//_paymentService(std::make_unique<TechnicalServices::Payment::PaymentService>())
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
		TechnicalServices::Payment::PaymentService _purchase_history;
		Domain::Shop::Shop _item;

		
		do 
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
		//unsigned menuSelection;
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
		if (selectedCommand == "Start Game")
		{
			_logger << "Game started";
			//
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
						if (_purchase_history.findPurchaseByName(username))
						{
							break;
						}
						
						for (int i = 0; i < 1; ++i)
							std::cout << "Items available for purchase\n" << i + 1 << " : " << _item.display_item()[i].name << std::endl;

							int choice;
							std::cout << "Select the item number you want to purchase \n";
							std::cin >> choice;
							if (choice <= _item.display_item().size() && _purchase_history.purchaseItem(_item.display_item()[choice].id))
							{
								std::cout << "Successfully purchased the item\n";
							}
								std::cout << "Purchase process didn't go through\n";
						//done	
						//enter code to check if Mage is purchased
						//if yes break;
						//else display purchase options and purchase it
					}

				}
				catch (...)
				{
					chartoint = 100;
				}
			//} while (!(chartoint == 1 || chartoint == 2 || chartoint == 3));
			} while (!(chartoint == 1 || chartoint == 2));

			UI::PlayGame * playgame;
			if (chartoint == 3) playgame = new UI::PlayGame(new Domain::Game::Mage());
			else if (chartoint == 2) playgame = new UI::PlayGame(new Domain::Game::Warrior());
			else playgame = new UI::PlayGame(new Domain::Game::Assassin());
			//UI::PlayGame * playgame = new UI::PlayGame;
			playgame->disp_map();
			double score = playgame->launch();
			if (score > 0.0) std::cout << "\nYOU WIN\nScore is " << score << std::endl << std::endl;
			else std::cout << "\nGAME OVER\nYOU LOSE\nScore is 0" << std::endl << std::endl;
		}
		else if (selectedCommand == "Quit Game")
		{
			_logger << "Game quit";
			_Exit(10);
		}
		else if (selectedCommand == "Scores")
		{
			_logger << "Displaying Scores";
			//enter code to show scores
		}
		else if (selectedCommand == "Help")
		{
			_logger << "Displaying Help";
			//enter code to show help
		}
		else if (selectedCommand == "Shop")
		{
			_logger << "Shop opened";
			//discard shop
		}
		else;
	}
}


