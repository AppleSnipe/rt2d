/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file playertwo.cpp
 *
 */

#include "playertwo.h"
#include "game.h"

PlayerTwo::PlayerTwo() : BasicEntity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = RED;
}

PlayerTwo::~PlayerTwo()
{

}

void PlayerTwo::update(float deltaTime)
{
	// ###############################################################
	// ALWAYS Put the entity update in an entity.
	// ###############################################################
	BasicEntity::update(deltaTime);

	// ###############################################################
	// Falling & Movement
	// ###############################################################


		if(!this->falling) {
			if (input()->getKey(Left)) {
				this->position.x -= 3;
			}
			if (input()->getKey(Right)) {
				this->position.x += 3;
			}
			if (input()->getKeyDown(Up)) {
				this->position.y -= 30;
			}
		}
}


