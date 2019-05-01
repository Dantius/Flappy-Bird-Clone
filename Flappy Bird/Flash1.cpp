#include "stdafx.h"
#include "Flash1.hpp"


namespace Sonar {

	Flash1::Flash1(GameDataRef data) : _data(data)
	{
		_shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
		_shape.setFillColor(sf::Color(255, 255, 255, 0));


		_flashOn = true;

	}

	void Flash1::Show(float dt)
	{
		if (_flashOn)
		{
			int alpha = (int)_shape.getFillColor().a + (FLASH_SPEED*dt);

			if (alpha >= 255.0f)
			{
				alpha = 255.0f;
				_flashOn = false;
			}

			_shape.setFillColor(sf::Color(255, 255, 255, alpha));
		}
		else
		{
			int alpha = (int)_shape.getFillColor().a + (FLASH_SPEED*dt);

			if (alpha >= 0.0f)
			{
				alpha = 0.0f;
				_flashOn = false;
			}

			_shape.setFillColor(sf::Color(255, 255, 255, alpha));
		}
	}


	void Flash1::Draw()
	{
		_data->window.draw(_shape);
	}

}