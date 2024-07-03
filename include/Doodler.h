#pragma once
#include "Framework.h"
#include "PlatformBasic.h"

class Doodler : public Entity {
protected:

	Rectangle hitBoxBottom;
	DoodleStatus doodlerStatus;
	unsigned int previousTime = getTickCount();

public:
	Doodler() 
		:Entity(Point(WINDOW_WIDTH/2,WINDOW_HEIGHT/2), 90, 90)
	{
		hitBoxBottom.x = 0;
		hitBoxBottom.y = 0;

		doodlerStatus = Right;
	}
	Doodler(Point point, int width, int height)
		:Entity(point, width, height)
	{
		doodlerStatus = Right;

		hitBoxBottom.x = point.x + 5;
		hitBoxBottom.y = point.y + 90;
	}

	void initializeDoodler() {
		position.x = WINDOW_WIDTH/2;
		position.y = WINDOW_HEIGHT - 200;
		hitBox.width = DOODLER_WIDTH;
		hitBox.height = DOODLER_HEIGHT;
		hitBoxBottom.x = position.x + 5;
		hitBoxBottom.y = position.y + 80;
	}

	void updateDoodlerPositionY(int y) {
		position.y += y;
		hitBox.y += y;
		hitBoxBottom.y += y;
	}

	
	void updateDoodlerPositionX(int x) {
		position.x += x;
		hitBox.y += x;
		hitBoxBottom.x += x;
	}

	bool doodlerLost(bool isLost) {
		if (isLost) {
			return true;
		}
		return false;
	}

	void setDoodlerStatus(const DoodleStatus& status) {
		doodlerStatus = status;
	}

	void setDoodlerPositionX(int x) {
		position.x = x;
		hitBoxBottom.x = x;

	}
	void setDoodlerPositionY(int y) {
		position.y = y;
		hitBoxBottom.y = y + 80;
	}

	DoodleStatus& getDoodlerStatus() {
		return doodlerStatus;
	}

	Point& getDoodlerPosition() {
		return position;
	}

	Rectangle& getHitBoxBottom() {
		return hitBoxBottom;
	}
	
	Rectangle& getHitBox() {
		return hitBox;
	}

	void leftRightPosition(float& deltaTime, bool& doodlerOnRightHalf) {
		float vx = DOODLE_VX;
		if (doodlerOnRightHalf) {
			vx = vx * 1.5;
		}
		switch (doodlerStatus)
		{
		case Right: { 
			updateDoodlerPositionX(vx * deltaTime);
		}break;
		case Left: {
			updateDoodlerPositionX(-vx * deltaTime);
		}break;
		default:
			break;
		}
	}

};