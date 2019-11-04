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
	struct item
	{
		std::string item_id;
		std::string item_name;
	};

	class PaymentService
	{
	private:
		std::vector<user_purchases> purchase_history;
		std::vector<item> _items;
	public:
		PaymentService();
		~PaymentService() = default;
		bool purchaseItem(std::string _username,std::string _itemid);
		bool findPurchaseByName(std::string _username);
		bool verifypaymentdetails(std::string username, std::string credicardno, std::string cvv);
		bool getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs);
		std::vector<item> displayItemsforpurchase(); //low coupling/high cohesion GRASP is used in here. We discarded shop class and move displayitem function to here.
	};
}
