#pragma once

#include "Entropy/Tools/API.h"

namespace Entropy
{
	namespace Graphics
	{
		class ENTROPY_API Renderer
		{
		public:
			Renderer(float* vertices, std::string shader) : _VAO(0), _numVertices(sizeof(vertices) / sizeof(float)), _shader(shader) {};
			virtual ~Renderer();

			virtual void OnRender() = 0;
			virtual void OnUpdate() = 0;

		protected:
			unsigned int _VAO;
			unsigned int _numVertices;

			std::string _shader;
		};
	}
}

