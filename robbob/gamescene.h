/**
 * Copyright 2018 Nick Struik <nick_struik@outlook.com>
 *
 * @file game.h
 *
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <glm/glm.hpp>
#include <rt2d/scene.h>
#include <rt2d/texture.h>
#include <rt2d/color.h>
#include <rt2d/pointx.h>

#include "playerone.h"
#include "playertwo.h"
#include "basicentity.h"
#include "staticentity.h"

/// @brief The MyScene class is the Scene implementation.
class GameScene : public Scene
{
public:
	
	/// @brief Constructor
	GameScene();
	/// @brief Destructor
	virtual ~GameScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	static bool AABB(BasicEntity* A, StaticEntity* B);
	bool PointCollision(Vector2 pos);
	static void updateGravity(BasicEntity* A);

private:
	/// @brief the rotating square in the middle of the screen
	std::vector <StaticEntity*> collidables;
	StaticEntity* wall1;
	StaticEntity* wall2;
	StaticEntity* floor1;
	StaticEntity* floor2;
	StaticEntity* floor3;
	StaticEntity* background;
	PlayerOne* playerone;
	PlayerTwo* playertwo;
	/// @brief a Timer to rotate the color every n seconds
};

#endif /* SCENE00_H */
