#include "ShopMenu.hpp"

#include "../../TechnicalServices/Payment/VisaPaymentService.hpp"
// #include "../../TechnicalServices/Payment/MastercardPaymentService.hpp"


namespace Domain::Shop
{
	inline ShopMenu::~ShopMenu() noexcept
	{}

	ShopMenu::ShopMenu()
	{
		payservice = new TechnicalServices::Payment::VisaPaymentService();
		_items = {
			{"100A", "Character_Mage"}
		};

		purchase_history = {
			{"Kasim", "100A"}
		};
	}

	bool ShopMenu::purchaseItem(std::string _username, std::string _itemid, std::string _creditcardno, std::string _cvv)
	{
		try
		{
			if (payservice->verifypaymentdetails(_username, _creditcardno, _cvv))
			{
				purchase_history.push_back({ _username, _itemid });
				return true;
			}
		}
		catch (...)
		{
			return false;
		}
		return false;
	}
}
