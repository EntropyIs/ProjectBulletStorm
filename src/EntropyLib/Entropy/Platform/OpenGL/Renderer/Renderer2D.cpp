#include "ecpch.h"
#include "Renderer2D.h"

#include "..\ResourseManager.h"

#include "Entropy/Math/Transform3D.h"

Entropy::Graphics::Renderer2D::Renderer2D(float* vertices, unsigned int numVertices, std::string shader) : Renderer(numVertices, shader), _x(0), _y(0)
{
	unsigned int VBO;

	glGenVertexArrays(1, &_VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(_VAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0); // X, Y
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(2 * sizeof(float))); // tX, tY
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(4 * sizeof(float))); // R, G, B, A
	glBindVertexArray(0);
}

void Entropy::Graphics::Renderer2D::OnRender()
{
	// Prepare Transformations
	Entropy::Math::Mat4 model = Entropy::Math::Translate(Entropy::Math::Vec3(_x, _y));

	ResourceManager::GetShader(_shader).Use();
	ResourceManager::GetShader(_shader).SetMat4("model", model);

	// Render
	glBindVertexArray(_VAO);
	glDrawArrays(GL_TRIANGLES, 0, _numVertices);
	glBindVertexArray(0);
}

void Entropy::Graphics::Renderer2D::SetPosition(float x, float y)
{
	_x = x;
	_y = y;
}
