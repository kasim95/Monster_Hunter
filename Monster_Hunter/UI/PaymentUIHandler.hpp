#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "../Domain/Shop/ShopHandler.hpp"

namespace UI
{
	class PaymentUIHandler
	{
	public:
		PaymentUIHandler() = default;
		virtual ~PaymentUIHandler() noexcept;
		virtual bool purchaseItem(std::string _username, std::string _itemid) = 0;
		bool findexistingPurchase(std::string _username);
		void displayItems(std::string _username);
	protected:
		Domain::Shop::ShopHandler * shop;
	};

	inline PaymentUIHandler::~PaymentUIHandler() noexcept
	{}

	inline bool PaymentUIHandler::findexistingPurchase(std::string _username)
	{
		return shop->findPurchaseByName(_username);
	}

	inline void PaymentUIHandler::displayItems(std::string _username)
	{
		std::vector<Domain::Shop::item> items = shop->getItems();
		for (unsigned i = 0; i < items.size(); ++i)
		{
			std::cout << "Item available for purchase\n" << i << " : " << items[i].item_name << " | Price: $9.99" << std::endl;
		}
		unsigned choice;
		std::cout << "Select the item number you want to purchase: ";
		std::cin >> choice;
		if (purchaseItem(_username, items[choice].item_id)) std::cout << "Successfully purchased the item\n";
		else std::cout << "Purchase process didn't go through\n";
	}
}
