#pragma once
#include "Framework.h"
#include "PlatformBasic.h"

class Doodler : public Entity {
protected:

	Rectangle hitBoxBottom;
	DoodleStatus doodlerStatus;
	unsigned int previousTime = getTickCount();

public:
	Doodler();
	Doodler(Point point, int width, int height);

	void initializeDoodler();

	void updateDoodlerPositionY(int y);
	
	void updateDoodlerPositionX(int x);

	void setDoodlerStatus(const DoodleStatus& status);

	void setDoodlerPositionX(int x);

	void setDoodlerPositionY(int y);

	void updateHitBoxBottom(int x, int y);

	void setHitBoxBottom(int x, int y);

	const DoodleStatus& getDoodlerStatus() const;

	const Point& getDoodlerPosition() const;

	const Rectangle& getHitBoxBottom() const;

	const Rectangle& getHitBox() const;

	void leftRightPosition(float deltaTime, bool doodlerOnRightHalf);

};