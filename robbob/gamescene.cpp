/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file game.cpp
 *
 */

#include <fstream>
#include <sstream>

#include "gamescene.h"
#include <functional>


GameScene::GameScene() : Scene()
{

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	std::cout << "Screen Contructor" << std::endl;
	std::cout << "Width: " << SWIDTH << std::endl;
	std::cout << "Height: " << SHEIGHT << std::endl;

	background = new StaticEntity();
	background->position = Point2(20, 20);
	background->scale = Point(100.0f, 100.0f);
	background->sprite()->color = WHITE;

	wall1 = new StaticEntity();
	wall1->addSprite("assets/square.tga");
	wall1->sprite()->color = BLACK;
	wall1->position = Point2(0, 0);
	wall1->scale = Point(0.5, 20);
	collidables.push_back(wall1);

	wall2 = new StaticEntity();
	wall2->addSprite("assets/square.tga");
	wall2->sprite()->color = BLACK;
	wall2->position = Point2(1280, 0);
	wall2->scale = Point(0.5, 20);
	collidables.push_back(wall2);
	
	floor1 = new StaticEntity();
	floor1->addSprite("assets/square.tga");
	floor1->sprite()->color = BLACK;
	floor1->position = Point2(0, 360);
	floor1->scale = Point(20, 0.5);
	collidables.push_back(floor1);

	floor2 = new StaticEntity();
	floor2->addSprite("assets/square.tga");
	floor2->sprite()->color = BLACK;
	floor2->position = Point2(0, 0);
	floor2->scale = Point(20, 0.5);
	collidables.push_back(floor2);

	floor3 = new StaticEntity();
	floor3->addSprite("assets/square.tga");
	floor3->sprite()->color = BLACK;
	floor3->position = Point2(0, 720);
	floor3->scale = Point(20, 0.5);
	collidables.push_back(floor3);

	playerone = new PlayerOne();
	playerone->sprite()->color = BLUE;
	playerone->position = Point2(120, 80);
	playerone->scale = Point(0.3f, 0.3f);
	playerone->setPointCollision(std::bind(&GameScene::PointCollision, this, std::placeholders::_1));

	playertwo = new PlayerTwo();
	playertwo->position = Point2(120, 420);
	playertwo->scale = Point(0.3f, 0.3f);
	playertwo->setPointCollision(std::bind(&GameScene::PointCollision, this, std::placeholders::_1));

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(background);
	this->addChild(wall1);
	this->addChild(wall2);
	this->addChild(floor1);
	this->addChild(floor2);
	this->addChild(floor3);
	this->addChild(playerone);
	this->addChild(playertwo);
	
}

GameScene::~GameScene()
{
	// deconstruct and delete the Tree
	this->removeChild(background);
	this->removeChild(wall1);
	this->removeChild(wall2);
	this->removeChild(floor1);
	this->removeChild(floor2);
	this->removeChild(floor3);
	this->removeChild(playerone);
	this->removeChild(playertwo);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete background;
	delete wall1;
	delete wall2;
	delete floor1;
	delete floor2;
	delete floor3;
	delete playerone;
	delete playertwo;
}

void GameScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	

	//std::cout << playerone->velocity.x<< std::endl;
	//updateGravity(this->playerone);
	//updateGravity(this->playertwo);
}

bool GameScene::AABB(BasicEntity* A, StaticEntity* B) {
	if (
		A->sprite()->spriteposition.x + A->totalwidth >= B->sprite()->spriteposition.x &&
		B->sprite()->spriteposition.x + B->totalwidth >= A->sprite()->spriteposition.x &&
		A->sprite()->spriteposition.y + A->totalheight >= B->sprite()->spriteposition.y &&
		B->sprite()->spriteposition.y + B->totalheight >= A->sprite()->spriteposition.y) {
		return true;
	}
	else {
		return false;
	}
}

bool GameScene::PointCollision(Vector2 pos) {
	for (int i = 0; i < collidables.size(); i++) {
		if (
			collidables[i]->sprite()->spriteposition.x + collidables[i]->totalwidth >= pos.x &&
			pos.x >= collidables[i]->sprite()->spriteposition.x &&
			collidables[i]->sprite()->spriteposition.y + collidables[i]->totalheight >= pos.y &&
			pos.y >= collidables[i]->sprite()->spriteposition.y) {
			return true;
		}
	}
	return false;
}


void GameScene::updateGravity(BasicEntity* A) {
	if (A->grounded == false) {
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