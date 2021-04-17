#pragma once

#include "Entropy/Tools/API.h"

#include "Entropy/Math/Vec2.h"
#include "Entropy/Math/Vec3.h"
#include "Entropy/Math/Vec4.h"
#include "Entropy/Math/Mat2.h"
#include "Entropy/Math/Mat3.h"
#include "Entropy/Math/Mat4.h"

namespace Entropy
{
	namespace Graphics
	{
		class ENTROPY_API GLShader
		{
		public:
			GLShader(const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometaryShaderPath = nullptr);

			void Use() const;

			void SetBool(const char* name, bool v0) const;
			void SetInt(const char* name, int v0) const;
			void SetFloat(const char* name, float v0) const;

			void SetVec2(const char* name, const Math::Vec2& v0) const;
			void SetVec3(const char* name, const Math::Vec3& v0) const;
			void SetVec4(const char* name, const Math::Vec4& v0) const;

			void SetMat2(const char* name, const Math::Mat2& v0) const;
			void SetMat3(const char* name, const Math::Mat3& v0) const;
			void SetMat4(const char* name, const Math::Mat4& v0) const;

			//void SetMaterial(const Material& v0) const;

			//void SetDirectionalLight(const DirectionalLight& v0) const;
			//void SetPointLight(unsigned int index, const PointLight& v0) const;
			//void SetSpotLight(unsigned int index, const SpotLight& v0) const;

			void SetUniformBlockBinding(const char* name, unsigned int v0) const;

			unsigned int GetUniformBlockIndex(const char* name) const;

		private:
			unsigned int _ID;
			unsigned int Compile(const char* path, unsigned int type);
		};
	}
}
