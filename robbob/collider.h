/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file collider.h
 *
 */

#ifndef COLLIDER_H
#define COLLIDER_H

#include <rt2d/entity.h>
#include "basicentity.h"

class Collider : public Entity
{
public:
	static bool CubePlayer(BasicEntity A, BasicEntity B);

	Collider();
	virtual ~Collider();

	virtual void update(float deltaTime);

private:
	/* add your private declarations */

};

#endif /* COLLIDER_H */
