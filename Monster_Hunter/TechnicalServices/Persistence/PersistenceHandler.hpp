#pragma once
#include <stdexcept>
#include <string>
#include <vector>

namespace TechnicalServices::Persistence
{
	struct UserCredentials
	{
		std::string userName;
		std::string passPhrase;
		std::vector<std::string> roles;
	};

	class PersistenceHandler
	{
	public:
		struct NoSuchuser : std::domain_error { using domain_error::domain_error; };

		PersistenceHandler() = default;
		PersistenceHandler(const PersistenceHandler & original) = default;
		PersistenceHandler(PersistenceHandler && original) = default;

		virtual std::vector<std::string> findRoles() = 0;
		virtual UserCredentials findCredentialsByName(const std::string & name) = 0;
		virtual ~PersistenceHandler() noexcept = 0;

	protected:
		PersistenceHandler & operator=(const PersistenceHandler & rhs) = default;
		PersistenceHandler & operator=(PersistenceHandler && rhs) = default;
	};


	inline PersistenceHandler::~PersistenceHandler() noexcept
	{}
}
