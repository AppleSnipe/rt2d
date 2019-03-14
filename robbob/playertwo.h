/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file playertwo.h
 *
 */

#ifndef PLAYERTWO_H
#define PLAYERTWO_H

#include "basicentity.h"
#include <functional>

/// @brief The MyEntity class is the Entity implementation.
class PlayerTwo : public BasicEntity
{
public:
	void setPointCollision(std::function<bool(Vector2 pos)> value) { pointcollision = value; }
	/// @brief Constructor
	PlayerTwo();
	/// @brief Destructor
	virtual ~PlayerTwo();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	std::function<bool(Vector2 pos)> pointcollision = nullptr;
	bool leftdown;
	bool rightdown;
	bool updown;
};

#endif
