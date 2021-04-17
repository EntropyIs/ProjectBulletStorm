#pragma once

#include "Entropy/Tools/API.h"
#include "Renderer.h"

namespace Entropy
{
	namespace Graphics
	{
		class ENTROPY_API Renderer2D : public Renderer
		{
		public:
			Renderer2D(float* vertices, unsigned int numVertices, std::string shader);

			virtual void OnRender() override;
			
			void SetPosition(float x, float y);

		private:
			float _x, _y;
		};
	}
}
