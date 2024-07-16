#include "Rectangle.h"

Rectangle::Rectangle() : x(0), y(0), width(0), height(0) {}

Rectangle::Rectangle(int x, int y, int width, int height)
	: x(x), y(y), width(width), height(height)
{}

Rectangle::Rectangle(Point point, int width, int height)
	: x(point.x), y(point.y), width(width), height(height)
{}