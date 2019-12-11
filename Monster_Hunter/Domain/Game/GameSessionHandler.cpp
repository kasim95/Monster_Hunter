#include "GameSessionHandler.hpp"


namespace Domain::Game
{
	GameSessionHandler::~GameSessionHandler() noexcept
	{}

	bool GameSessionHandler::usePotion()
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

	bool GameSessionHandler::end_game()
	{
		time2 = clock();
		return true;
	}


	double GameSessionHandler::calculate_score()
	{
		double elapsed_secs = double(time2 - time1);
		//enter formula to calculate score
		double minutes;
		minutes = elapsed_secs / 60000;
		return minutes;
	}

	std::array<std::array<std::string, 30>, 15> GameSessionHandler::return_map()
	{
		return map->get_map();
	}

	bool GameSessionHandler::equip_weapon(double weapon_attributes)
	{
		player_character->equip_Weapon(weapon_attributes, 0);
		player_character->calculate_damage();
		return true;
	}

	double GameSessionHandler::get_player_damage()
	{
		return player_character->get_damage();
	}

	double GameSessionHandler::get_player_health_percentage()
	{
		return (player_character->get_current_health() * 100) / (player_character->get_max_health());
	}

	char GameSessionHandler::get_previous_char()
	{
		return map->get_previous_char()[0];
	}

	int GameSessionHandler::get_no_of_potions()
	{
		return player_character->get_potion();
	}

	void GameSessionHandler::reset_monster(int monster_type)
	{
		if (monster_type == 1) weak_monster->reset_monster();
		else if (monster_type == 2) medium_monster->reset_monster();
		else if (monster_type == 3) strong_monster->reset_monster();
		else;
	}

	double GameSessionHandler::get_weapon_drop_attributes(int monster_type)
	{
		if (monster_type == 1) return weak_monster->get_weapon_drop();
		else if (monster_type == 2) return medium_monster->get_weapon_drop();
		else if (monster_type == 3) return strong_monster->get_weapon_drop();
		else return 0.0;
	}

	bool GameSessionHandler::is_player_alive()
	{
		if (player_character->get_current_health() > 0.0) return true;
		return false;
	}

	bool GameSessionHandler::is_dragon_alive()
	{
		if (dragon_monster->get_current_health() > 0.0) return true;
		return false;
	}

	std::string GameSessionHandler::get_monster_name(int monster_type)
	{
		if (monster_type == 1) return weak_monster->get_monster_name();
		else if (monster_type == 2) return medium_monster->get_monster_name();
		else if (monster_type == 3) return strong_monster->get_monster_name();
		else if (monster_type == 4) return dragon_monster->get_monster_name();
		else return "NA";
	}

	double GameSessionHandler::get_monster_health_percentage(int monster_type)
	{
		if (monster_type == 1) return (weak_monster->get_current_health() * 100.0) / weak_monster->get_max_health();
		else if (monster_type == 2) return (medium_monster->get_current_health() * 100.0) / medium_monster->get_max_health();
		else if (monster_type == 3) return (strong_monster->get_current_health() * 100.0) / strong_monster->get_max_health();
		else if (monster_type == 4) return (dragon_monster->get_current_health() * 100.0) / dragon_monster->get_max_health();
		else return 0.0;
	}

	std::string GameSessionHandler::get_character_name()
	{
		return player_character->get_name();
	}
	double GameSessionHandler::get_player_attributes()
	{
		return player_character->get_attributes();
	}
	std::string GameSessionHandler::get_character_weapon_name()
	{
		return player_character->get_weapon_name();
	}
	int GameSessionHandler::get_character_weapon_attributes()
	{
		return (int)player_character->get_weapon_attributes();
	}
}