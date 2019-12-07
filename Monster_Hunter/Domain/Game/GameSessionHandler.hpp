#pragma once
#include <array>
#include <ctime>
#include <memory>
#include <string>

#include "CharacterCreator.hpp"
#include "Character.hpp"
#include "Monster.hpp"
#include "MapHandler.hpp"


namespace Domain::Game
{
	class GameSessionHandler
	{
	public:
		GameSessionHandler() = default;
		GameSessionHandler(const GameSessionHandler & original) = default;
		GameSessionHandler(GameSessionHandler && original) = default;
		virtual ~GameSessionHandler() noexcept = 0;
		virtual void heal_using_campfire(double percentage) noexcept = 0;
		virtual void move_character(int direction) noexcept = 0; //1 for left, 2 for bottom, 3 for right, 4 for top
		virtual void attack(int monster_type, bool char_turn) noexcept = 0; //incomplete
		bool usePotion();
		bool end_game();
		double calculate_score();
		std::array<std::array<std::string, 30>, 15> return_map();
		bool equip_weapon(double weapon_attributes);
		double get_player_damage();
		double get_player_health_percentage();
		char get_previous_char();
		int get_no_of_potions();
		void reset_monster(int monster_type);
		double get_weapon_drop_attributes(int monster_type);
		bool is_player_alive();
		bool is_dragon_alive();
		std::string get_monster_name(int monster_type);
		double get_monster_health_percentage(int monster_type);
		std::string get_character_name();
		double get_player_attributes();
		std::string get_character_weapon_name();
		int get_character_weapon_attributes();


	protected:
		GameSessionHandler & operator=(const GameSessionHandler & rhs) = default;
		GameSessionHandler & operator=(GameSessionHandler && rhs) = default;
		CharacterCreator * theCreator;
		std::array<int, 2> player_position;
		Character * player_character;
		Monster * weak_monster;
		Monster * medium_monster;
		Monster * strong_monster;
		Monster * dragon_monster;
		MapHandler * map;
		clock_t time1;
		clock_t time2;
	};
}
