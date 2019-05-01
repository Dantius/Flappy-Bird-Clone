#pragma once
#include "stdafx.h"

#include <memory>
#include <string>
#include <SFML\Config.hpp>
#include"StateMachine.hpp"
#include"AssetManager.hpp"
#include"InputManager.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp> 

namespace Sonar
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager asset;
		InputManager input;

	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, std::string title);

	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;
		sf::SoundBuffer _backgroundMusicBuffer;
		sf::Music _backgroundMusic;

		GameDataRef _data = std::make_shared<GameData>();

		void Run();

	};

}