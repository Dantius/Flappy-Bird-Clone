#pragma once
#include "stdafx.h"
#include "MainMenuState.hpp"
#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "Flash1.hpp"
#include<iostream>
#include "GameOverState.hpp"


namespace Sonar
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
//Carga de Sonidos
		if (!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH))
		{
			std::cout << "ERROR AUDIO" << std::endl;
		}
		if (!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH))
		{
			std::cout << "ERROR AUDIO" << std::endl;
		}
		if (!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH))
		{
			std::cout << "ERROR AUDIO" << std::endl;
		}
/*		if (!_backgroundMusicBuffer.loadFromFile(BACKGROUND_MUSIC_FILEPATH))
		{
			std::cout << "ERROR AUDIO" << std::endl;
		}*/
		_HitSound.setBuffer(_hitSoundBuffer);
		_WingSound.setBuffer(_wingSoundBuffer);
		_PointSound.setBuffer(_pointSoundBuffer);
//Carga de texturas

		_data->asset.LoadTexture("Game Background",GAME_BACKGROUND_FILEPATH);
		_data->asset.LoadTexture("Pipe Up",	PIPE_UP_FILEPATH);
		_data->asset.LoadTexture("Pipe Down",PIPE_DOWN_FILEPATH);
		_data->asset.LoadTexture("Land",LAND_FILEPATH);
		_data->asset.LoadTexture("Enemy Frame 1", ENEMY_FRAME_1_FILEPATH);
		_data->asset.LoadTexture("Enemy Frame 2", ENEMY_FRAME_2_FILEPATH);
		_data->asset.LoadTexture("Enemy Frame 3", ENEMY_FRAME_3_FILEPATH);
		_data->asset.LoadTexture("Enemy Frame 4", ENEMY_FRAME_4_FILEPATH);
		_data->asset.LoadTexture("Bird Frame 1",BIRD_FRAME_1_FILEPATH);
		_data->asset.LoadTexture("Bird Frame 2",BIRD_FRAME_2_FILEPATH);
		_data->asset.LoadTexture("Bird Frame 3",BIRD_FRAME_3_FILEPATH);
		_data->asset.LoadTexture("Bird Frame 4",BIRD_FRAME_4_FILEPATH);
		_data->asset.LoadTexture("Scoring Pipe",SCORING_PIPE_FILEPATH);
		_data->asset.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

// Generador de objetos

		bird = new Bird(_data);
		pipe = new Pipe(_data);
		land = new Land(_data);
		flash = new Flash1(_data);
		hud = new HUD(_data);
		enemy =new Enemy(_data),
        
// seteo de fondo del juego y score 

		_background.setTexture(this->_data->asset.GetTexture("Game Background"));
		_score = 0;

		hud->UpdateScore(_score);
		_gameState = GameStates::eReady;




	}

	void GameState::HandleInput()
	{
		sf::Event event;

	//Mientras la ventana permanezca abierta

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

		// click en la pantalla, se activa el movimiento del pajaro

			if (_data->input.isSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				if(GameStates::eGameOver !=_gameState)
				{
					_gameState = GameStates::ePlaying;
					bird->Tap();
					_WingSound.play();

				}
			}

			/*
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
			{
				// left key is pressed: move our character
				bird->Tap();
			}*/
		}
	}

	void GameState::Update(float dt)
	{
	//animaciones del pajaro, tierra mientras el juego permanece activo
		if (GameStates::eGameOver != _gameState)
		{
			bird->Animate(dt);
			land->MoveLand(dt);

		}
//clases iniciadas cuando comienza el juego
		if (GameStates::ePlaying == _gameState)
		{
		//movimiento de pipes
			pipe->MovePipes(dt);
			enemy->MoveEnemy(dt);

			if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
			{
				pipe->RandomisePipeOffset();
				pipe->SpawnInvisiblePipe();
				pipe->SpawnBottomPipe();
				pipe->SpawnTopPipe();
				pipe->SpawnScoringPipe();
				clock.restart();
			}
			if (clock1.getElapsedTime().asSeconds() > ENEMY_SPAWN_FREQUENCY)
			{
				enemy->RandomiseEnemyOffset();
				enemy->SpawnEnemy();
				clock1.restart();
			}
			bird->Update(dt);

		//Detecta la colision con el piso
			std::vector < sf::Sprite> landSprites = land->GetSprites();

			for (int i = 0; i < landSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(bird->GetSprite(),0.7f, landSprites.at(i), 1.0f))
				{
					_gameState = GameStates::eGameOver;

					clock.restart();
					_HitSound.play();

				}
			}

		//Detecta la colision con los pipes

			std::vector < sf::Sprite> pipeSprites = pipe->GetSprites();

			for (int i = 0; i < pipeSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(bird->GetSprite(),0.625f, pipeSprites.at(i), 1.0f))
				{
					_gameState = GameStates::eGameOver;

					clock.restart();
					_HitSound.play();
				}
			}
		//Detecta la colision con enemigo
		std::vector < sf::Sprite> enemySprites = enemy->GetSprites();
		
			for (int i = 0; i < enemySprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(bird->GetSprite(), 0.500f, enemy->GetSprite(), 0.75f))
				{
					_gameState = GameStates::eGameOver;

					clock.restart();
					_HitSound.play();
				}
			}

		//Detecta pipes invisibles para  marcar el resultado

			if (GameStates::ePlaying == _gameState)
			{
				std::vector < sf::Sprite> &scoringSprites = pipe->GetScoringSprites();

				for (int i = 0; i < scoringSprites.size(); i++)
				{
					if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, scoringSprites.at(i), 1.0f))
					{
						_score++;
						hud->UpdateScore(_score);
						scoringSprites.erase(scoringSprites.begin() + i);

						_PointSound.play();
					}
				}

			}

		}

	//Si el jugador pierde (colision) se muestra efecto de flash y la pantalla de scoring
		if (GameStates::eGameOver == _gameState)
		{
			flash->Show( dt);

			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
			{
				_data->machine.AddState(StateRef(new GameOverState(_data, _score)));
			}
		}


	}

// dibujo de las diferentes clases
	void GameState::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
		pipe->DrawPipes();
		land->DrawLand();
		enemy->DrawEnemy();
		bird->Draw();

		flash->Draw();

		hud->Draw();
		_data->window.display();
	}

}


