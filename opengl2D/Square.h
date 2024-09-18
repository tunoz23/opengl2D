#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
class Square
{
public:
	GLfloat centerPosX;
	GLfloat centerPosY;
	GLfloat squareWidth;
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;
public:
	Square(const GLfloat _centerPosX, const GLfloat _centerPosY, int width);
	Square(const GLuint _centerPosX, const GLuint _centerPosY, int width);
};

