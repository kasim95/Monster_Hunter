#pragma once
#include <array>
//Delete battle class and move everything to UI layer and GameSession class
class Battle
{
	int char_health;
	int mons_health;
	bool turn;	//character's turn = 1, mons_turn = 0
	std::array<std::array<std::string, 20>, 20> char_image;
	std::array<std::array<std::string, 20>, 20> mons_image;	
public:
	Battle() = default;
	~Battle() = default;
	void update_battle(int char_health, int mons_health, int turn, std::array<std::array<std::string, 20>, 20> char_image, std::array<std::array<std::string, 20>, 20> mons_image );	//healths have to be in percentage
};
