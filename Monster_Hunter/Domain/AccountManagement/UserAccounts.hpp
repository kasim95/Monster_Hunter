#pragma once
#include <memory>
#include <string>

#include "AccountManagementHandler.hpp"
#include "../../TechnicalServices/Logging/LoggerHandler.hpp"
#include "../../TechnicalServices/Persistence/PersistenceHandler.hpp"

namespace Domain::AccountManagement
{
	class UserAccounts :public AccountManagementHandler
	{
	public:
		using AccountManagementHandler::AccountManagementHandler;
		UserAccounts();
		bool isAuthenticated(const UserCredentials & credentials) override;
		~UserAccounts() noexcept override;

	private:
		std::unique_ptr<TechnicalServices::Persistence::PersistenceHandler> _perssistentData;
		std::unique_ptr <TechnicalServices::Logging::LoggerHandler> _loggerPtr;

		TechnicalServices::Logging::LoggerHandler & _logger = *_loggerPtr;
	};
}
