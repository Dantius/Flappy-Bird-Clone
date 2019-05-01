#include "stdafx.h"

#include "Pipe.hpp"
#include <iostream>

namespace Sonar {

//constructor
	Pipe::Pipe(GameDataRef data) : _data(data)
	{
		_landHeight = _data->asset.GetTexture("Land").getSize().y;

		_pipeSpawnYOffset = 0;
	}
//generacion de pipe abajo
	void Pipe::SpawnBottomPipe()
	{
		sf::Sprite sprite(_data->asset.GetTexture("Pipe Down"));

		sprite.setPosition(_data->window.getSize().x, - _pipeSpawnYOffset);

		pipeSprites.push_back(sprite);

	}

//generacion de pipe arriba
	void Pipe::SpawnTopPipe()
	{
		
		sf::Sprite sprite(_data->asset.GetTexture("Pipe Up")
		);
		sprite.setPosition(_data->window.getSize().x, _data->
			window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset );

		pipeSprites.push_back(sprite);
	}

//generacion de pipe invisible

	void Pipe::SpawnInvisiblePipe()
	{
		sf::Sprite sprite(_data->asset.GetTexture("Pipe Up"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);

		sprite.setColor(sf::Color(0, 0, 0, 0) );
		pipeSprites.push_back(sprite);
	}

//generacion de pipe para el resultado

	void Pipe::SpawnScoringPipe()
	{
		sf::Sprite sprite(_data->asset.GetTexture("Scoring Pipe"));
		sprite.setPosition(_data->window.getSize().x,0);

		scoringPipes.push_back(sprite);
	}

//movimiento de pipes

	void Pipe::MovePipes(float dt)
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			if (pipeSprites.at(i).getPosition().x < 0 - 
				pipeSprites.at(i).getGlobalBounds().width)
			{
				pipeSprites.erase(pipeSprites.begin() + i);
			}
			float movement = PIPE_MOVEMENT_SPEED * dt;

			pipeSprites.at(i).move(-movement, 0);
		}

		for (unsigned short int i = 0; i < scoringPipes.size(); i++)
		{
			if (scoringPipes.at(i).getPosition().x < 0 -
				scoringPipes.at(i).getGlobalBounds().width)
			{
				scoringPipes.erase(scoringPipes.begin() + i);
			}
			float movement = PIPE_MOVEMENT_SPEED * dt;

			scoringPipes.at(i).move(-movement, 0);
		}

	}
// dibujar las pipes

	void Pipe :: DrawPipes()
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			_data->window.draw(pipeSprites.at(i));
		}
	}
// numero aleatorio para genracion de altura

	void Pipe::RandomisePipeOffset()
	{
		_pipeSpawnYOffset = rand() % (_landHeight + 1);
	}

	const std::vector<sf::Sprite> &Pipe::GetSprites() const
	{
		return pipeSprites;
	}

	std::vector<sf::Sprite> &Pipe::GetScoringSprites() 
	{
		return scoringPipes;
	}
}