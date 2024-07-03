#pragma once

#include "Framework.h"
#include "Rectangle.h"
#include "Const.h"
#include <iostream>

class Entity {
protected:
	Rectangle hitBox;
	Point position;

	Entity(Point point, int width, int height) 
		: hitBox{point,width,height}, position(point)
	{
	}

};