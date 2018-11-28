/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file basicentity.cpp
 *
 */

#include "basicentity.h"

BasicEntity::BasicEntity() : Entity()
{
	
}


BasicEntity::~BasicEntity()
{

}

void BasicEntity::update(float deltaTime)
{

}

bool BasicEntity::CubePlayer(BasicEntity A, BasicEntity B) {
	if (
		A.position.x + A.scale.x >= B.position.x &&
		B.position.x + B.scale.x >= A.position.x &&
		A.position.y + A.scale.y >= A.position.y &&
		B.position.y + B.scale.y >= B.position.y) {
		return true;
	}
	else {
		return false;
	}
}