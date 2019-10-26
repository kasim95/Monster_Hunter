#pragma once
#include <array>
#include "Item.hpp"

class Shop
{
private:
	std::array<Item, 1> items;
public:
	Shop();
	~Shop() = default;
	void purchase(std::string item_id);
	std::array<Item, 1> display_item(std::string item_id);
};

