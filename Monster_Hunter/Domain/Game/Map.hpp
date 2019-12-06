#pragma once
#include <array>

#include "MapHandler.hpp"

namespace Domain::Game
{
	class Map : public MapHandler
	{
	public:
		Map();
		~Map() noexcept override;
		void draw_map(std::array<int, 2> curr_player_pos) override;
	};
}
