#include "PlayerManager.h"

void PlayerManager::initializeManager() {
	spritesManager.emplace_back(createSprite(DOODLE_RIGHT_PATH));
	spritesManager.emplace_back(createSprite(DOODLE_LEFT_PATH));
	spritesManager.emplace_back(createSprite(DOODLE_TOP_PATH));
	spritesManager.emplace_back(createSprite(DOODLE_TRUNK_PATH));
	spritesManager.emplace_back(createSprite(MONSTER_PATH));
	spritesManager.emplace_back(createSprite(PROJECTILE_PATH));
	spritesManager.emplace_back(createSprite(JUMP_PAD_PATH));
	spritesManager.emplace_back(createSprite(SPRING_BOOTS_LEFT_PATH));
	spritesManager.emplace_back(createSprite(SPRING_BOOTS_PATH));
	doodler.initializeDoodler();
	if (WINDOW_HEIGHT / 2 < 380) screenUpdateBorder = 200;
}

void PlayerManager::doodleShootProjectile(int& x, int& y) {
	int xRelative = x - doodler.getDoodlerPosition().x;
	int yRelative = y - doodler.getDoodlerPosition().y;

	// length vector
	float length = sqrt(xRelative * xRelative + yRelative * yRelative);

	// normalize vector
	float normalizedX = xRelative / length;
	float normalizedY = yRelative / length;

	// end coordinates to create
	int projectileX = doodler.getDoodlerPosition().x;
	int projectileY = doodler.getDoodlerPosition().y - 20;

	projectiles.emplace_back(Point(projectileX, projectileY), PROJECTILE_WIDTH, PROJECTILE_HEIGHT, normalizedX * 20, normalizedY * 20);
}

void PlayerManager::updateProjectilePosition(int speed, int deltaTime) {
	for (auto& projectile : projectiles) {
		if (projectile.getProjectilePosition().x > 600) {
			projectile.setProjectilePosition(0, projectile.getProjectilePosition().y);
		}
		else if (projectile.getProjectilePosition().x < 0) projectile.setProjectilePosition(600, projectile.getProjectilePosition().y);

		if (projectile.getProjectilePosition().y < 0) {
			projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(), [](Projectile& p) {
				return p.getProjectilePosition().y < 0 || p.getProjectilePosition().y > WINDOW_HEIGHT;
				}), projectiles.end());
		}
		projectile.updateVerticalShooting();
		if (monster.isMonsterHitBoxCollideProjectile(projectile)) monster.setMonsterPoint(-200, -100);
		setSpriteSize(spritesManager[5], PROJECTILE_WIDTH, PROJECTILE_HEIGHT);
		drawSprite(spritesManager[5], projectile.getProjectilePosition().x, projectile.getProjectilePosition().y);
	}
}

void PlayerManager::outAllInfo() {
	std::cout << "doodlePos:" << doodler.getDoodlerPosition().x << "/" << doodler.getDoodlerPosition().y
		<< " doodlerHitBoxPos:" << doodler.getHitBoxBottom().x << "/" << doodler.getHitBoxBottom().y
		<< std::endl;
}

void PlayerManager::drawSpritesManager() {
	switch (doodler.getDoodlerStatus()) {
	case DoodleStatus::Right: {
		setSpriteSize(spritesManager[Right], DOODLER_WIDTH, DOODLER_HEIGHT);
		drawSprite(spritesManager[Right], doodler.getDoodlerPosition().x, doodler.getDoodlerPosition().y);
		if (springBoots.activeAbility) {
			setSpriteSize(spritesManager[RightBoots], SPRING_BOOTS_WIDTH, SPRING_BOOTS_HEIGHT);
			drawSprite(spritesManager[RightBoots], doodler.getHitBoxBottom().x + 20, doodler.getHitBoxBottom().y - 5);
		}

	}break;
	case DoodleStatus::Left: {
		setSpriteSize(spritesManager[Left], DOODLER_WIDTH, DOODLER_HEIGHT);
		drawSprite(spritesManager[Left], doodler.getDoodlerPosition().x, doodler.getDoodlerPosition().y);
		if (springBoots.activeAbility) {
			setSpriteSize(spritesManager[LeftBoots], SPRING_BOOTS_WIDTH, SPRING_BOOTS_HEIGHT);
			drawSprite(spritesManager[LeftBoots], doodler.getHitBoxBottom().x + 15, doodler.getHitBoxBottom().y - 5);
		}
	}break;
	case DoodleStatus::Top: {
		setSpriteSize(spritesManager[Top], DOODLER_WIDTH, DOODLER_HEIGHT);
		setSpriteSize(spritesManager[Trunk], 20, 80);
		drawSprite(spritesManager[Top], doodler.getDoodlerPosition().x, doodler.getDoodlerPosition().y);
		drawSprite(spritesManager[Trunk], doodler.getDoodlerPosition().x + 35, doodler.getDoodlerPosition().y + 3);
	}break;
	default: std::cout << "Undefined doodleStatus\n"; break;
	}

}

