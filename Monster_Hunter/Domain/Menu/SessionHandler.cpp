#include <stdexcept>

#include "SessionHandler.hpp"
#include "AdminSession.hpp"
#include "PlayerSession.hpp"

namespace Domain::Menu
{
	std::unique_ptr<SessionHandler> SessionHandler::createSession(const std::string & role)
	{
		if (role == "Player") return std::make_unique<Domain::Menu::AdminSession>();
		else if (role == "Admin") return std::make_unique<Domain::Menu::PlayerSession>();
		else
		{
			throw std::logic_error("Invalid role requested in function " + std::string(__func__));
		}
	}

	SessionHandler::~SessionHandler() noexcept
	{}
}
