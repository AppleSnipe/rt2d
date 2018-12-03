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

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	
	
	background = new BasicEntity();
	background->position = Point2(20, 20);
	background->scale = Point(100.0f, 100.0f);
	background->sprite()->color = WHITE;

	floor = new BasicEntity();
	floor->addSprite("assets/square.tga");
	floor->sprite()->color = BLACK;
	floor->position = Point2(120, 300);
	floor->scale = Point(2.0f, 1.0f);

	playerone = new PlayerOne();
	playerone->sprite()->color = BLUE;
	playerone->position = Point2(80, 80);
	playerone->scale = Point(0.2f, 0.2f);

	playertwo = new PlayerTwo();
	playertwo->position = Point2(20, 20);
	playertwo->scale = Point(0.2f, 0.2f);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(background);
	this->addChild(floor);
	this->addChild(playerone);
	this->addChild(playertwo);
	
}

Game::~Game()
{
	// deconstruct and delete the Tree
	this->removeChild(background);
	this->removeChild(floor);
	this->removeChild(playerone);
	this->removeChild(playertwo);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete background;
	delete floor;
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
	// Check for collision
	// ###############################################################
	if (AABB(this->playerone, this->floor)) {
		this->playerone->falling = false;
	}
	else {
		this->playerone->falling = true;
	}

	if (AABB(this->playertwo, this->floor)) {
		this->playertwo->falling = false;
	}
	else {
		this->playertwo->falling = true;
	}

	updateGravity(this->playerone);
	updateGravity(this->playertwo);
}

bool Game::AABB(BasicEntity* A, BasicEntity* B) {
	if (
		A->x + A->totalwidth >= B->x &&
		B->x + B->totalwidth >= A->x &&
		A->y + A->totalheight >= B->y &&
		B->y + B->totalheight >= A->y) {
		return true;
	}
	else {
		return false;
	}
}

void Game::updateGravity(BasicEntity* A) {
	if (A->falling == true) {
		A->position.y++;
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