void PlayerManager::drawMonster() {
	setSpriteSize(spritesManager[4], MONSTER_WIDTH, MONSTER_HEIGHT);
	drawSprite(spritesManager[4], monster.getMonsterHitBox().x, monster.getMonsterHitBox().y);
}

void PlayerManager::drawJumpPad() {
	setSpriteSize(spritesManager[6], JUMP_PAD_WIDTH, JUMP_PAD_HEIGHT);
	drawSprite(spritesManager[6], jumpPad.getJumpPadHitBox().x, jumpPad.getJumpPadHitBox().y);
}

void PlayerManager::drawSpringBoots() {
	setSpriteSize(spritesManager[7], SPRING_BOOTS_WIDTH, SPRING_BOOTS_HEIGHT);
	drawSprite(spritesManager[7], springBoots.getHitBoxSpringBootsPosition().x, springBoots.getHitBoxSpringBootsPosition().y);
}

void PlayerManager::isDoodlerFall(Doodler& doodler) {
	if (doodler.getDoodlerPosition().y > WINDOW_HEIGHT && gameStart) {
		isGameOver = true;
		doodler.setDoodlerPositionY(-100);
	}
}

void PlayerManager::isDoodlerAcrossBorder(Doodler& doodler) {

	if (doodler.getDoodlerPosition().x > WINDOW_WIDTH + 50) {
		doodler.setDoodlerPositionX(-50);
		doodler.setHitBoxBottom(doodler.getHitBoxBottom().x, -50);
	}
	else
	{
		if (doodler.getDoodlerPosition().x < -50) {
			doodler.setDoodlerPositionX(WINDOW_WIDTH + 50);
			doodler.setHitBoxBottom(WINDOW_WIDTH + 50, doodler.getDoodlerPosition().x);
		}
	}
}

void PlayerManager::doodlerIsUseJumpPad(JumpPad& jumpPad, Doodler& doodler) {
	if (jumpPad.isDoodlerCollideJumpPad(doodler)) {
		if (dy > 0) {
			if (doodler.getDoodlerPosition().y < WINDOW_HEIGHT / 2) dy = -0.35 * 3;
			else dy = -0.5 * 3;
			jumpBoost = true;
			jumpPad.setJumpPadHitBox(-100, 900);
		}
	}
	else if (dy > -0.1) jumpBoost = false;
}

void PlayerManager::doodlerIsUseSpringBoots(SpringBoots& springBoots, Doodler& doodler) {
	if (springBoots.activeAbility) {
		if (WINDOW_HEIGHT / 2 < 380) {
			screenUpdateBorder = WINDOW_HEIGHT / 2;
		}
	}
	if (springBoots.isDoodlerCollideSpringBoots(doodler)) {
		startTime = getTickCount();
		jumpBoostSpring = true;
		springBoots.setSpringBootsHitBox(-100, -900);
	}
	if (dy < 0 && springBoots.activeAbility) {
		if (dy < 0)jumpBoostSpring = true;
		else jumpBoostSpring = false;
	}

	if (getTickCount() - startTime >= 20000) {
		jumpBoostSpring = false;
		springBoots.activeAbility = false;
	}
}

void PlayerManager::screenUpdate(Doodler& doodler, PlatformManager& platformManager, float deltaTime, Score& score) {
	if (doodler.getDoodlerPosition().y < screenUpdateBorder) {
		dy += G * deltaTime;
		updateScreenPosition(platformManager, 1, deltaTime, score);
		if (doodler.getDoodlerPosition().y > jumpLevel - 80 && !jumpBoost && !springBoots.activeAbility) dy = -0.8;
		if (doodler.getDoodlerPosition().y > jumpLevel - 80 && springBoots.activeAbility) dy = -0.4 * 2.5;
		doodler.updateDoodlerPositionY(dy * deltaTime);
		if (dy > 0 && isAlive) {
			checkCollision(platformManager);
		}
	}
	else {
		// jump movement
		dy += G * deltaTime;

		if (doodler.getDoodlerPosition().y > jumpLevel - 80 && !jumpBoost && !springBoots.activeAbility) dy = -0.8;
		if (doodler.getDoodlerPosition().y > jumpLevel - 80 && springBoots.activeAbility) {
			dy = -0.5 * 2.5;
		}
		if (dy > 0 && isAlive) {
			checkCollision(platformManager);
		}
		doodler.updateDoodlerPositionY(dy * deltaTime);
	}
}



