#pragma once
#include <array>
#include <ctime>
#include <memory>
#include "Character.hpp"
#include "Assassin.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Monster.hpp"
#include "Goblin.hpp"
#include "Orc.hpp"
#include "Golem.hpp"
#include "Dragon.hpp"
#include "Map.hpp"

namespace Domain::Game
{
	class GameSession
	{
	private:
		std::array<int, 2> player_position;
		Character* player_character;
		Goblin weak_monster;
		Orc medium_monster;
		Golem strong_monster;
		Dragon dragon_monster;
		Map map;
		clock_t time1;
		clock_t time2;
	public:
		GameSession();
		GameSession(Character* selected_character);
		~GameSession() = default;
		bool usePotion();
		void heal_using_campfire();
		void move_character(int direction); //1 for left, 2 for bottom, 3 for right, 4 for top
		void attack(int monster_type, bool char_turn); //incomplete
		bool end_game();
		double calculate_score();
		std::array<std::array<std::string, 30>, 15> return_map();
		bool equip_weapon(int weapon_attributes);
		double get_player_damage();
		double get_player_health_percentage();
		char get_previous_char();
		int get_no_of_potions();
		double get_weak_monster_health_percentage();
		double get_medium_monster_health_percentage();
		double get_strong_monster_health_percentage();
		double get_dragon_monster_health_percentage();
		void reset_all_monsters();
		double get_weapon_drop_attributes(int monster_type);
	};
}
