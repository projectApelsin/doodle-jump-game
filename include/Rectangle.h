#pragma once

#include "Point.h"

struct Rectangle {
	int x, y, width, height;
	Rectangle() : x(0), y(0), width(0), height(0) {}

	Rectangle(int x, int y, int width, int height)
		: x(x), y(y), width(width), height(height)
	{}
	Rectangle(Point point, int width, int height)
		: x(point.x), y(point.y), width(width), height(height)
	{}
};
