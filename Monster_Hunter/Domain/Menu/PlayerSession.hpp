#pragma once
#include <memory>
#include <string>
#include <vector>

#include "SessionHandler.hpp"

namespace Domain::Menu
{

	class PlayerSession : public Domain::Menu::SessionHandler
	{
	public:
		using SessionHandler::SessionHandler;
		std::vector<std::string> getCommands() override;
		~PlayerSession() noexcept override;
	};

	inline PlayerSession::~PlayerSession() noexcept
	{}

	inline std::vector<std::string> PlayerSession::getCommands()
	{
		return { "Start Game","Scores","Help","Quit Game" };
	}
}
