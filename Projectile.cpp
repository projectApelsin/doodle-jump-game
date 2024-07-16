#include "Projectile.h"

Projectile::Projectile(Point point, int width, int height, float dx, float dy)
	:Entity(point, width, height), dx(dx), dy(dy)
{
	hitBox.x = point.x;
	hitBox.y = point.y;
	hitBox.width = width;
	hitBox.height = height;
}

Point& Projectile::getProjectilePosition() {
	return position;
}

Rectangle& Projectile::getProjectileHitBox() {
	return hitBox;
}

void Projectile::setProjectilePosition(int x, int y) {
	position.x = x;
	position.y = y;
	hitBox.x = position.x;
	hitBox.y = position.y;
}

void Projectile::updateProjectilePositionY(int dy) {
	position.y += dy;
	hitBox.y = position.y;
}

void Projectile::updateProjectilePositionX(int dx) {
	position.x += dx;
	hitBox.x = position.x;
}

void Projectile::updateVerticalShooting() {
	position.x += dx;
	if (dy > 0) {
		dy = dy * (-1);
	}
	position.y += dy;
}