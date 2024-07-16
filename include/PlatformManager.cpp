#include "PlatformManager.h"

void PlatformManager::randomGenerate(int& newX, int& newY, int x, int y, int x1, int y1) {
	std::mt19937 gen(rand_dev());
	std::uniform_int_distribution<int> xDistribution(x, y);
	std::uniform_int_distribution<int> yDistribution(x1, y1);
	newX = xDistribution(gen);
	newY = yDistribution(gen);
}

Point PlatformManager::generateNonCollidingPosition(const int& platformWidth, const int& platformHeight) {

	int newX, newY;

	randomGenerate(newX, newY, 0, WINDOW_WIDTH - platformWidth, 0, WINDOW_HEIGHT - platformHeight);
	for (auto& platform : platforms) {
		Rectangle tempRect(newX, newY, platformWidth, platformHeight);
		if (collides(tempRect, platform.getPlatformBasicHitBox())) {
			return generateNonCollidingPosition(platformWidth, platformHeight);
		}
	}
	return Point(newX, newY);
}

Point PlatformManager::updateNonCollidingPosition() {
	int newX, newY;

	randomGenerate(newX, newY, 0, WINDOW_WIDTH - PLATFORM_COLLISION_DISTANCE_WIDTH, -50, 50);
	for (auto& platform : platforms) {
		Rectangle tempRect(newX, newY, PLATFORM_COLLISION_DISTANCE_WIDTH, PLATFORM_COLLISION_DISTANCE_HEIGHT);
		if (collides(tempRect, platform.getPlatformBasicHitBox())) {
			return updateNonCollidingPosition();
		}
	}
	return Point(newX, newY);
}

void PlatformManager::generatePlatforms(int size) {
	platforms.reserve(size + 1);
	for (int i = 0; i < size; i++) {
		platforms.emplace_back(generateNonCollidingPosition(PLATFORM_COLLISION_DISTANCE_WIDTH, PLATFORM_COLLISION_DISTANCE_HEIGHT),
			PLATFORM_WIDTH, PLATFORM_HEIGHT);
	}
	platforms.emplace_back(Point(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 100), PLATFORM_WIDTH, PLATFORM_HEIGHT);

}

void PlatformManager::drawPlatforms() {
	for (auto& platform : platforms) {
		platform.drawPlatformBasic();
	}
}

bool PlatformManager::collides(Rectangle rect1, Rectangle rect2) {
	return rect1.x < rect2.x + rect2.width &&
		rect1.x + rect1.width > rect2.x &&
		rect1.y < rect2.y + rect2.height &&
		rect1.y + rect1.height > rect2.y;
}

