#pragma once

#include "GameObject.h"

#include "Entropy/Events/KeyEvent.h"

class Player : public GameObject
{
public:
	Player(float x, float y, float vX, float vY, unsigned int health,
		float hb_dX, float hb_dY, float hb_w, float hb_h)
		: GameObject(x, y, vX, vY, health, hb_dX, hb_dY, hb_w, hb_h) {}

	virtual void OnEvent(Entropy::Event& e);

	bool OnKeyPressed(Entropy::KeyPressedEvent& e);
	bool OnKeyReleased(Entropy::KeyReleasedEvent& e);
};
