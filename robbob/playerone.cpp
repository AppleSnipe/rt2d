/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file playerone.cpp
 *
 */


#include "playerone.h"
#include "collider.h"

PlayerOne::PlayerOne() : Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = RED;
	bool falling = false;
}

PlayerOne::~PlayerOne()
{

}

void PlayerOne::update(float deltaTime)
{
	// ###############################################################
	// Falling & Movement
	// ###############################################################

	if (!CubePlayer()) {

		if (!PlayerOne::updateGravity()) {
			this->position.y++;
		}
		else {
			if (input()->getKey(A)) {
				this->position.x -= 3;
			}
			if (input()->getKey(D)) {
				this->position.x += 3;
			}

			if (input()->getKeyDown(W)) {
				this->position.y;
			}
		}
	}
}

bool PlayerOne::updateGravity() {
	if (this->position.y >= 300) {
		return true;
	}
	else {
		return false;
	}

	
}