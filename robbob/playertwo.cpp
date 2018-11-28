/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file playertwo.cpp
 *
 */

#include "playertwo.h"
#include "collider.h"

PlayerTwo::PlayerTwo() : Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = RED;
	bool falling = false;
}

PlayerTwo::~PlayerTwo()
{

}

void PlayerTwo::update(float deltaTime)
{
	// ###############################################################
	// Falling & Movement
	// ###############################################################

	if
	if (!PlayerTwo::updateGravity()) {
		this->position.y++;
	}
	else {
		if (input()->getKey(Left)) {
			this->position.x -= 3;
		}
		if (input()->getKey(Right)) {
			this->position.x += 3;
		}

		if (input()->getKeyDown(Up)) {
			this->position.y;
		}
	}
}

bool PlayerTwo::updateGravity() {
	if (this->position.y >= 600) {
		return true;
	}
	else {
		return false;
	}
}


