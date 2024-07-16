#pragma once
#include "Framework.h"
#include "Entity.h"
#include "Const.h"

class PlatformBasic : public Entity  {
private:
	Sprite* platformBasicSprite = createSprite(PLATFORM_BASIC_PATH);
public:

	PlatformBasic(Point position, int width, int height)
		: Entity(position, width, height)
	{
		setSpriteSize(platformBasicSprite,PLATFORM_WIDTH, PLATFORM_HEIGHT);
	}
		
	virtual void drawPlatformBasic() {
		drawSprite(platformBasicSprite,hitBox.x,hitBox.y);
	}

	Point& getPlatformBasicPosition() {
		return position;
	}

	void setPlatformBasicPosition(int x, int y) {
		position.x = x;
		position.y = y;
		hitBox.x = x;
		hitBox.y = y;
	}
	void setPlatformBasicPositionYUpdate(int y) {
		position.y += y;
		hitBox.y += y;
	}
	Rectangle& getPlatformBasicHitBox() {
		return hitBox;
	}
};
