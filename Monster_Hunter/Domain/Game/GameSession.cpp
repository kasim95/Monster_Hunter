#include "GameSession.hpp"

namespace Domain::Game
{
	GameSession::GameSession(Character * selected_character)
	{
		player_character = selected_character;
		player_character->calculate_damage();				//Information Expert GRASP pattern is used here. 
		time1 = clock();									// calculate_damage is located in the Character class since that is where all the information is stored.
		time2 = time1;
		weak_monster.reset_monster();
		medium_monster.reset_monster();
		strong_monster.reset_monster();
		dragon_monster.reset_monster();
	}

	GameSession::~GameSession() noexcept
	{}

	bool GameSession::usePotion()
	{
		int potions = player_character->get_potion();
		if (potions > 0)
		{
			player_character->set_potion(potions - 1);
			player_character->set_current_health(player_character->get_max_health());
			player_character->set_attributes(player_character->get_attributes() + 30);
			return true;
		}
		return false;
	}

	void GameSession::heal_using_campfire(double percentage)
	{
		
		double max_health = player_character->get_max_health();
		double curr_health = player_character->get_current_health();
		curr_health += max_health * (percentage/100);
		if (curr_health > max_health) { curr_health = max_health; }
		player_character->set_current_health(curr_health);
	}

	void GameSession::move_character(int direction)
	{
		std::array<int, 2> previous_char_pos = map.get_previous_char_pos();
		std::array<int, 2> new_pos;
		if (direction == 4)
		{
			if ((previous_char_pos[0] - 1) > 0)
			{
				new_pos[0] = previous_char_pos[0] - 1;
				new_pos[1] = previous_char_pos[1];
				map.draw_map(new_pos);
			}
		}
		else if (direction == 2)
		{
			if ((previous_char_pos[0] + 1) < 14)
			{
				new_pos[0] = previous_char_pos[0] + 1;
				new_pos[1] = previous_char_pos[1];
				map.draw_map(new_pos);
			}

		}
		else if (direction == 3)
		{
			if ((previous_char_pos[1] + 1) < 29)
			{
				new_pos[0] = previous_char_pos[0];
				new_pos[1] = previous_char_pos[1] + 1;
				map.draw_map(new_pos);
			}
		}
		else
		{
			if ((previous_char_pos[1] - 1) > 0)
			{
				new_pos[0] = previous_char_pos[0];
				new_pos[1] = previous_char_pos[1] - 1;
				map.draw_map(new_pos);
			}
		}
	}

	void GameSession::attack(int monster_type, bool char_turn)
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
			double monster_health = weak_monster.get_current_health();
			double monster_damage = weak_monster.get_damage();
			if (char_turn) weak_monster.set_current_health(monster_health - char_damage);
			else player_character->set_current_health(char_health - monster_damage);
		}
		else if (monster_type == 2)
		{
			double monster_health = medium_monster.get_current_health();
			double monster_damage = medium_monster.get_damage();
			if (char_turn) medium_monster.set_current_health(monster_health - char_damage);
			else player_character->set_current_health(char_health - monster_damage);
		}
		else if (monster_type == 3)
		{
			double monster_health = strong_monster.get_current_health();
			double monster_damage = strong_monster.get_damage();
			if (char_turn) strong_monster.set_current_health(monster_health - char_damage);
			else player_character->set_current_health(char_health - monster_damage);
		}
		else
		{
			double monster_health = dragon_monster.get_current_health();
			double monster_damage = dragon_monster.get_damage();
			if (char_turn) dragon_monster.set_current_health(monster_health - char_damage);
			else player_character->set_current_health(char_health - monster_damage);
		}
	}

	bool GameSession::end_game()
	{
		time2 = clock();
		return true;
	}

	double GameSession::calculate_score()
	{
		double elapsed_secs = double(time2 - time1);
		//enter formula to calculate score
		double minutes;
		minutes = elapsed_secs / 60000;
		return minutes;
	}

	std::array<std::array<std::string, 30>, 15> GameSession::return_map()
	{
		return map.get_map();
	}

	bool GameSession::equip_weapon(double weapon_attributes)
	{
//		player_character->set_weapon_attributes(weapon_attributes);
		player_character->equip_Weapon(weapon_attributes, 0);
		player_character->calculate_damage();
		return true;
	}

	double GameSession::get_player_damage()
	{
		return player_character->get_damage();
	}

	double GameSession::get_player_health_percentage()
	{
		return (player_character->get_current_health() * 100) / (player_character->get_max_health());
	}

	char GameSession::get_previous_char()
	{
		return map.get_previous_char()[0];
	}

	int GameSession::get_no_of_potions()
	{
		return player_character->get_potion();
	}

	void GameSession::reset_monster(int monster_type)
	{
		if (monster_type == 1) weak_monster.reset_monster();
		else if (monster_type == 2) medium_monster.reset_monster();
		else if (monster_type == 3) strong_monster.reset_monster();
		else;
	}

	double GameSession::get_weapon_drop_attributes(int monster_type)
	{
		if (monster_type == 1) return weak_monster.get_weapon_drop();
		else if (monster_type == 2) return medium_monster.get_weapon_drop();
		else if (monster_type == 3) return strong_monster.get_weapon_drop();
		else return 0.0;
	}

	bool GameSession::is_player_alive()
	{
		if (player_character->get_current_health() > 0.0) return true;
		return false;
	}
	
	bool GameSession::is_dragon_alive()
	{
		if (dragon_monster.get_current_health() > 0.0) return true;
		return false;
	}

	std::string GameSession::get_monster_name(int monster_type)
	{
		if (monster_type == 1) return weak_monster.get_monster_name();
		else if (monster_type == 2) return medium_monster.get_monster_name();
		else if (monster_type == 3) return strong_monster.get_monster_name();
		else if (monster_type == 4) return dragon_monster.get_monster_name();
		else return "NA";
	}

	double GameSession::get_monster_health_percentage(int monster_type)
	{
		if (monster_type == 1) return (weak_monster.get_current_health() * 100.0) / weak_monster.get_max_health();
		else if (monster_type == 2) return (medium_monster.get_current_health() * 100.0) / medium_monster.get_max_health();
		else if (monster_type == 3) return (strong_monster.get_current_health() * 100.0) / strong_monster.get_max_health();
		else if (monster_type == 4) return (dragon_monster.get_current_health() * 100.0) / dragon_monster.get_max_health();
		else return 0.0;
	}

	std::string GameSession::get_character_name()
	{
		return player_character->get_name();
	}
	double GameSession::get_player_attributes()
	{
		return player_character->get_attributes();
	}
	std::string GameSession::get_character_weapon_name()
	{
		return player_character->get_weapon_name();
	}
	int GameSession::get_character_weapon_attributes()
	{
		return player_character->get_weapon_attributes();
	}
}
