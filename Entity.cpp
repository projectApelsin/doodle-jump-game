#include "Entity.h"

Entity::Entity(Point point, int width, int height)
	: hitBox{ point,width,height }, position(point)
{
}
