#include "GameSession.hpp"

namespace Domain::Game
{
	GameSession::GameSession()
	{
		//Character* player_character = new Assassin();
		// the reason the test for equip weapon WAS failing because Assassin z is lost once the constructor is called and this causes memory leak which returns a nullptr
		Character* z = new Assassin();
		player_character = z;
		player_character->calculate_damage();
		time1 = clock();
		time2 = time1;
		weak_monster.reset_monster();
		medium_monster.reset_monster();
		strong_monster.reset_monster();
		dragon_monster.reset_monster();
	}

	GameSession::GameSession(Character * selected_character)
	{
		//Character* player_character;
		player_character = selected_character;
		player_character->calculate_damage();
		time1 = clock();
		time2 = time1;
		weak_monster.reset_monster();
		medium_monster.reset_monster();
		strong_monster.reset_monster();
		dragon_monster.reset_monster();
	}

	bool GameSession::usePotion()
	{
		int potions = player_character->get_potion();
		if (potions > 0)
		{
			player_character->set_potion(potions - 1);
			return true;
		}
		return false;
	}

	void GameSession::heal_using_campfire()
	{
		double max_health = player_character->get_max_health();
		double curr_health = player_character->get_current_health();
		while (curr_health < max_health)
		{
			curr_health += max_health * 0.1;
			if (curr_health > max_health) { curr_health = max_health; }
			player_character->set_current_health(curr_health);
		}
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
		return elapsed_secs;
	}

	std::array<std::array<std::string, 30>, 15> GameSession::return_map()
	{
		return map.get_map();
	}

	bool GameSession::equip_weapon(int weapon_attributes)
	{
//		player_character->set_weapon_attributes(weapon_attributes);
		player_character->gain_Attribute(weapon_attributes, 0);
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
	double GameSession::get_weak_monster_health_percentage()
	{
		return (weak_monster.get_current_health() * 100)/weak_monster.get_max_health();
	}
	double GameSession::get_medium_monster_health_percentage()
	{
		return (medium_monster.get_current_health() * 100)/medium_monster.get_max_health();
	}
	double GameSession::get_strong_monster_health_percentage()
	{
		return (strong_monster.get_current_health() * 100)/strong_monster.get_max_health();
	}
	double GameSession::get_dragon_monster_health_percentage()
	{
		return (dragon_monster.get_current_health() * 100)/dragon_monster.get_max_health();
	}
	void GameSession::reset_all_monsters()
	{
		weak_monster.reset_monster();
		medium_monster.reset_monster();
		strong_monster.reset_monster();
	}
	double GameSession::get_weapon_drop_attributes(int monster_type)
	{
		if (monster_type == 1) return weak_monster.get_weapon_drop();
		else if (monster_type == 2) return medium_monster.get_weapon_drop();
		else if (monster_type == 3) return strong_monster.get_weapon_drop();
		else return 0.0;
	}
}
