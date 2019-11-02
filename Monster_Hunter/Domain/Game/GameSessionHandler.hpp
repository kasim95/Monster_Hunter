#pragma once

namespace Domain::Game
{
	class GameSessionHandler
	{
	public:
		GameSessionHandler() = default;
		GameSessionHandler(const GameSessionHandler & original) = default;
		GameSessionHandler(GameSessionHandler && original) = default;
		virtual ~GameSessionHandler() noexcept = 0;

	protected:
		GameSessionHandler & operator=(const GameSessionHandler & rhs) = default;
		GameSessionHandler & operator=(GameSessionHandler && rhs) = default;
	};


	inline GameSessionHandler::~GameSessionHandler() noexcept
	{}

}
