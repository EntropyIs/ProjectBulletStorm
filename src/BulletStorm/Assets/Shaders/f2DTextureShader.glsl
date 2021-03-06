#version 460 core
in vec2 TexCoords;
in vec4 TintColor;
out vec4 FragColor;

uniform sampler2D spriteSheet;
uniform vec3 spriteColor;
uniform vec2 spriteOffset; // Element position on sheet
uniform vec2 spriteSheetSize; // Num of elements in sprite sheet

void main()
{
	float xOffset = (1.0 / spriteSheetSize.x) * spriteOffset.x;
	vec2 offsetSize = vec2(1.0, 1.0) / spriteSheetSize;
	vec2 correctedCoords = (TexCoords / spriteSheetSize) + (offsetSize * spriteOffset); 
	vec4 texColor = vec4(spriteColor, 1.0) * texture(spriteSheet, correctedCoords);
	if(texColor.a < 0.1)
		discard;
	FragColor = texColor;
}