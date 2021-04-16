#include "HitBox.h"

void HitBox::OnUpdate(float x, float y)
{
	_x = x + _dX;
	_y = y + _dY;
}

void HitBox::SetDX(float dX)
{
	_dX = dX;
}

void HitBox::SetDY(float dY)
{
	_dY = dY;
}

const bool HitBox::Detect(const HitBox& other) const
{
	return _x < (other._x + other._w) && (_x + _w) > other._x
		&& _y < (other._y + other._h) && (_y + _h) > other._y;
}
