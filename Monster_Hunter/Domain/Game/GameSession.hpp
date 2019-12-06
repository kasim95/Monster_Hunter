#pragma once
#include <array>
#include <ctime>
#include <memory>
#include <string>
#include "GameSessionHandler.hpp"
#include "Character.hpp"
#include "Assassin.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Monster.hpp"
#include "Goblin.hpp"
#include "Orc.hpp"
#include "Golem.hpp"
#include "Dragon.hpp"
#include "MapHandler.hpp"
#include "CharacterCreator.hpp"

namespace Domain::Game
{
	class GameSession : public Domain::Game::GameSessionHandler
	{
	private:
		std::array<int, 2> player_position;
		Character* player_character;
		Goblin weak_monster;
		Orc medium_monster;
		Golem strong_monster;
		Dragon dragon_monster;
		MapHandler * map;
		clock_t time1;
		clock_t time2;
	public:
		GameSession() = default;
		GameSession(std::string characterName);
		~GameSession() noexcept override;
		bool usePotion();
		void heal_using_campfire(double percentage);
		void move_character(int direction); //1 for left, 2 for bottom, 3 for right, 4 for top
		void attack(int monster_type, bool char_turn); //incomplete
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
	};
}
