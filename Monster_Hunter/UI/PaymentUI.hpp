#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "PaymentUIHandler.hpp"
#include "../Domain/Shop/ShopMenu.hpp"

namespace UI
{
	class PaymentUI : public PaymentUIHandler
	{
	public:
		PaymentUI();
		~PaymentUI() noexcept override;
		bool purchaseItem(std::string _username, std::string _itemid) override;
	};

	inline PaymentUI::PaymentUI()
	{
		shop = new Domain::Shop::ShopMenu();
	}

	inline PaymentUI::~PaymentUI() noexcept
	{}

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
			std::cout << "Monster Hunter Payment Service\n";
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
}
