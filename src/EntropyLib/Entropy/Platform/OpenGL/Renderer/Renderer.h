#pragma once

#include "Entropy/Tools/API.h"

namespace Entropy
{
	namespace Graphics
	{
		class ENTROPY_API Renderer
		{
		public:
			Renderer() : _VAO(0), _numVertices(0), _shader() {};
			Renderer(unsigned int numVertices, std::string shader) : _VAO(0), _numVertices(numVertices), _shader(shader) {};
			virtual ~Renderer();

			virtual void OnRender() = 0;

		protected:
			unsigned int _VAO;
			unsigned int _numVertices;

			std::string _shader;
		};
	}
}

