#pragma once
#include "Entity.h"
#include <math.h>

class Projectile : public Entity {
private:
	float dx, dy;
public:
	Projectile(Point point, int width, int height, float dx, float dy) 
		:Entity(point, width, height), dx(dx), dy(dy)
	{
		hitBox.x = point.x;
		hitBox.y = point.y;
		hitBox.width = width;
		hitBox.height = height;
	}

	Point& getProjectilePosition() {
		return position;
	}

	Rectangle& getProjectileHitBox() {
		return hitBox;
	}

	void setProjectilePosition(int x, int y) {
		position.x = x;
		position.y = y;
		hitBox.x = position.x;
		hitBox.y = position.y;
	}

	void updateProjectilePositionY(int dy) {
		position.y += dy;
		hitBox.y = position.y;
	}
	void updateProjectilePositionX(int dx) {
		position.x += dx;
		hitBox.x = position.x;
	}
	void updateVerticalShooting() {
		position.x += dx;
		if (dy > 0) {
			dy = dy * (-1);
		}
		position.y += dy;
	}
};