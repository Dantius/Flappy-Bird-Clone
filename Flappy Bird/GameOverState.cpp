#pragma once
#include "stdafx.h"
#include "MainMenuState.hpp"
#include <sstream>
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include <fstream>
#include<iostream>

namespace Sonar
{
	GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score)
	{

	}

	void GameOverState::Init()
	{
		std::ifstream readFile;
		readFile.open("C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/Highscore.png");
		
		if (readFile.is_open() )
		{
			while (!readFile.eof())
			{
				readFile >> _highScore;
			}
		}

		readFile.close();
		std::ofstream writeFile("C:/Users/Gonzalo/Desktop/Flappy Bird/Flappy Bird/Debug/Resources/res/Highscore.png");

		if (writeFile.is_open())
		{
			if (_score > _highScore)
			{
				_highScore = _score;
			}
			writeFile << _highScore;

		}
		writeFile.close();

		_data->asset.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		_data->asset.LoadTexture("Game Over Title",	GAME_OVER_TITLE_FILEPATH);
		_data->asset.LoadTexture("Game Over Body",	GAME_OVER_BODY_FILEPATH);

		_data->asset.LoadTexture("Bronze Medal", BRONZE_MEDAL_FILEPATH);
		_data->asset.LoadTexture("Silver Medal", SILVER_MEDAL_FILEPATH);
		_data->asset.LoadTexture("Gold Medal", GOLD_MEDAL_FILEPATH);
		_data->asset.LoadTexture("Platinum Medal", PLATINUM_MEDAL_FILEPATH);

		_background.setTexture(this->_data->asset.GetTexture("Game Over Background"));
		_gameOverTitle.setTexture(this->_data->asset.GetTexture("Game Over Title"));
		_gameOverContainer.setTexture(this->_data->asset.GetTexture("Game Over Body"));
		_retryButton.setTexture(this->_data->asset.GetTexture("Play Button"));



		//Posiciones de Sprites de game Over

		_gameOverContainer.setPosition((_data->window.getSize().x/2) - (
		_gameOverContainer.getGlobalBounds().width /2), (_data->window.
			getSize().y / 2) -	(_gameOverContainer.getGlobalBounds().height /
			2) );


		_gameOverTitle.setPosition((_data->window.getSize().x / 2) - (
			_gameOverContainer.getGlobalBounds().width / 2), _gameOverContainer.
			getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.2) );

		_retryButton.setPosition((_data->window.getSize().x / 2) - (
			_retryButton.getGlobalBounds().width / 2), _gameOverContainer.
			getPosition().y + _gameOverContainer.getGlobalBounds().height + (
				_retryButton.getGlobalBounds().height * 0.2));


		_scoreText.setFont(_data->asset.GetFont("Flappy Font"));
		_scoreText.setString(std::to_string( _score));
		_scoreText.setCharacterSize(56);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2,
			_scoreText.getGlobalBounds().height / 2);
		_scoreText.setPosition(_data->window.getSize().x / 10 * 7.25, 
			_data->window.getSize().y / 2.15);

		_highScoreText.setFont(_data->asset.GetFont("Flappy Font"));
		_highScoreText.setString(std::to_string(_highScore));
		_highScoreText.setCharacterSize(56);
		_highScoreText.setFillColor(sf::Color::White);
		_highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2,
			_highScoreText.getGlobalBounds().height / 2);
		_highScoreText.setPosition(_data->window.getSize().x / 10 * 7.25,
			_data->window.getSize().y / 1.78 );

		if (_score >= PLATINUM_MEDAL_SCORE)
		{
			_medal.setTexture(_data->asset.GetTexture("Platinum Medal"));
		}
		else if (_score >= GOLD_MEDAL_SCORE)
		{
			_medal.setTexture(_data->asset.GetTexture("Gold Medal"));
		}
		else if (_score >= SILVER_MEDAL_SCORE)
		{
			_medal.setTexture(_data->asset.GetTexture("Silver Medal"));
		}
		else 
		{
			_medal.setTexture(_data->asset.GetTexture("Bronze Medal"));
		}

		_medal.setPosition(175, 465);
	}

	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

			if (_data->input.isSpriteClicked(_retryButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef( new GameState(_data)), true);
			}
		}
	}

	void GameOverState::Update(float dt)
	{

	}


	void GameOverState::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
		_data->window.draw(_gameOverTitle);
		_data->window.draw(_gameOverContainer);
		_data->window.draw(_retryButton);
		_data->window.draw(_scoreText);
		_data->window.draw(_highScoreText);
		_data->window.draw(_medal);

		_data->window.display();

	}

}


