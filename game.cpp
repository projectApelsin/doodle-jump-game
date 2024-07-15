#include "Framework.h"
#include "PlatformManager.h"
#include "PlayerManager.h"
#include <string>

Doodler doodler;

/* Test Framework realization */
class MyFramework : public Framework {

	PlatformManager platformManager;
	PlayerManager playerManager;
	
	Score scorePoints;
	bool gameRun;
	float previousTime = getTickCount();


public:

	

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		for (int i = 1; i < __argc; ++i) {
			if (std::string(__argv[i]) == "-window" && i + 1 < __argc) {
				std::string sizeString = __argv[i + 1];
				size_t xPos = sizeString.find('x');

				if (xPos != std::string::npos && xPos + 1 < sizeString.length()) {
					WINDOW_WIDTH = std::stoi(sizeString.substr(0, xPos));
					WINDOW_HEIGHT = std::stoi(sizeString.substr(xPos + 1));

					fullscreen = false;
				}
			}
		}
		width = WINDOW_WIDTH;
		height = WINDOW_HEIGHT;
		fullscreen = false;
	}

	virtual bool Init() {
		
	platformManager.generatePlatforms(12);
		playerManager.initializeManager();
		scorePoints.initializeScoreSprites();
		
		return true;
	}

	virtual void Close() {

	}
	float deltaTime, currentTime;
	virtual bool Tick() {
		Sprite* background = createSprite("data/bck@2x.png");
		setSpriteSize(background, WINDOW_WIDTH, WINDOW_HEIGHT);
		drawSprite(background, 0, 0);
		if (playerManager.isGameOver) {
			currentTime = getTickCount();
			deltaTime = currentTime - previousTime;
			Sprite* gameOver = createSprite("data/game_over.png");
			Sprite* endBottom = createSprite("data/bottom_screen_end.png");
			setSpriteSize(gameOver, 300, 150);
			setSpriteSize(endBottom, WINDOW_WIDTH, 100);
			drawSprite(gameOver, 200, 300);
			drawSprite(endBottom,0,WINDOW_HEIGHT - 100);
			static int dy;
			dy += 0.1* deltaTime;
			playerManager.doodler.updateDoodlerPositionY(dy);
			playerManager.drawSpritesManager();
			scorePoints.drawScore();
			destroySprite(gameOver);
			destroySprite(endBottom);
			destroySprite(background);
			previousTime = currentTime;
			return false;
		}
		else {

			currentTime = getTickCount();
			deltaTime = currentTime - previousTime;
			platformManager.drawPlatforms();
			playerManager.updatePosition(pressedLeft, pressedRight, platformManager, deltaTime, scorePoints);
			//playerManager.outAllInfo();
			playerManager.drawSpritesManager();
			destroySprite(background);
			previousTime = currentTime;
			return false;
		}
	}



	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		if (playerManager.isDoodleShoot) {
			playerManager.doodleShootProjectile(x,y);
		}
		playerManager.isDoodleShoot = false;
	}


	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {

		switch (button)
		{
		case FRMouseButton::LEFT: {
				if (!isReleased) {
					playerManager.isDoodleShoot = true;
				}

				playerManager.doodler.setDoodlerStatus(Top);
		}
			break;

		default:
			break;
		}
	}
	bool pressedRight;
	bool pressedLeft;
	virtual void onKeyPressed(FRKey k) {

		switch (k)
		{
		case FRKey::RIGHT: {
			playerManager.doodler.setDoodlerStatus(Right);
			pressedRight = true;
		}
			break;
		case FRKey::LEFT: {
			playerManager.doodler.setDoodlerStatus(Left);
			pressedLeft = true;
		}
			break;

		default:
			break;
		}
	}

	virtual void onKeyReleased(FRKey k) {
		switch (k)
		{
		case FRKey::RIGHT: {
			pressedRight = false;
		}
			break;
		case FRKey::LEFT: pressedLeft = false;
			break;

		default:
			break;
		}
	}

	virtual const char* GetTitle() override
	{
		return "Doodle Jump";
	}
};

int main(int argc, char* argv[])
{
		return run(new MyFramework);
}
