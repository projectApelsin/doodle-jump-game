#include "JumpPad.h"

JumpPad::JumpPad()
	:Entity(Point(-100, -100), JUMP_PAD_WIDTH, JUMP_PAD_HEIGHT)
{}

JumpPad::JumpPad(Point& point, int width, int height)
	: Entity(point, width, height)
{}

Point& JumpPad::getJumpPadPosition() {
	return position;
}

Rectangle& JumpPad::getJumpPadHitBox() {
	return hitBox;
}

void JumpPad::setJumpPadHitBox(int x, int y) {
	hitBox.x = x;
	hitBox.y = y;
	isJumpPadSpawn = false;
}

bool JumpPad::isDoodlerCollideJumpPad(Doodler& doodler) {
	if ((doodler.getHitBoxBottom().x > hitBox.x - 50)
		&& (doodler.getHitBoxBottom().x < hitBox.x + 50)
		&& (doodler.getHitBoxBottom().y > hitBox.y - 30)
		&& (doodler.getHitBoxBottom().y < hitBox.y + 10)) {
		return true;
	}

	return false;
}

void JumpPad::updateJumpPadPositionY(int dy) {
	hitBox.y += dy;
}

void JumpPad::spawnJumpPad() {
	isJumpPadSpawn = true;
}