/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file collider.cpp
 *
 */

#include "floor.h"

Floor::Floor() : BasicEntity()
{

}


Floor::~Floor()
{

}

void Floor::update(float deltaTime)
{
	/*------------------------------------------------------------------
				ALWAYS Put the entity update in an entity.
	------------------------------------------------------------------*/
	BasicEntity::update(deltaTime);
}


