/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file game.cpp
 *
 */

#include <fstream>
#include <sstream>

#include "game.h"


Game::Game() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	
	cube = new BasicEntity();
	cube->addSprite("assets/square.tga");
	cube->position = Point2(10, 10);
	cube->scale = Point(30, 30);

	background = new BasicEntity();
	background->position = Point2(20, 20);
	background->scale = Point(100.0f, 100.0f);
	background->sprite()->color = WHITE;

	playerone = new PlayerOne();
	playerone->position = Point2(20, 20);
	playerone->scale = Point(0.2f, 0.2f);

	playertwo = new PlayerTwo();
	playertwo->position = Point2(20, 20);
	playertwo->scale = Point(0.2f, 0.2f);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(cube);
	this->addChild(background);
	this->addChild(playerone);
	this->addChild(playertwo);
	
}

Game::~Game()
{
	// deconstruct and delete the Tree
	this->removeChild(cube);
	this->removeChild(background);
	this->removeChild(playerone);
	this->removeChild(playertwo);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete cube;
	delete background;
	delete playerone;
	delete playertwo;
}

void Game::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = playerone->sprite()->color;
		playerone->sprite()->color = Color::rotate(color, 0.01f);
		playertwo->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}
}

/*
std::vector<std::vector<int> > MyArray;

std::vector<int>;

int map[6][6] = { {0, 0, 0, 0, 0, 0},
				  {0, 2, 1, 2, 1, 0},
				  {0, 1, 2, 1, 2, 0},
				  {0, 1, 2, 2, 1, 0},
				  {0, 1, 3, 1, 2, 0},
				  {0, 0, 0, 0, 0, 0} };

				  */