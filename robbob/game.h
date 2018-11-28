/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file game.h
 *
 */

#ifndef GAME_H
#define GAME_H

#include <glm/glm.hpp>
#include <rt2d/scene.h>
#include <rt2d/texture.h>
#include <rt2d/color.h>
#include <rt2d/pointx.h>

#include "playerone.h"
#include "playertwo.h"
#include "basicentity.h"
#include "collider.h"

/// @brief The MyScene class is the Scene implementation.
class Game : public Scene
{
public:
	/// @brief Constructor
	Game();
	/// @brief Destructor
	virtual ~Game();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen
	BasicEntity* cube;
	BasicEntity* background;
	PlayerOne* playerone;
	PlayerTwo* playertwo;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* SCENE00_H */
