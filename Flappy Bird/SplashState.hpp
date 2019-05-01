#pragma once

#include "stdafx.h"

#include <SFML\Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Sonar
{
	class SplashState : public State
	{
	public:
			SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);


	private:

		GameDataRef _data;
		sf::Clock _clock;

		sf::Texture _backgroundtexture;

		sf::Sprite _background;
	};
}