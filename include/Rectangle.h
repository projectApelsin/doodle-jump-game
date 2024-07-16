#pragma once

#include "Point.h"

struct Rectangle {
	int x, y, width, height;
	Rectangle();

	Rectangle(int x, int y, int width, int height);
	Rectangle(Point point, int width, int height);
};
