#include "PlatformBasic.h"

PlatformBasic::PlatformBasic(Point position, int width, int height)
	: Entity(position, width, height)
{
	setSpriteSize(platformBasicSprite, PLATFORM_WIDTH, PLATFORM_HEIGHT);
}

void PlatformBasic::drawPlatformBasic() {
	drawSprite(platformBasicSprite, hitBox.x, hitBox.y);
}

Point& PlatformBasic::getPlatformBasicPosition() {
	return position;
}

void PlatformBasic::setPlatformBasicPosition(int x, int y) {
	position.x = x;
	position.y = y;
	hitBox.x = x;
	hitBox.y = y;
}

void PlatformBasic::setPlatformBasicPositionYUpdate(int y) {
	position.y += y;
	hitBox.y += y;
}

Rectangle& PlatformBasic::getPlatformBasicHitBox() {
	return hitBox;
}