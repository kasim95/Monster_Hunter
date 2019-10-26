#pragma once
#include <memory>
#include <string>
#include <vector>

#include "PersistenceHandler.hpp"
#include "../Logging/LoggerHandler.hpp"

namespace TechnicalServices::Persistence
{
	class SimpleDB : public TechnicalServices::Persistence::PersistenceHandler
	{
	public:
		using PersistenceHandler::PersistenceHandler;
		SimpleDB();

		std::vector<std::string> findRoles() override;
		UserCredentials findCredentialsByName(const std::string & name) override;
		
		~SimpleDB() noexcept override;
	
	private:
		std::unique_ptr<TechnicalServices::Logging::LoggerHandler> _loggerPtr;
		TechnicalServices::Logging::LoggerHandler & _logger = *_loggerPtr;
	};
}

