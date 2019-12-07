#include "GameSession.hpp"
#include "CharacterCreator.hpp"
#include "Map.hpp"

namespace Domain::Game
{
	GameSession::GameSession(std::string characterName)
	{
		theCreator = Domain::Game::CharacterCreator::createCreator(characterName);
		player_character = theCreator->createCharacter();

		player_character->calculate_damage();				//Information Expert GRASP pattern is used here. 
		time1 = clock();									// calculate_damage is located in the Character class since that is where all the information is stored.
		time2 = time1;
		weak_monster = new Goblin();
		medium_monster = new Orc();
		strong_monster = new Golem();
		dragon_monster = new Dragon();
		weak_monster->reset_monster();						//creator GRASP is also used here. GameSession creates the instance than PlayGame class creates them.
		medium_monster->reset_monster();
		strong_monster->reset_monster();
		dragon_monster->reset_monster();
		map = new Map();
	}

	GameSession::~GameSession() noexcept
	{}
	
	void GameSession::heal_using_campfire(double percentage) noexcept
	{
		
		double max_health = player_character->get_max_health();
		double curr_health = player_character->get_current_health();
		curr_health += max_health * (percentage/100);
		if (curr_health > max_health) { curr_health = max_health; }
		player_character->set_current_health(curr_health);
	}

	void GameSession::move_character(int direction) noexcept
	{
		std::array<int, 2> previous_char_pos = map->get_previous_char_pos();
		std::array<int, 2> new_pos;
		if (direction == 4)
		{
			if ((previous_char_pos[0] - 1) > 0)
			{
				new_pos[0] = previous_char_pos[0] - 1;
				new_pos[1] = previous_char_pos[1];
				map->draw_map(new_pos);
			}
		}
		else if (direction == 2)
		{
			if ((previous_char_pos[0] + 1) < 14)
			{
				new_pos[0] = previous_char_pos[0] + 1;
				new_pos[1] = previous_char_pos[1];
				map->draw_map(new_pos);
			}

		}
		else if (direction == 3)
		{
			if ((previous_char_pos[1] + 1) < 29)
			{
				new_pos[0] = previous_char_pos[0];
				new_pos[1] = previous_char_pos[1] + 1;
				map->draw_map(new_pos);
			}
		}
		else
		{
			if ((previous_char_pos[1] - 1) > 0)
			{
				new_pos[0] = previous_char_pos[0];
				new_pos[1] = previous_char_pos[1] - 1;
				map->draw_map(new_pos);
			}
		}
	}

	void GameSession::attack(int monster_type, bool char_turn) noexcept
	{
		/*
		monster_type = 1 for weak monster
		monster_type = 2 for medium monster
		monster_type = 3 for strong monster
		monster_type = 4 for dragon monster
		*/
		//later implement battle log message for each attack
		double char_health = player_character->get_current_health();
		double char_damage = player_character->get_damage();
		if (monster_type == 1)
		{
			double monster_health = weak_monster->get_current_health();
			double monster_damage = weak_monster->get_damage();
			if (char_turn) weak_monster->set_current_health(monster_health - char_damage);
			else player_character->set_current_health(char_health - monster_damage);
		}
		else if (monster_type == 2)
		{
			double monster_health = medium_monster->get_current_health();
			double monster_damage = medium_monster->get_damage();
			if (char_turn) medium_monster->set_current_health(monster_health - char_damage);
			else player_character->set_current_health(char_health - monster_damage);
		}
		else if (monster_type == 3)
		{
			double monster_health = strong_monster->get_current_health();
			double monster_damage = strong_monster->get_damage();
			if (char_turn) strong_monster->set_current_health(monster_health - char_damage);
			else player_character->set_current_health(char_health - monster_damage);
		}
		else
		{
			double monster_health = dragon_monster->get_current_health();
			double monster_damage = dragon_monster->get_damage();
			if (char_turn) dragon_monster->set_current_health(monster_health - char_damage);
			else player_character->set_current_health(char_health - monster_damage);
		}
	}
}
