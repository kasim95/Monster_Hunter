#pragma once
#include <array>

namespace Domain::Game
{
	class MapHandler
	{
	public:
		MapHandler() = default;
		virtual ~MapHandler() noexcept = 0;
		virtual void draw_map(std::array<int, 2> curr_player_pos);
		std::array<int, 2> get_previous_char_pos();
		void set_previous_char_pos(std::array<int, 2> value);
		std::array<std::array<std::string, 30>, 15> get_map();
		std::string get_previous_char();
	protected:
		std::array<std::array<std::string, 30>, 15> _map;
		std::string previous_char;
		std::array<int, 2> previous_char_pos;
	};

	inline MapHandler::~MapHandler() noexcept
	{}

	inline void MapHandler::draw_map(std::array<int, 2> curr_player_pos)
	{}

	inline std::array<int, 2> MapHandler::get_previous_char_pos()
	{
		return previous_char_pos;
	}

	inline void MapHandler::set_previous_char_pos(std::array<int, 2> value)
	{
		previous_char_pos = value;
	}

	inline std::array<std::array<std::string, 30>, 15> MapHandler::get_map()
	{
		return _map;
	}

	inline std::string MapHandler::get_previous_char()
	{
		return previous_char;
	}
}
