#pragma once
#include <array>
#include "../../TechnicalServices/Payment/PaymentService.hpp"

namespace Domain::Shop
{
	struct Item
	{
		std::string id;
		std::string name;
		double price;
	};

	class Shop
	{
	private:
		std::array<Item, 1> items; //there is only one item that can be purchased as of now
		TechnicalServices::Payment::PaymentService payservice;
	public:
		Shop();
		~Shop() = default;
		bool purchase(std::string item_id);
		std::array<Item, 1> display_item();
	};
}
