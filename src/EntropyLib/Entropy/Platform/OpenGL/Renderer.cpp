#include "ecpch.h"
#include "Renderer.h"

Entropy::Graphics::Renderer::~Renderer()
{
	glDeleteVertexArrays(1, &_VAO);
}