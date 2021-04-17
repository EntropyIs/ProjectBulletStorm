#pragma once

#include "Entropy/Tools/API.h"

namespace Entropy
{
	namespace Math
	{
		class _declspec(dllexport) Vec2
		{
		public:
			union
			{
				struct { float I, J; };
				struct { float X, Y; };
				float Data[2];
			};

			Vec2() : I(0.0f), J(0.0f) {};
			Vec2(float value) : I(value), J(value) {};
			Vec2(float i, float j) : I(i), J(j) {};

			Vec2& operator+= (const Vec2& right);
			Vec2& operator-= (const Vec2& right);
		};

		Vec2 ENTROPY_API operator+ (const Vec2& left, const Vec2& right);
		Vec2 ENTROPY_API operator- (const Vec2& left, const Vec2& right);

		Vec2 ENTROPY_API operator* (const float left, const Vec2& right);
		Vec2 ENTROPY_API operator* (const Vec2& left, const float right);

		float ENTROPY_API dot(const Vec2& left, const Vec2& right);
		float ENTROPY_API magnitude(const Vec2& vector);
		Vec2 ENTROPY_API normalize(const Vec2& vector);
	}
}

