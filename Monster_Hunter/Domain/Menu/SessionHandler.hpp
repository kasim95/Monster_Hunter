#pragma once
#include <memory>
#include <string>
#include <vector>

namespace Domain::Menu
{
	class SessionHandler
	{
	public:
		SessionHandler() =  default;
		SessionHandler(const SessionHandler & original) = default;
		SessionHandler(SessionHandler && original) = default;
		virtual std::vector<std::string> getCommands() = 0;
		static std::unique_ptr<SessionHandler> createSession(const std::string & role);

		virtual ~SessionHandler() noexcept = 0;

	protected:
		SessionHandler & operator=(const SessionHandler & rhs) = default;
		SessionHandler & operator=(SessionHandler && rhs) = default;
	};

}


