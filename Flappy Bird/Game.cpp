#include "stdafx.h"
#include "SplashState.hpp"
#include <stdlib.h>
#include <time.h>
#include "Game.hpp"
#include "GameState.hpp"
#include<iostream>

namespace Sonar
{
	Game::Game(int width, int height, std::string title)
	{
		srand(time(NULL));
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.AddState(StateRef(new SplashState(this->_data)));



		this->Run();

	}


	void Game::Run()
	{
		float newTime, FrameTime, interpolation;

		if (!_backgroundMusic.openFromFile(BACKGROUND_MUSIC_FILEPATH))
		{
			std::cout << "ERROR AUDIO" << std::endl;

		}
		_backgroundMusic.setVolume(25);
		_backgroundMusic.play();
		
		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();

			FrameTime = newTime - currentTime;

			if (FrameTime > 0.25f)
			{
				FrameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += FrameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();

				this->_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}
	}
}