#pragma once

#include "Entropy/Tools/API.h"

namespace Entropy
{
	namespace Math
	{
		class ENTROPY_API Vec3
		{
		public:
			union
			{
				struct { float I, J, K; };
				struct { float X, Y, Z; };
				struct { float R, G, B; };
				float Data[3];
			};

			Vec3() : I(0.0f), J(0.0f), K(0.0f) {};
			Vec3(float value) : I(value), J(value), K(value) {};
			Vec3(float i, float j) : I(i), J(j), K(0.0f) {};
			Vec3(float i, float j, float k) : I(i), J(j), K(k) {};

			Vec3& operator += (const Vec3& right);
			Vec3& operator -= (const Vec3& right);
		};

		Vec3 ENTROPY_API operator+ (const Vec3& left, const Vec3& right);
		Vec3 ENTROPY_API operator- (const Vec3& left, const Vec3& right);

		Vec3 ENTROPY_API operator* (const float left, const Vec3& right);
		Vec3 ENTROPY_API operator* (const Vec3& left, const float right);

		float ENTROPY_API dot(const Vec3& left, const Vec3& right);
		Vec3 ENTROPY_API cross(const Vec3& left, const Vec3& right);
		float ENTROPY_API magnitude(const Vec3& vector);
		Vec3 ENTROPY_API normalize(const Vec3& vector);
	}
}