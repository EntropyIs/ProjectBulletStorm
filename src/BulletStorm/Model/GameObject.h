#pragma once

#include "HitBox.h"

#include <Entropy/Events/Event.h>

class GameObject
{
public:
	GameObject(float x, float y, float vX, float vY, unsigned int health,
		float hb_dX, float hb_dY, float hb_w, float hb_h)
		: _x(x), _y(y), _vX(vX), _vY(vY), _health(health), _isAlive(true), 
		_hitbox(x, y, hb_w, hb_h, hb_dX, hb_dY) {}
	virtual ~GameObject() {}

	virtual void OnUpdate();
	virtual void OnEvent(Entropy::Event& event) {};

	void SetVX(float vX);
	void SetVY(float vY);

	bool isAlive();
	void kill();
	
protected:
	float _x, _y; // Position
	float _vX, _vY; // Velosity

	HitBox _hitbox;

	unsigned int _health;
	bool _isAlive;
};
