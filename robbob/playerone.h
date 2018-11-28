/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file playerone.cpp
 *
 */

#ifndef PLAYERONE_H
#define PLAYERONE_H

#include "basicentity.h"

/// @brief The MyEntity class is the Entity implementation.
class PlayerOne : public BasicEntity
{
public:

	/// @brief Constructor
	PlayerOne();
	/// @brief Destructor
	virtual ~PlayerOne();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
	bool updateGravity();


};

#endif /* MYENTITY_H */
