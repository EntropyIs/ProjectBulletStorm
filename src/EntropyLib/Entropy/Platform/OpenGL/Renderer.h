#pragma once

#include "Entropy/Tools/API.h"

namespace Entropy
{
	class ENTROPY_API Renderer
	{
	public:
		Renderer(float* vertices);
		virtual ~Renderer();

		void OnRender();

	protected:
		unsigned int _VAO;
	};
}

