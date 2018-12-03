/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file playertwo.h
 *
 */

#ifndef PLAYERTWO_H
#define PLAYERTWO_H

#include "basicentity.h"

/// @brief The MyEntity class is the Entity implementation.
class PlayerTwo : public BasicEntity
{
public:
	/// @brief Constructor
	PlayerTwo();
	/// @brief Destructor
	virtual ~PlayerTwo();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
	
};

#endif /* MYENTITY_H */
