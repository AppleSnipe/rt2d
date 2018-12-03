/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file collider.h
 *
 */

#ifndef FLOOR_H
#define FLOOR_H

#include "basicentity.h"

class Floor : public BasicEntity
{
public:

	Floor();
	virtual ~Floor();

	virtual void update(float deltaTime);

private:
	/* add your private declarations */

};

#endif /* COLLIDER_H */
