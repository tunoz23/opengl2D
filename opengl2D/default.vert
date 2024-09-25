#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 Color;

uniform float sCale; 

void main()
{
	gl_Position = vec4(aPos.x + aPos.x * sCale,aPos.y + aPos.y * sCale,aPos.z, 1.0);
	Color = aColor;
}