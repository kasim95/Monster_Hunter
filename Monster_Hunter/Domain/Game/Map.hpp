#pragma once
#include <array>

class Map
{
private:
	std::array<std::array<std::string, 30>, 15> _map;
	std::string previous_char;
	std::array<int, 2> previous_char_pos;
public:
	Map();
	~Map() = default;
	void draw_map(std::array<int, 2> curr_player_pos);
	std::array<int, 2> get_previous_char_pos();
	void set_previous_char_pos(std::array<int, 2> value);
	std::array<std::array<std::string, 30>, 15> get_map();
};
