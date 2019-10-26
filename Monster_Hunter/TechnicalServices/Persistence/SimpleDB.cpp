//#include "pch.h"
#include "SimpleDB.hpp"
#include "../Logging/SimpleLogger.hpp"
#include "PersistenceHandler.hpp"

namespace TechnicalServices::Persistence
{
	SimpleDB::SimpleDB()
		: _loggerPtr(std::make_unique < TechnicalServices::Logging::SimpleLogger>())
	{
		_logger << "Simple DB being used and has been successfully initialized";
	}

	SimpleDB::~SimpleDB() noexcept
	{
		_logger << "Simple DB shutdown successfully";
	}

	std::vector<std::string> SimpleDB::findRoles()
	{
		return { "Player", "Admin" };
	}

	UserCredentials SimpleDB::findCredentialsByName(const std::string & name)
	{
		static std::vector<UserCredentials> storedUsers = 
		{
			//Username, Password, Roles
			{"Kasim", "passpass", {"Player", "Admin"}},
			{"Mark", "passpass", {"Player"}},
			{"Shawn", "passpass", {"Player"}}
		};
		
		for (const auto & user : storedUsers)
		{
			if (user.userName == name)
			{
				return { user.userName, user.passPhrase, user.roles };
			}
		}

		std::string message = __func__;
		message += "attempt to find user \"" + name + "\" failed";
		throw PersistenceHandler::NoSuchuser(message);
	}

}
