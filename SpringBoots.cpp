#include "SpringBoots.h"

SpringBoots::SpringBoots()
	:Entity(Point(-100, -100), SPRING_BOOTS_WIDTH, SPRING_BOOTS_HEIGHT), jumpBoost(2.5), isSpringBootsSpawn(false), activeAbility(false)
{}

Point& SpringBoots::getSpringBootsPosition() {
	return position;
}

Rectangle& SpringBoots::getHitBoxSpringBootsPosition() {
	return hitBox;
}

int SpringBoots::jumpBooster() {
	return jumpBoost;
}

void SpringBoots::spawnSpringBoots() {
	isSpringBootsSpawn = true;
}

bool SpringBoots::getIsSpringBootsSpawn() {
	return isSpringBootsSpawn;
}

void SpringBoots::setSpringBootsHitBox(int x, int y) {
	hitBox.x = x;
	hitBox.y = y;
	isSpringBootsSpawn = false;
}


void SpringBoots::updateSpringBootsPositionY(int y) {
	hitBox.y += y;
}

bool SpringBoots::isDoodlerCollideSpringBoots(Doodler& doodler) {
	if ((doodler.getHitBoxBottom().x > hitBox.x - 50)
		&& (doodler.getHitBoxBottom().x < hitBox.x + 50)
		&& (doodler.getHitBoxBottom().y > hitBox.y - 30)
		&& (doodler.getHitBoxBottom().y < hitBox.y + 10)) {
		activeAbility = true;
		std::cout << "chinaren\n";
		return true;
	}

	return false;
}