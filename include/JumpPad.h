#pragma once
#include "Entity.h"
#include "Doodler.h"
class JumpPad : public Entity {

public:
	bool isJumpPadSpawn = false;
	JumpPad()
		:Entity(Point(-100, -100), JUMP_PAD_WIDTH, JUMP_PAD_HEIGHT)
	{}

	JumpPad(Point& point, int width, int height) 
		: Entity(point,width,height)
	{}

	Point& getJumpPadPosition() {
		return position;
	}

	Rectangle& getJumpPadHitBox() {
		return hitBox;
	}

	void setJumpPadHitBox(int x, int y) {
		hitBox.x = x;
		hitBox.y = y;
		isJumpPadSpawn = false;
	}

	bool isDoodlerCollideJumpPad(Doodler& doodler) {
		if ((doodler.getHitBoxBottom().x > hitBox.x - 50)
			&& (doodler.getHitBoxBottom().x < hitBox.x + 50)
			&& (doodler.getHitBoxBottom().y > hitBox.y - 30)
			&& (doodler.getHitBoxBottom().y < hitBox.y + 10)) {
			return true;
		}

		return false;
	}

	void updateJumpPadPositionY(int dy) {
		hitBox.y += dy;
	}

	void spawnJumpPad() {
		isJumpPadSpawn = true;
	}

};