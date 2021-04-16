#pragma once

class HitBox
{
public:
	HitBox(float x, float y, float w, float h) : _x(x), _y(y), _w(w), _h(h), _dX(0), _dY(0) {}
	HitBox(float x, float y, float w, float h, float dX, float dY) : _x(x + dX), _y(y + dY), _w(w), _h(h), _dX(dX), _dY(dY) {}
	~HitBox() {}

	void OnUpdate(float x, float y);

	void SetDX(float dX);
	void SetDY(float dY);

	const bool Detect(const HitBox& other) const;

private:
	float _x, _y; //Position
	float _w, _h; //Size
	float _dX, _dY; // Offset (From Game Object Position)
};
