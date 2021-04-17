#include "ecpch.h"
#include "Renderer.h"

Entropy::Renderer::Renderer(float* vertices)
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

Entropy::Renderer::~Renderer()
{
	glDeleteVertexArrays(1, &_VAO);
}

void Entropy::Renderer::OnRender()
{
	// Prepare Transformations
	// Math::Mat4 model = Math::Translate(Math::Vec3(position.X - ((float)spriteData.cel_width / 2.0f), position.Y - ((float)spriteData.cel_height / 2.0f), 0.0f)) * Math::RotateZ(Math::Radians(rotAngle)) * Math::Scale((float)spriteData.cel_width, (float)spriteData.cel_height, 1.0f);
	
	// Render

}