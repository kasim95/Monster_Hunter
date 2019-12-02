#pragma once
#include <memory>

#include "../Domain/AccountManagement/AccountManagementHandler.hpp"
#include "../TechnicalServices/Logging/LoggerHandler.hpp"
#include "../TechnicalServices/Persistence/PersistenceHandler.hpp"
#include "../UI/UserInterfaceHandler.hpp"
#include "../UI/PaymentUI.hpp"

namespace UI
{
	class ConsoleUI : public UI::UserInterfaceHandler
	{
	public:
		using UserInterfaceHandler::UserInterfaceHandler;
		ConsoleUI();
		void launch() override;

		~ConsoleUI() noexcept override;

	private:
		std::unique_ptr<Domain::AccountManagement::AccountManagementHandler> _accounts;
		
		std::unique_ptr<TechnicalServices::Logging::LoggerHandler> _loggerPtr;
		std::unique_ptr<TechnicalServices::Persistence::PersistenceHandler> _persistentData;

		TechnicalServices::Logging::LoggerHandler & _logger = *_loggerPtr;
		UI::PaymentUI payui;
	};
}