void PlayerManager::updatePosition(bool& pressedRight, bool& pressedLeft, PlatformManager& platformManager, float deltaTime, Score& score) {
	
	updateProjectilePosition(0.5, deltaTime);
	// end if player fall of platform to bottom
	isDoodlerFall(doodler);
	// if player on right side player speed increase by 50% look at keyboard input function in framework onKeyPressed
	if (doodler.getDoodlerPosition().x > WINDOW_WIDTH / 2) doodlerOnRightHalf = true;
	else doodlerOnRightHalf = false;

	if ((pressedLeft || pressedRight) && isAlive)doodler.leftRightPosition(deltaTime, doodlerOnRightHalf);

	// if player go aboard right and left screen 
	isDoodlerAcrossBorder(doodler);
	//check collide doodler kill from top monster
	if (monster.isMonsterHitBoxTopCollideDoodler(doodler)) {
		monster.setMonsterPoint(-200, -200);
		dy = -0.8;
	}
	//check collide monster doodler to kill
	if (monster.isMonsterHitBoxCollideDoodler(doodler)) {
		isAlive = false;
		jumpLevel = 1000;
	}
	// check using jump pad
	doodlerIsUseJumpPad(jumpPad,doodler);
	//check using spring boots
	doodlerIsUseSpringBoots(springBoots, doodler);
	// update screen logic
	screenUpdate(doodler, platformManager, deltaTime, score);
	drawMonster();
	drawJumpPad();
	drawSpringBoots();
	score.drawScore();

}

bool PlayerManager::checkCollision(PlatformManager& platformManager) {
	for (auto& platform : platformManager.platforms) {
		if ((doodler.getHitBoxBottom().x > platform.getPlatformBasicHitBox().x - 48)
			&& (doodler.getHitBoxBottom().x < platform.getPlatformBasicHitBox().x + 48)
			&& (doodler.getHitBoxBottom().y > platform.getPlatformBasicHitBox().y - 10)
			&& (doodler.getHitBoxBottom().y < platform.getPlatformBasicHitBox().y + 20)) {
			jumpLevel = platform.getPlatformBasicPosition().y - 20;
			gameStart = true;
			return true;
		}
	}
	jumpLevel = WINDOW_HEIGHT + 100;
	return false;
}

void PlayerManager::updateScreenPosition(PlatformManager& platformManager, float vy, const float& deltaTime, Score& score) {
	if (jumpBoost || jumpBoostSpring) {
		if (jumpBoost && !jumpBoostSpring) {
			boost = 3;
		}
		if (jumpBoostSpring && !jumpBoost) boost = 2.5;
	}
	else boost = 1;
	for (auto& platform : platformManager.platforms) {
		platform.setPlatformBasicPositionYUpdate(vy * deltaTime * interpolationFactor * boost);
		if (tempScoreMonster > 2433) {
			monster.spawnMonster();
			tempScoreMonster = 0;
		}
		if (tempScoreJumpPad > 1551) {
			jumpPad.spawnJumpPad();
			tempScoreJumpPad = 0;
		}
		if (tempScoreSpringBoots > 1000) {
			springBoots.spawnSpringBoots();
			tempScoreSpringBoots = 0;
		}
		if (platform.getPlatformBasicHitBox().y > WINDOW_HEIGHT) {
			platform.setPlatformBasicPosition(platformManager.updateNonCollidingPosition().x, platformManager.updateNonCollidingPosition().y);
			if (monster.getMonsterSpawn()) {
				monster.setMonsterPoint(platform.getPlatformBasicHitBox().x + 5, platform.getPlatformBasicHitBox().y - 60);
			}
			if (jumpPad.isJumpPadSpawn) {
				jumpPad.setJumpPadHitBox(platform.getPlatformBasicHitBox().x + 5, platform.getPlatformBasicHitBox().y - 30);
			}
			if (springBoots.getIsSpringBootsSpawn() && !springBoots.activeAbility) {
				springBoots.setSpringBootsHitBox(platform.getPlatformBasicHitBox().x + 5, platform.getPlatformBasicHitBox().y - 50);
			}
		}
	}
	tempScoreMonster += vy * deltaTime * interpolationFactor;
	tempScoreJumpPad += vy * deltaTime * interpolationFactor;
	tempScoreSpringBoots += vy * deltaTime * interpolationFactor * boost;
	jumpPad.updateJumpPadPositionY(vy * deltaTime * interpolationFactor * boost);
	doodler.updateDoodlerPositionY(vy * deltaTime * interpolationFactor);
	monster.setMonsterPositionUpdateY(vy * deltaTime * interpolationFactor * boost);
	springBoots.updateSpringBootsPositionY(vy * deltaTime * interpolationFactor * boost);
	score.setScorePoints(vy * deltaTime * interpolationFactor * boost);
}


