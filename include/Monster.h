#pragma once

#include "Entity.h"
#include "PlatformBasic.h"
#include "Projectile.h"
#include "Doodler.h"

class Monster : public Entity {
private:
	Rectangle hitBoxTop;
	bool monsterSpawn = false;
public:
	Monster();

	Monster(Point point, int width, int height);

	Rectangle& getMonsterHitBox();

	void setMonsterSpawn(bool spawn);

	void spawnMonster();

	bool getMonsterSpawn();

	void setMonsterPoint(int x, int y);

	void setMonsterPositionUpdateY(int dy);

	bool isMonsterHitBoxCollideDoodler(Doodler& doodler);

	bool isMonsterHitBoxCollideProjectile(Projectile& projectile);

	bool isMonsterHitBoxTopCollideDoodler(Doodler& doodler);
};