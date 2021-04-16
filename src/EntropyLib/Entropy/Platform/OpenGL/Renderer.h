#pragma once

namespace Entropy
{
	class Renderer
	{
	public:
		Renderer(float* vertices);
		virtual ~Renderer();

		void OnRender();

	protected:
		unsigned int _VAO;
	};
}

