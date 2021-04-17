#include "GameObject.h"

void GameObject::OnUpdate()
{
	// Update Position
	_x += _vX;
	_y += _vY;

	// Update Hitbox
	_hitbox.OnUpdate(_x, _y);
}

void GameObject::OnRender()
{
#ifdef ENTROPY_DEBUG
	_hitbox.OnRender(); // Only render Hitbox if in Debug Mode
#endif // ENTROPY_DEBUG
}

void GameObject::SetVX(float vX)
{
	_vX = vX;
}

void GameObject::SetVY(float vY)
{
	_vY = vY;
}

bool GameObject::isAlive()
{
	return _isAlive;
}

void GameObject::kill()
{
	_isAlive = false;
}
