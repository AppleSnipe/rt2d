/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file playerone.cpp
 *
 */


#include "playerone.h"
#include "game.h"

PlayerOne::PlayerOne() : BasicEntity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = RED;
}

PlayerOne::~PlayerOne()
{

}

void PlayerOne::update(float deltaTime)
{
	// ###############################################################
	// ALWAYS Put the entity update in an entity.
	// ###############################################################
	BasicEntity::update(deltaTime);
	
	// ###############################################################
	// Falling & Movement
	// ###############################################################


		if (!this->falling) {
			if (input()->getKey(A)) {
				this->position.x -= 3;
			}
			if (input()->getKey(D)) {
				this->position.x += 3;
			}
			if (input()->getKeyDown(W)) {
				this->position.y -= 30;
			}
		}
	
}