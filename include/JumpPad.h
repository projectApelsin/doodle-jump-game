#pragma once
#include "Entity.h"
#include "Doodler.h"
class JumpPad : public Entity {

public:
	bool isJumpPadSpawn = false;
	JumpPad();

	JumpPad(Point& point, int width, int height);

	Point& getJumpPadPosition();

	Rectangle& getJumpPadHitBox();

	void setJumpPadHitBox(int x, int y);

	bool isDoodlerCollideJumpPad(Doodler& doodler);

	void updateJumpPadPositionY(int dy);

	void spawnJumpPad();
};