#pragma once
#include "Entity.h"
#include "Doodler.h"

class SpringBoots : public Entity{
	int jumpBoost;
	bool isSpringBootsSpawn;
public:
	bool activeAbility;
	SpringBoots() 
		:Entity(Point(-100,-100), SPRING_BOOTS_WIDTH, SPRING_BOOTS_HEIGHT), jumpBoost(2.5), isSpringBootsSpawn(false), activeAbility(false)
	{

	}

	Point& getSpringBootsPosition() {
		return position;
	}

	Rectangle& getHitBoxSpringBootsPosition() {
		return hitBox;
	}

	int jumpBooster() {
		return jumpBoost;
	}

	void spawnSpringBoots() {
		isSpringBootsSpawn = true;
	}

	bool getIsSpringBootsSpawn() {
		return isSpringBootsSpawn;
	}

	void setSpringBootsHitBox(int x, int y) {
		hitBox.x = x;
		hitBox.y = y;
		isSpringBootsSpawn = false;
	}

	void updateSpringBootsPositionY(int y) {
		hitBox.y += y;
	}

	bool isDoodlerCollideSpringBoots(Doodler& doodler) {
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
};