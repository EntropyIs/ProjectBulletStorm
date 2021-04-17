#include "HitBox.h"
#include "Entropy/Platform/OpenGL/ResourseManager.h"

HitBox::HitBox(float x, float y, float w, float h) : _x(x), _y(y), _w(w), _h(h), _dX(0), _dY(0)
{
#ifdef ENTROPY_DEBUG
	//   X,    Y,   tX,   tY,    R,    G,    B,    A
	float vertices[] =
	{ 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	  0.0f,    h, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	     w, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,

	  0.0f,    h, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	     w,    h, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	     w, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };

	_renderer = Entropy::Graphics::Renderer2D(vertices, unsigned int(6), std::string("HitboxShader"));
#endif // ENTROPY_DEBUG
}

HitBox::HitBox(float x, float y, float w, float h, float dX, float dY) : _x(x + dX), _y(y + dY), _w(w), _h(h), _dX(dX), _dY(dY)
{
#ifdef ENTROPY_DEBUG
	//   X,    Y,   tX,   tY,    R,    G,    B,    A
	float vertices[] =
	{ 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	  0.0f,    h, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 w, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,

	  0.0f,    h, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 w,    h, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 w, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };

	_renderer = Entropy::Graphics::Renderer2D(vertices, unsigned int(6), std::string("HitboxShader"));
#endif // ENTROPY_DEBUG
}

void HitBox::OnUpdate(float x, float y)
{
	_x = x + _dX;
	_y = y + _dY;
}

void HitBox::OnRender()
{
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
