#pragma once
#include <vector>
#include <iostream>
#include <string>

namespace TechnicalServices::Payment
{
	struct user_purchases
	{
		std::string username;
		std::string item_id;
	};

	class PaymentService
	{
	private:
		std::vector<user_purchases> purchase_history;
	public:
		PaymentService();
		~PaymentService() = default;
		bool purchaseItem(std::string _itemid);
		bool findPurchaseByName(std::string _username);
		bool verifypaymentdetails(std::string username, std::string credicardno, std::string cvv);
	};
}

