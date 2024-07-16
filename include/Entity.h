#pragma once
#include "Rectangle.h"
#include <iostream>
#include "Const.h"

class Entity {
protected:
	Rectangle hitBox;
	Point position;

	Entity(Point point, int width, int height);

};