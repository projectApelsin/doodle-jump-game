#pragma once

#include "Doodler.h"
#include <iostream>
#include <vector>
#include "PlatformBasic.h"
#include "Doodler.h"
#include "Score.h"
#include "Monster.h"
#include "Projectile.h"
#include "JumpPad.h"
#include "SpringBoots.h"
#include "PlatformManager.h"

class PlayerManager {
private:
	std::vector<Sprite*> spritesManager;
	std::vector<Projectile> projectiles;
	unsigned int previousTime = getTickCount();
	float dy = DOODLE_VY;
	float vx = DOODLE_VX;
	int jumpLevel = WINDOW_HEIGHT; 
	bool doodlerOnRightHalf;
	bool isAlive = true;
	bool gameStart;
	bool jumpBoost;
	bool jumpBoostSpring;
	int screenUpdateBorder = WINDOW_HEIGHT/2;
	unsigned int startTime;
	float interpolationFactor = 0.28;
	int boost;
	int tempScoreMonster;
	int tempScoreJumpPad;
	int tempScoreSpringBoots;
public:
	Doodler doodler;
	Monster monster;
	JumpPad jumpPad;
	SpringBoots springBoots;
	bool isGameOver;
	bool isDoodleShoot;

	void initializeManager();

	void doodleShootProjectile(int& x, int& y);
	
	void updateProjectilePosition(int speed, int deltaTime);

	void outAllInfo();

	void drawSpritesManager();

	void drawMonster();

	void drawJumpPad();

	void drawSpringBoots();

	void isDoodlerFall(Doodler& doodler);

	void isDoodlerAcrossBorder(Doodler& doodler);

	void doodlerIsUseJumpPad(JumpPad& jumpPad, Doodler& doodler);

	void doodlerIsUseSpringBoots(SpringBoots& springBoots, Doodler& doodler);

	void screenUpdate(Doodler& doodler, PlatformManager& platformManager, float deltaTime, Score& score);

	void updatePosition(bool& pressedRight, bool& pressedLeft, PlatformManager& platformManager, float deltaTime, Score& score);

	bool checkCollision(PlatformManager& platformManager);

	void updateScreenPosition(PlatformManager& platformManager, float vy, const float& deltaTime, Score& score);
};

