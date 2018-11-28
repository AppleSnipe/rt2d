/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file basicentity.h
 *
 */

#ifndef BASICENTITY_H
#define BASICENTITY_H

#include <rt2d/entity.h>

class BasicEntity : public Entity
{
public:
	static bool CubePlayer(BasicEntity A, BasicEntity B);

	BasicEntity();
	virtual ~BasicEntity();

	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* BASICENTITY_H */
