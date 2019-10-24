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
	std::array<std::array<std::string, 30>, 15> get_map();
};

inline Map::Map()
{
	//dots
	for (int i = 0; i <= 15; ++i)
	{
		for (int j = 0; j <= 30; ++j)
		{
			_map[i][j] = ".";
		}
	}
	//campfire
	for (int i = 10; i <= 13; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			_map[i][j] = "C";
		}
	}

	//medium monster
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 3; j <= 5; ++j)
		{
			_map[i][j] = "M";
		}
	}

	//weak monster
	for (int i = 10; i <= 12; ++i)
	{
		for (int j = 18; j <= 20; ++j)
		{
			_map[i][j] = "W";
		}
	}

	//strong monster
	for (int i = 5; i <= 7; ++i)
	{
		for (int j = 12; j <= 14; ++j)
		{
			_map[i][j] = "S";
		}
	}

	//dragon
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 26; j <= 29; ++j)
		{
			_map[i][j] = "D";
		}
	}

	//character
	_map[10][4] = "@";

}


inline void Map::draw_map(std::array<int, 2> curr_player_pos)
{
	_map[previous_char_pos[0]][previous_char_pos[1]] = previous_char;
	previous_char = _map[curr_player_pos[0]][curr_player_pos[1]];
	_map[curr_player_pos[0]][curr_player_pos[1]] = '@';
}

inline std::array<int, 2> Map::get_previous_char_pos()
{
	return previous_char_pos;
}

inline std::array<std::array<std::string, 30>, 15> Map::get_map()
{
	return _map;
}
