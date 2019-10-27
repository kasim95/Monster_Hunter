#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>

#include "ConsoleUI.hpp"
#include "../Domain/AccountManagement/UserAccounts.hpp"
#include "../Domain/Game/GameSession.hpp"
#include "../TechnicalServices/Logging/LoggerHandler.hpp"
#include "../TechnicalServices/Logging/SimpleLogger.hpp"
#include "../TechnicalServices/Persistence/SimpleDB.hpp"

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
			std::cout << " Enter you  username: ";
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

	}


}


