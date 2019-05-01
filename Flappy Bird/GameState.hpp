#pragma once

#include "stdafx.h"
#include "Pipe.hpp"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash1.hpp"
#include "HUD.hpp"
#include "Enemy.hpp"

namespace Sonar
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);


	private:

		GameDataRef _data;

		sf::Texture _backgroundtexture;
		sf::Sprite _background;
		Pipe *pipe;
		Land *land;
		Bird *bird;
		Enemy *enemy;
		Collision collision;
		Flash1 * flash;
		HUD * hud;
		sf::Clock clock;
		sf::Clock clock1;

		int _gameState;

		int _score;

		sf::SoundBuffer _hitSoundBuffer;
		sf::SoundBuffer _pointSoundBuffer;
		sf::SoundBuffer _wingSoundBuffer;
		sf::SoundBuffer _backgroundMusicBuffer;

		sf::Sound _HitSound;
		sf::Sound _PointSound;
		sf::Sound _WingSound;
		sf::Music _backgroundMusic;

	};
}