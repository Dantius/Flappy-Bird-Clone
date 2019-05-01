#pragma once
#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include <vector>

namespace Sonar {
	
	class Enemy
	{
	public:
		Enemy(GameDataRef data);

		void SpawnEnemy();
		void MoveEnemy(float dt);
		void DrawEnemy();
		void RandomiseEnemyOffset();

		const std::vector<sf::Sprite> &GetSprites() const;

// objetos de animaciones

		void Animate(float dt);
		unsigned int _animationInterator;
		sf::Clock _clock;
		std::vector<sf::Texture> _animationFrames;

		const sf::Sprite &GetSprite() const;

	private:

		GameDataRef _data;
		sf::Sprite _enemySprite;
	
		std::vector<sf::Sprite> enemysprites;

		int _landHeight;
		int _enemySpawnYOffset;
	};
}