#include "Map.hpp"

namespace Domain::Game
{
	Map::Map()
	{
		//dots
		for (int i = 0; i < 15; ++i)
		{
			for (int j = 0; j < 30; ++j)
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
			for (int j = 25; j <= 28; ++j)
			{
				_map[i][j] = "D";
			}
		}

		//character
		_map[10][4] = "@";
		previous_char_pos[0] = 10;
		previous_char_pos[1] = 4;
		previous_char = "C";

		//horizontal borders
		for (int i = 0; i < 30; ++i)
		{
			_map[0][i] = "_";
			_map[14][i] = "_";
		}

		//vertical borders
		for (int i = 1; i < 14; ++i)
		{
			_map[i][0] = "|";
			_map[i][29] = "|";
		}
	}

	void Map::draw_map(std::array<int, 2> curr_player_pos)
	{
		_map[previous_char_pos[0]][previous_char_pos[1]] = previous_char;
		previous_char = _map[curr_player_pos[0]][curr_player_pos[1]];
		_map[curr_player_pos[0]][curr_player_pos[1]] = '@';
		previous_char_pos = curr_player_pos;
	}

	//you can remove this setter and getter if its not needed at the end
	std::array<int, 2> Map::get_previous_char_pos()
	{
		return previous_char_pos;
	}

	void Map::set_previous_char_pos(std::array<int, 2> value)
	{
		previous_char_pos = value;
	}

	std::array<std::array<std::string, 30>, 15> Map::get_map()
	{
		return _map;
	}
}
