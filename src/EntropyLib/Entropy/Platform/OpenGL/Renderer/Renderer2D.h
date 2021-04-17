#pragma once

#include "Entropy/Tools/API.h"
#include "Renderer.h"

namespace Entropy
{
	namespace Graphics
	{
		class ENTROPY_API Renderer2D : public Renderer
		{
			Renderer2D(float* vertices, unsigned int numVertices, std::string shader);

			virtual void OnRender() override;
		};
	}
}
