#pragma once

#ifdef ENTROPY_DEBUG
#include "Entropy/Platform/OpenGL/Renderer/Renderer2D.h"
#endif // ENTROPY_DEBUG

class HitBox
{
public:
	HitBox(float x, float y, float w, float h);
	HitBox(float x, float y, float w, float h, float dX, float dY);
	~HitBox() {}

	void OnUpdate(float x, float y);
	void OnRender();

	void SetDX(float dX);
	void SetDY(float dY);

	const bool Detect(const HitBox& other) const;

private:
	float _x, _y; //Position
	float _w, _h; //Size
	float _dX, _dY; // Offset (From Game Object Position)

#ifdef ENTROPY_DEBUG
	Entropy::Graphics::Renderer2D _renderer;
#endif // ENTROPY_DEBUG

};
