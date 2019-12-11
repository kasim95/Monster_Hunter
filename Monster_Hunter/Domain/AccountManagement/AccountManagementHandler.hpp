#pragma once
#include <string>
#include "../../TechnicalServices/Persistence/PersistenceHandler.hpp"


namespace Domain::AccountManagement
{
	using TechnicalServices::Persistence::UserCredentials;
	class AccountManagementHandler
	{
	public:
		AccountManagementHandler() = default;
		AccountManagementHandler(const AccountManagementHandler & original) = default;
		AccountManagementHandler(AccountManagementHandler && original) = default;
		virtual ~AccountManagementHandler() noexcept = 0;
		
		virtual bool isAuthenticated(const UserCredentials & credentials) = 0;				// Controller GRASP pattern handles login responsibility
	
	protected:
		AccountManagementHandler & operator=(const AccountManagementHandler & rhs) = default;
		AccountManagementHandler & operator=(AccountManagementHandler && rhs) = default;

	};

	inline AccountManagementHandler::~AccountManagementHandler() noexcept
	{}
}
