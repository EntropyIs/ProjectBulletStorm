#version 460 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoords;
layout (location = 3) in vec4 aTintColor;

out vec2 TexCoords;
out vec4 TintColor;

uniform mat4 model;
uniform mat4 projection;

void main()
{
	TexCoords = aTexCoords;
	TintColor = aTintColor;
	gl_Position = projection * model * vec4(aPos, 0.0, 1.0);
}