#pragma once
namespace Domain::Game
{
	class Orc : public Domain::Game::Monster
	{
	public:
		~Orc() noexcept override;
		void set_damage() override;
		void set_image() override;
		void set_max_health() override;

	};
	//inline implementation
	inline Orc::~Orc() noexcept
	{
	}

	inline void Orc::set_damage() {
		damage = base_damage * 2;
	}

	inline void Orc::set_image() {
		//placeholder code
		//change later once the images are finalized
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				image[i][j] = std::to_string(j);
			}
		}
	}

	inline void Orc::set_max_health() {
		max_health = 30 * 2;
	}
}