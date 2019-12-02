#pragma once
#include <vector>
#include <string>
#include "../../TechnicalServices/Payment/PaymentService.hpp"

namespace Domain::Shop
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

	class ShopHandler
	{
	public:
		ShopHandler() = default;
		ShopHandler(const ShopHandler & original) = default;
		virtual bool purchaseItem(std::string _username, std::string _itemid, std::string _creditcardno, std::string _cvv) = 0;
		std::vector<item> getItems();
		bool findPurchaseByName(std::string _username);
		std::vector<user_purchases> get_shop_purchase_history();
		virtual ~ShopHandler() noexcept = 0;

	protected:
		std::vector<user_purchases> purchase_history;
		std::vector<item> _items;
		TechnicalServices::Payment::PaymentService * payservice;
		ShopHandler & operator=(const ShopHandler & rhs) = default;
		ShopHandler & operator=(ShopHandler && rhs) = default;
	};

	
	inline std::vector<item> ShopHandler::getItems()
	{
		return _items;
	}

	inline bool ShopHandler::findPurchaseByName(std::string _username)
	{
		for (unsigned i = 0; i < purchase_history.size(); ++i)
		{
			if (purchase_history[i].username == _username)
			{
				return true;
			}
		}
		return false;
	}

	inline std::vector<user_purchases> ShopHandler::get_shop_purchase_history()
	{
		return purchase_history;
	}

	inline ShopHandler::~ShopHandler() noexcept
	{}

}
