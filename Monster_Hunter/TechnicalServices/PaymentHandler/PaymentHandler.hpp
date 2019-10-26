#pragma once
#include <vector>
#include <iostream>
#include <string>

struct user_purchases
{
	std::string username;
	std::string item_id;
};

class PaymentHandler
{
private:
	std::vector<user_purchases> purchase_history;
public:
	PaymentHandler();
	~PaymentHandler() = default;
	bool purchaseItem(std::string _itemid);
	bool findPurchaseByName(std::string _username);
	bool verifypaymentdetails(std::string username, std::string credicardno, std::string cvv);
};
