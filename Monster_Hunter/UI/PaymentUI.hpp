#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "../Domain/Shop/ShopHandler.hpp"
#include "../Domain/Shop/ShopMenu.hpp"

namespace UI
{
	class PaymentUI
	{
	public:
		PaymentUI();
		~PaymentUI() = default;
		bool purchaseItem(std::string _username, std::string _itemid);
		bool findexistingPurchase(std::string _username);
		void displayItems(std::string _username);
	private:
		Domain::Shop::ShopHandler * shop;
	};

	inline PaymentUI::PaymentUI()
	{
		Domain::Shop::ShopHandler * _shop = new Domain::Shop::ShopMenu();
		shop = _shop;
	}


	inline bool PaymentUI::purchaseItem(std::string _username, std::string _itemid)
	{
		try
		{
			std::vector<Domain::Shop::user_purchases> purchase_history = shop->get_shop_purchase_history();
			char creditcardno[11];
			char cvv[4];
			for (unsigned i = 0; i < purchase_history.size(); ++i)
			{
				if (purchase_history[i].username == _username)
				{
					return true;
				}
			}
			std::cout << "\n*************************\n";
			std::cout << "CSUF Payment Service\n";
			std::cout << "\nEnter your credit card no: ";
			std::cin.ignore();
			std::cin.getline(creditcardno, 11);
			std::string _creditcardno(creditcardno);
			std::cout << "\nEnter CVV code: ";
			std::cin.getline(cvv, 4);
			std::string _cvv(cvv);
			if (shop->purchaseItem(_username, _itemid, _creditcardno, _cvv))
			{
				std::cout << "\nPayment Confirmed. Enjoy your purchase\n";
				std::cout << "*************************\n";
				return true;
			}
			std::cout << "\nPayment Failed\n";
			std::cout << "*************************\n";
			return false;
		}
		catch (...)
		{
			return false;
		}
	}
	inline bool PaymentUI::findexistingPurchase(std::string _username)
	{
		return shop->findPurchaseByName(_username);
	}
	inline void PaymentUI::displayItems(std::string _username)
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
