//#include "pch.h"
#include "GameSession.hpp"


GameSession::GameSession()
{
	Character* player_character = new Assassin();
	player_character->calculate_damage();
	time1 = clock();
	time2 = time1;
}

GameSession::GameSession(Character * selected_character)
{
	player_character = selected_character;
	player_character->calculate_damage();
	time1 = clock();
	time2 = time1;
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
	
void GameSession::fight(int monster_type)
{
	int z; //placeholder for no code
	/*
	monster_type = 1 for weak monster
	monster_type = 2 for medium monster
	monster_type = 3 for strong monster
	monster_type = 4 for dragon monster
	*/
	if (monster_type == 1)
	{
		z = 1;
	}
	else if (monster_type == 2)
	{
		z = 2;
	}
	else if (monster_type == 3)
	{
		z = 3;
	}
	else
	{
		z = 4;
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
	player_character->set_weapon_attributes(weapon_attributes);
	player_character->calculate_damage();
	return true;
}

int GameSession::get_player_damage()
{
	return player_character->get_damage();
}

int GameSession::get_player_health_percentage()
{
	return (player_character->get_current_health() * 100) / (player_character->get_max_health());
}
