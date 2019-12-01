#pragma once
#include <string>
#include "Character.hpp"
#include "Assassin.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"

namespace Domain::Game
{
	struct CharacterCreator
	{
		static CharacterCreator * createCreator(std::string characterType);
		virtual Character * createCharacter() = 0;
	};

	struct AssassinCreator : CharacterCreator
	{
		Assassin * createCharacter() override
		{
			return new Assassin();
		}
	};

	struct WarriorCreator : CharacterCreator
	{
		Warrior * createCharacter() override
		{
			return new Warrior();
		}
	};

	struct MageCreator : CharacterCreator
	{
		Mage * createCharacter() override
		{
			return new Mage();
		}
	};
	
	inline CharacterCreator * CharacterCreator::createCreator(std::string characterType)
	{
		if (characterType == "Assassin") return new AssassinCreator();
		else if (characterType == "Warrior") return new WarriorCreator();
		else if (characterType == "Mage") return new MageCreator();
		else throw std::domain_error("Unsupported character type encountered " + characterType);
	}

}
