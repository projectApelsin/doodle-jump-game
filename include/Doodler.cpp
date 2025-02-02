#include "Doodler.h";

Doodler::Doodler():Entity(Point(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), 90, 90)
{
	hitBoxBottom.x = 0;
	hitBoxBottom.y = 0;

	doodlerStatus = Right;
}
Doodler::Doodler(Point point, int width, int height)
	:Entity(point, width, height)
{
	doodlerStatus = Right;

	hitBoxBottom.x = point.x + 5;
	hitBoxBottom.y = point.y + 90;
}
void Doodler::initializeDoodler() {
	position.x = WINDOW_WIDTH / 2;
	position.y = WINDOW_HEIGHT - 200;
	hitBox.width = DOODLER_WIDTH;
	hitBox.height = DOODLER_HEIGHT;
	hitBoxBottom.x = position.x + 5;
	hitBoxBottom.y = position.y + 80;
}

void Doodler::updateDoodlerPositionY(int y) {
	position.y += y;
	hitBox.y += y;
	hitBoxBottom.y += y;
}

void Doodler::updateDoodlerPositionX(int x){
	position.x += x;
	hitBox.y += x;
	hitBoxBottom.x += x;
}

void Doodler::setDoodlerStatus(const DoodleStatus& status) {
	doodlerStatus = status;
}

void Doodler::setDoodlerPositionX(int x) {
	position.x = x;
	hitBoxBottom.x = x;
}

void Doodler::setDoodlerPositionY(int y) {
	position.y = y;
	hitBoxBottom.y = y + 80;
}

void Doodler::updateHitBoxBottom(int x, int y) {
	if (position.x != x) position.x += x;
	if (position.y != y) position.y += y;
}

void Doodler::setHitBoxBottom(int x, int y) {
	position.x = x;
	position.y = y;
}

 const DoodleStatus& Doodler::getDoodlerStatus() const{
	return doodlerStatus;
}

const Point& Doodler::getDoodlerPosition() const{
	return position;
}

const Rectangle& Doodler::getHitBoxBottom() const{
	return hitBoxBottom;
}

const Rectangle& Doodler::getHitBox() const{
	return hitBox;
}

void Doodler::leftRightPosition(float deltaTime, bool doodlerOnRightHalf) {
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