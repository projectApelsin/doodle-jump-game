#pragma once

#include "PlatformBasic.h"
#include <random>
#include <vector>

class PlatformManager {
public:
	std::vector<PlatformBasic> platforms;
	std::random_device rand_dev;

	void randomGenerate(int& newX, int& newY, int x, int y, int x1, int y1);

	Point generateNonCollidingPosition(const int& platformWidth, const int& platformHeight);

	Point updateNonCollidingPosition();

	void generatePlatforms(int size);


	void drawPlatforms();

	bool collides(Rectangle rect1, Rectangle rect2);
};
