/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file basicentity.cpp
 *
 */

#include <iostream>
#include "basicentity.h"

BasicEntity::BasicEntity() : Entity()
{
	std::cout << "Constructor BasicEntity" << std::endl;
	this->addSprite("assets/square.tga");
	this->x = 42;
	this->y = 42;
	this->falling = false;
}


BasicEntity::~BasicEntity()
{

}

void BasicEntity::update(float deltaTime)
{
	this->totalwidth = this->scale.x * this->sprite()->width();
	this->totalheight = this->scale.y * this->sprite()->height();
	this->x = this->position.x - (totalwidth / 2);
	this->y = this->position.y - (totalheight / 2);
}

