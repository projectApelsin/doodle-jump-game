#pragma once

#include "Entity.h"
#include "PlatformBasic.h"
#include "Projectile.h"

class Monster : public Entity {
private:
	Rectangle hitBoxTop;
	bool monsterSpawn = false;
public:
	Monster() 
		: Entity(Point(-100,-100),0,0)
	{
		hitBoxTop.x = hitBox.x;
		hitBoxTop.y = hitBox.y - 70;
		hitBoxTop.width = hitBox.width;
		hitBoxTop.height = hitBox.height - 70;
	}

	Monster(Point point, int width, int height)
		: Entity(point, width, height)
	{
		hitBox.x = point.x;
		hitBox.y = point.y;
		hitBoxTop.x = point.x;
		hitBoxTop.y = point.y - 70;
	}

	Rectangle& getMonsterHitBox() {
		return hitBox;
	}

	void setMonsterSpawn(bool spawn) {
		monsterSpawn = spawn;
	}

	void spawnMonster() {
		monsterSpawn = true;
	}

	bool getMonsterSpawn() {
		return monsterSpawn;
	}

	void setMonsterPoint(int x, int y) {
		hitBox.x = x;
		hitBox.y = y;
		hitBoxTop.x = x;
		hitBoxTop.y = y - 60;
		monsterSpawn = false;

	}

	void setMonsterPositionUpdateY(int dy) {
		hitBox.y += dy;
		hitBoxTop.y += dy;
	}

	bool isMonsterHitBoxCollideDoodler(Doodler& doodler) {

		if ((doodler.getDoodlerPosition().x > hitBox.x - 60)
			&& (doodler.getDoodlerPosition().x < hitBox.x + 60)
			&& (doodler.getDoodlerPosition().y > hitBox.y - 30)
			&& doodler.getDoodlerPosition().y < hitBox.y + 30) {
			return true;
		}
		return false;
	}

	bool isMonsterHitBoxCollideProjectile(Projectile& projectile) {

		if ((projectile.getProjectilePosition().x > hitBox.x - 80)
			&& (projectile.getProjectilePosition().x < hitBox.x + 80)
			&& (projectile.getProjectilePosition().y > hitBox.y - 40)
			&& projectile.getProjectilePosition().y < hitBox.y + 20) {
			return true;
		}
		return false;
	}

	bool isMonsterHitBoxTopCollideDoodler(Doodler& doodler) {
		if ((doodler.getHitBoxBottom().x > hitBoxTop.x - 50)
			&& (doodler.getHitBoxBottom().x < hitBoxTop.x + 50)
			&& (doodler.getHitBoxBottom().y > hitBoxTop.y - 10)
			&& (doodler.getHitBoxBottom().y < hitBoxTop.y + 20)) {
			return true;
		}
		
		return false;
	}
};