#pragma once
#include "stdafx.h"

#include <SFML\Graphics.hpp>
#include "Game.hpp"

#include "DEFINITIONS.hpp"

namespace Sonar
{
	class Flash1
	{
	public:

		Flash1(GameDataRef data);

		void Show(float dt);
		void Draw();

	private:
		GameDataRef _data;
		sf::RectangleShape _shape;


		bool _flashOn;

	};
}
