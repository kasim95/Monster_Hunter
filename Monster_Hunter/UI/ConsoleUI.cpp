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
#include "PlayGame.hpp";

namespace UI
{
	
	ConsoleUI::ConsoleUI()
		: _accounts(std::make_unique<Domain::AccountManagement::UserAccounts>() ),
		_loggerPtr(std::make_unique<TechnicalServices::Logging::SimpleLogger>() ),
		_persistentData(std::make_unique<TechnicalServices::Persistence::SimpleDB>() )
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
			menuSelection -= 48;
		} while (menuSelection >= commands.size());

		std::string selectedCommand = commands[menuSelection];
		_logger << "Selected command \"" + selectedCommand + "\" chosen";
		if (selectedCommand == "Start Game")
		{
			UI::PlayGame * playgame = new UI::PlayGame;
			playgame->disp_map();
			playgame->launch();
		}
		else if (selectedCommand == "Quit Game")
		{
			std::cout << "Exiting....";
			exit;
		}
		else if (selectedCommand == "Scores")
		{
			//enter code to show scores
			int y = 1;
		}
		else if (selectedCommand == "Help")
		{
			//enter code to show help
		}
		else if (selectedCommand == "Shop")
		{
			//discard shop
		}
		else;
	}
}


