#pragma once
#include "ShopHandler.hpp"
#include "../../TechnicalServices/Payment/PaymentServiceHandler.hpp"

namespace Domain::Shop
{
	
	class ShopMenu : public Domain::Shop::ShopHandler
	{
	public:
		ShopMenu();
		virtual bool purchaseItem(std::string _username, std::string _itemid, std::string _creditcardno, std::string _cvv) override;
		~ShopMenu() noexcept override;
	};

}
