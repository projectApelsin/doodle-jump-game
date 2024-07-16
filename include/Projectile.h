#pragma once
#include "Entity.h"
#include <math.h>

class Projectile : public Entity {
private:
	float dx, dy;
public:
	Projectile(Point point, int width, int height, float dx, float dy);

	const Point& getProjectilePosition() const;

	const Rectangle& getProjectileHitBox() const;

	void setProjectilePosition(int x, int y);

	void updateProjectilePositionY(int dy);

	void updateProjectilePositionX(int dx);

	void updateVerticalShooting();
};