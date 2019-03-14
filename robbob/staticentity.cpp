/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file basicentity.cpp
 *
 */

#include <iostream>
#include "staticentity.h"

StaticEntity::StaticEntity() : Entity()
{
	std::cout << "Constructor BasicEntity" << std::endl;
	this->addSprite("assets/square.tga");

	this->totalwidth = this->scale.x * this->sprite()->width();
	this->totalheight = this->scale.y * this->sprite()->height();
}


StaticEntity::~StaticEntity()
{

}

void StaticEntity::update(float deltaTime)
{
	this->totalwidth = this->scale.x * this->sprite()->width();
	this->totalheight = this->scale.y * this->sprite()->height();
	this->sprite()->spriteposition.x = this->position.x - (totalwidth / 2);
	this->sprite()->spriteposition.y = this->position.y - (totalheight / 2);
}

int StaticEntity::sign(float i) {
	if (i > 0){ 
		return 1;
	}
	if (i < 0) {
		return -1;
	}
	return 0;
}

