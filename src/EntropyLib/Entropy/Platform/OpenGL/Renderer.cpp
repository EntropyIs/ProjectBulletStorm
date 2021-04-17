#include "ecpch.h"
#include "Renderer.h"

#include "Entropy/Math/Transform3D.h"

#include "ResourseManager.h"

Entropy::Graphics::Renderer::Renderer(float* vertices, int numVertices, std::string shader) : _numVertices(numVertices), _shader(shader)
{
	unsigned int VBO;

	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(_VAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glBindVertexArray(0);
}

Entropy::Graphics::Renderer::~Renderer()
{
	glDeleteVertexArrays(1, &_VAO);
}

void Entropy::Graphics::Renderer::OnRender()
{
	// Prepare Transformations
	Entropy::Math::Mat4 model = Math::Mat4();

	ResourceManager::GetShader(_shader).Use();
	ResourceManager::GetShader(_shader).SetMat4("model", model);
	
	// Render
	glBindVertexArray(_VAO);
	glDrawArrays(GL_TRIANGLES, 0, _numVertices);
	glBindVertexArray(0);
}