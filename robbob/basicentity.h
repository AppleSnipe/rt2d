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

	int totalwidth;
	int totalheight;

	Vector2 velocity;
	Vector2 acceleration;

	int maxJump;
	int maxSpeed;

	int sign(float i);

	bool grounded;

	BasicEntity();
	virtual ~BasicEntity();

	virtual void update(float deltaTime);

private:
	/* add your private declarations */
	float gravity;
	float maxgravity;
};

#endif /* BASICENTITY_H */
