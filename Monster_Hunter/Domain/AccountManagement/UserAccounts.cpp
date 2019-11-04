#include <algorithm>
#include <memory>

#include "UserAccounts.hpp"
#include "../../TechnicalServices/Logging/SimpleLogger.hpp"
#include "../../TechnicalServices/Persistence/SimpleDB.hpp"

namespace Domain::AccountManagement
{
	UserAccounts::UserAccounts()
		: _perssistentData(std::make_unique<TechnicalServices::Persistence::SimpleDB>()),
		_loggerPtr(std::make_unique < TechnicalServices::Logging::SimpleLogger>())
	{
		_logger << "UserAccounts being used and has been successfully initialized";
	}
	
	UserAccounts::~UserAccounts() noexcept
	{
		_logger << "UserAccounts shutdown successfully";
	}

	bool UserAccounts::isAuthenticated(const UserCredentials & credentials)
	{
		try
		{
			UserCredentials credentialsFromDB = _perssistentData->findCredentialsByName(credentials.userName);
			if (credentials.userName == credentialsFromDB.userName
				&& credentials.passPhrase == credentialsFromDB.passPhrase
				&& std::any_of(credentialsFromDB.roles.cbegin(), credentialsFromDB.roles.cend(),
					[&](const std::string & role) { return credentials.roles.size() > 0 && credentials.roles[0] == role; }
					)
				) return true;
		}
		catch(const TechnicalServices::Persistence::PersistenceHandler::NoSuchuser &) {}
		return false;
	}
}
 