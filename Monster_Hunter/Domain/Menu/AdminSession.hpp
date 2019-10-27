#pragma once
#include <memory>
#include <string>
#include <vector>

#include "SessionHandler.hpp"

namespace Domain::Menu
{
	class AdminSession :public Domain::Menu::SessionHandler
	{
	public:
		using SessionHandler::SessionHandler;
		std::vector<std::string> getCommands() override;
		virtual ~AdminSession() noexcept override;
	};

	inline std::vector<std::string> AdminSession::getCommands()
	{
		return { "Delete Account, Rename Account", "Reset Scores" };
	}

	inline AdminSession::~AdminSession() noexcept
	{}
}
