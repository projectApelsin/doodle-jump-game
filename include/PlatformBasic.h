#pragma once
#include "Framework.h"
#include "Entity.h"
#include "Const.h"

class PlatformBasic : public Entity  {
private:
	Sprite* platformBasicSprite = createSprite(PLATFORM_BASIC_PATH);
public:

	PlatformBasic(Point position, int width, int height);
		
	virtual void drawPlatformBasic();

	Point& getPlatformBasicPosition();

	void setPlatformBasicPosition(int x, int y);

	void setPlatformBasicPositionYUpdate(int y);

	Rectangle& getPlatformBasicHitBox();
};
