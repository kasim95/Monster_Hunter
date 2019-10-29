#include "Shop.hpp"

//need to include one more class for Records of items purchased
namespace Domain::Shop
{
	Shop::Shop()
	{
		struct Item mage;
		mage.id = "100A";
		mage.name = "Character_Mage";
		mage.price = 100;
		items[0] = mage;
	}

	bool Shop::purchase(std::string item_id)
	{
		//loop used to check if the item with the correct item_id exists
		for (int i = 0; i < size(items); ++i)
		{
			if (items[i].id == item_id)
			{
				return (payservice.purchaseItem(items[i].id));
			}
		}
		return false;
	}

	std::array<Item, 1> Shop::display_item()
	{
		return items;
	}
}
