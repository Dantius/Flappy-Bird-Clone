#pragma once
#include "stdafx.h"
#include <vector>
#include <SFML\Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Sonar {

	class Bird {

	public:
		Bird(GameDataRef data);

		void Draw();

		void Animate(float dt);

		void Update(float dt);
		void Tap();

		const sf::Sprite &GetSprite() const;

	private:
		GameDataRef _data;

		sf::Sprite _birdSprite;

		std::vector<sf::Texture> _animationFrames;

		unsigned int _animationInterator;
		sf::Clock _clock;

		sf::Clock _movementClock;

		int _birdState;

		float _rotation;

	};
}