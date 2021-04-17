#pragma once

#include "ecpch.h"

#include "Entropy/Tools/API.h"

#include "GLShader.h"

namespace Entropy
{
	namespace Graphics
	{
		class ENTROPY_API ResourceManager
		{
		public:
			static GLShader& LoadShader(std::string name, const char* vertexShaderPath, const char* fragmentShaderPath, const char* geometaryShaderPath = NULL);
			static GLShader& GetShader(std::string name);
		
		private:
			static std::unordered_map<std::string, GLShader> _shaders;
		};
	}
}