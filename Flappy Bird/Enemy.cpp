#include "stdafx.h"

#include "Enemy.hpp"
#include <iostream>


namespace Sonar {

	Enemy:: Enemy(GameDataRef data) : _data(data)
	{
		_landHeight = _data->asset.GetTexture("Land").getSize().y;
		
		_enemySpawnYOffset=0;

//carga de animaciones
       _animationInterator = 0;
	 	_animationFrames.push_back(_data->asset.GetTexture("Enemy Frame 1"));
		_animationFrames.push_back(_data->asset.GetTexture("Enemy Frame 2"));
		_animationFrames.push_back(_data->asset.GetTexture("Enemy Frame 3"));
		//_animationFrames.push_back(_data->asset.GetTexture("Enemy Frame 4"));	

		_enemySprite.setTexture( _animationFrames.at(_animationInterator));
	}

//Funcion de animaciones

	void Enemy::Animate(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() >
			ENEMY_ANIMATION_DURATION / _animationFrames.size())
		{
			if (_animationInterator < _animationFrames.size() - 1)
			{
				_animationInterator++;
			}
			else
			{
				_animationInterator = 0;
			}

			_enemySprite.setTexture(_animationFrames.at(_animationInterator));

			_clock.restart();
		}
	}	
//Generar enemigo	
	void Enemy::SpawnEnemy()
	{
		//sf::Sprite sprite(_data->asset.GetTexture("Enemy"));
		_enemySprite.setTexture(_animationFrames.at(_animationInterator));
		_enemySprite.setPosition(_data->window.getSize().x, +_enemySpawnYOffset);

		enemysprites.push_back(_enemySprite);

	}

//movimiento de enemigo
	
	void Enemy:: MoveEnemy(float dt)
	{
		Animate(dt);

		float movement = ENEMY_MOVEMENT_SPEED * dt;
		_enemySprite.move(-10, 0);

		/*for (unsigned short int i = 0; i < enemysprites.size(); i++)
		{

			float movement = ENEMY_MOVEMENT_SPEED * dt;

			//enemysprites.at(i).move(-10, 0);
			//_enemySprite.move(, 0);
			//Animate(dt);

		} */

	}
	
// Dibujar enemigo

	void Enemy :: DrawEnemy()
	{
		for (unsigned short int i = 0; i < enemysprites.size(); i++)
		{
			_data->window.draw(enemysprites.at(i));
			_data->window.draw(_enemySprite);
		}
	}
	
		void Enemy::RandomiseEnemyOffset()
	{
		_enemySpawnYOffset = rand() % (_landHeight + 400);
	}
		
	const std::vector<sf::Sprite> &Enemy::GetSprites() const
	{
		return enemysprites;
	}

	const sf::Sprite &Enemy::GetSprite() const
	{
		return _enemySprite;
	}
}