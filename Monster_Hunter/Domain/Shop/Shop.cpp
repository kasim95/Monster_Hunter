//#include "pch.h"
#include "Shop.hpp"


Shop::Shop()
{
	struct Item mage;
	mage.id = "100A";
	mage.name = "Character_Mage";
	mage.price = 100;
	items[0] = mage;
}

void Shop::purchase(std::string item_id)
{
	//discard this and get this function done in technical services layer
	for (int i = 0; i < size(items); ++i)
	{
		if (items[i].id == item_id)
		{
			//enter payment google form link here
			system("open https://google.com");
		}
	}
}

std::array<Item, 1> Shop::display_item(std::string item_id)
{
	return items;
}
