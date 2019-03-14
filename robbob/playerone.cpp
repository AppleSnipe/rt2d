/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file playerone.cpp
 *
 */

#include "playerone.h"
#include "gamescene.h"

PlayerOne::PlayerOne() : BasicEntity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = RED;
	leftdown = false;
	rightdown = false;
	updown = false;
}

PlayerOne::~PlayerOne()
{

}

void PlayerOne::update(float deltaTime)
{
	/*------------------------------------------------------------------
				ALWAYS Put the entity update in an entity.
	------------------------------------------------------------------*/
	BasicEntity::update(deltaTime);


		
	/*------------------------------------------------------------------
						Check for grounded
	------------------------------------------------------------------*/
	if (pointcollision(Vector2(this->position.x, this->position.y + ((this->sprite()->height() * this->scale.y) / 2) + 1))) {
		grounded = true;
	}
	else {
		grounded = false;
	}


	/*------------------------------------------------------------------
						Input & Movement
	------------------------------------------------------------------*/
	if (this->grounded) {

		if (input()->getKeyDown(A)) {
			leftdown = true;
		}
		if (input()->getKeyDown(D)) {
			rightdown = true;
		}
		if (input()->getKeyDown(W)) {
			updown = true;
		}

		if (input()->getKeyUp(A)) {
			leftdown = false;
		}
		if (input()->getKeyUp(D)) {
			rightdown = false;
		}
		if (input()->getKeyUp(W)) {
			updown = false;
		}

		if (leftdown) {
			if (this->velocity.x > -this->maxSpeed) {
				this->velocity.x -= this->acceleration.x * deltaTime;
				if (this->velocity.x < -this->maxSpeed) {
					this->velocity.x = -this->maxSpeed;
				}
			}
		}

		if (rightdown) {
			if (this->velocity.x < this->maxSpeed) {
				this->velocity.x += this->acceleration.x * deltaTime;
				if (this->velocity.x > this->maxSpeed) {
					this->velocity.x = this->maxSpeed;
				}
			}
		}

		if (updown) {
			if (this->velocity.y > -this->maxJump) {
				this->velocity.y -= this->acceleration.y * deltaTime;
				if (this->velocity.y < -this->maxJump) {
					this->velocity.y = -this->maxJump;
				}
			}
		}

		if ((leftdown && rightdown) || (!leftdown && !rightdown)) {
			if (this->velocity.x < 0) {
				this->velocity.x += this->acceleration.x * deltaTime;
				if (this->velocity.x > 0) {
					this->velocity.x = 0;
				}
			}
			else if (this->velocity.x > 0) {
				this->velocity.x -= this->acceleration.x * deltaTime;
				if (this->velocity.x < 0) {
					this->velocity.x = 0;
				}
			}
		}
	}	


	/*------------------------------------------------------------------
							X collision
	------------------------------------------------------------------*/
	float sideplayerx = this->position.x + (((this->sprite()->width() * this->scale.x) / 2) * sign(this->velocity.x));
	float nextplayerx = sideplayerx + (this->velocity.x * deltaTime);

	if (pointcollision(Vector2(nextplayerx, this->position.y))) {
		nextplayerx = sideplayerx + sign(this->velocity.x);
		this->velocity.x = sign(this->velocity.x);
		int count = 0;
		int maxRecursions;
		if (this->velocity.x >= 0) {
			maxRecursions = int(std::ceil(velocity.x * deltaTime));
		}
		else {
			maxRecursions = int(std::floor(velocity.x * deltaTime));
		}
		while (!pointcollision(Vector2(nextplayerx, this->position.y)))
		{
			this->position.x += sign(this->velocity.x);
			this->position.x = floorf(this->position.x);
			nextplayerx = sideplayerx + sign(this->velocity.x);
			count++;
			if(count >= maxRecursions){
				break;
			}
		}
	}
	else {
		this->position.x += this->velocity.x * deltaTime;
	}


	/*------------------------------------------------------------------ 
							Y collision
	------------------------------------------------------------------*/
	float sideplayery = this->position.y + (((this->sprite()->height() * this->scale.y) / 2) * sign(this->velocity.y));
	float nextplayery = sideplayery + (this->velocity.y * deltaTime);

	if (pointcollision(Vector2(this->position.x, nextplayery))) {
		nextplayery = sideplayery + sign(this->velocity.y);
		this->velocity.y = sign(this->velocity.y);
		int count = 0;
		int maxRecursions;
		if (this->velocity.y >= 0) {
			maxRecursions = int(std::ceil(velocity.y * deltaTime));
		}
		else {
			maxRecursions = int(std::floor(velocity.y * deltaTime));
		}
		while (!pointcollision(Vector2(this->position.x, nextplayery)))
		{
			this->position.y += sign(this->velocity.y);
			this->position.y = floorf(this->position.y);
			nextplayery = sideplayery + sign(this->velocity.y);
			count++;
			if (count >= maxRecursions) {
				break;
			}
		}
	}
	else {
		this->position.y += this->velocity.y * deltaTime;
	}
}