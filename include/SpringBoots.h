#pragma once
#include "Entity.h"
#include "Doodler.h"

class SpringBoots : public Entity{
	int jumpBoost;
	bool isSpringBootsSpawn;
public:
	bool activeAbility;
	SpringBoots();
	
	Point& getSpringBootsPosition();

	Rectangle& getHitBoxSpringBootsPosition();

	int jumpBooster();

	void spawnSpringBoots();

	bool getIsSpringBootsSpawn();

	void setSpringBootsHitBox(int x, int y);

	void updateSpringBootsPositionY(int y);

	bool isDoodlerCollideSpringBoots(Doodler& doodler);
};