// Flappy Bird.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Game.hpp"
#include <SFML\Graphics.hpp>
#include "DEFINITIONS.hpp"


int main()
{
	Sonar::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
	return EXIT_SUCCESS;
}

