#include "Monster.h"

Monster::Monster()
	: Entity(Point(-100, -100), 0, 0)
{
	hitBoxTop.x = hitBox.x;
	hitBoxTop.y = hitBox.y - 70;
	hitBoxTop.width = hitBox.width;
	hitBoxTop.height = hitBox.height - 70;
}

Monster::Monster(Point point, int width, int height)
	: Entity(point, width, height)
{
	hitBox.x = point.x;
	hitBox.y = point.y;
	hitBoxTop.x = point.x;
	hitBoxTop.y = point.y - 70;
}

const Rectangle& Monster::getMonsterHitBox() const{
	return hitBox;
}

void Monster::setMonsterSpawn(bool spawn) {
	monsterSpawn = spawn;
}

void Monster::spawnMonster() {
	monsterSpawn = true;
}

bool Monster::getMonsterSpawn() {
	return monsterSpawn;
}

void Monster::setMonsterPoint(int x, int y) {
	hitBox.x = x;
	hitBox.y = y;
	hitBoxTop.x = x;
	hitBoxTop.y = y - 60;
	monsterSpawn = false;

}

void Monster::setMonsterPositionUpdateY(int dy) {
	hitBox.y += dy;
	hitBoxTop.y += dy;
}

bool Monster::isMonsterHitBoxCollideDoodler(const Doodler& doodler) {

	if ((doodler.getDoodlerPosition().x > hitBox.x - 60)
		&& (doodler.getDoodlerPosition().x < hitBox.x + 60)
		&& (doodler.getDoodlerPosition().y > hitBox.y - 30)
		&& doodler.getDoodlerPosition().y < hitBox.y + 30) {
		return true;
	}
	return false;
}

bool Monster::isMonsterHitBoxCollideProjectile(const Projectile& projectile) {

	if ((projectile.getProjectilePosition().x > hitBox.x - 80)
		&& (projectile.getProjectilePosition().x < hitBox.x + 80)
		&& (projectile.getProjectilePosition().y > hitBox.y - 40)
		&& projectile.getProjectilePosition().y < hitBox.y + 20) {
		return true;
	}
	return false;
}

bool Monster::isMonsterHitBoxTopCollideDoodler(const Doodler& doodler) {
	if ((doodler.getHitBoxBottom().x > hitBoxTop.x - 50)
		&& (doodler.getHitBoxBottom().x < hitBoxTop.x + 50)
		&& (doodler.getHitBoxBottom().y > hitBoxTop.y - 10)
		&& (doodler.getHitBoxBottom().y < hitBoxTop.y + 20)) {
		return true;
	}

	return false;
}