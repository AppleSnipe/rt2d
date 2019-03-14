/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file basicentity.h
 *
 */

#ifndef STATICENTITY_H
#define STATICENTITY_H

#include <rt2d/entity.h>

class StaticEntity : public Entity
{
public:

	int totalwidth;
	int totalheight;

	int sign(float i);

	StaticEntity();
	virtual ~StaticEntity();

	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* BASICENTITY_H */
