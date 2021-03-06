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

	this->grounded = true;
	this->velocity = Vector2(0,0);
	this->acceleration = Vector2(1000,10);
	this->maxJump = 100;
	this->maxSpeed = 10000;
	this->totalwidth = this->scale.x * this->sprite()->width();
	this->totalheight = this->scale.y * this->sprite()->height();
	this->gravity = 20;
	this->maxgravity = 100;
}


BasicEntity::~BasicEntity()
{

}

void BasicEntity::update(float deltaTime)
{
	this->totalwidth = this->scale.x * this->sprite()->width();
	this->totalheight = this->scale.y * this->sprite()->height();
	this->sprite()->spriteposition.x = this->position.x - (totalwidth / 2);
	this->sprite()->spriteposition.y = this->position.y - (totalheight / 2);

	if (velocity.y + gravity > maxgravity) {
		velocity.y = maxgravity;
	} else {
		this->velocity.y += gravity;
	}
	
}

int BasicEntity::sign(float i) {
	if (i > 0){ 
		return 1;
	}
	if (i < 0) {
		return -1;
	}
	return 0;
}

