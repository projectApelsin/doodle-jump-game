#pragma once
#include "Entity.h"
#include "Doodler.h"

class SpringBoots : public Entity{
	int jumpBoost;
	bool isSpringBootsSpawn;
public:
	bool activeAbility;
	SpringBoots();
	
	const Point& getSpringBootsPosition() const;

	const Rectangle& getHitBoxSpringBootsPosition() const;

	int jumpBooster();

	void spawnSpringBoots();

	bool getIsSpringBootsSpawn();

	void setSpringBootsHitBox(int x, int y);

	void updateSpringBootsPositionY(int y);

	bool isDoodlerCollideSpringBoots(const Doodler& doodler);
};