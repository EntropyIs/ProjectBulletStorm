#pragma once

#include "Entropy/Tools/API.h"

namespace Entropy
{
	namespace Graphics
	{
		class ENTROPY_API Renderer
		{
		public:
			Renderer(float* vertices, int numVertices, std::string shader);
			virtual ~Renderer();

			void OnRender();

		protected:
			unsigned int _VAO;

			unsigned int _numVertices;

			std::string _shader;
		};
	}
}

