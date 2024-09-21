#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <optional>

#include "VertexBufferObject.h"
#include "IndexBufferObject.h"
#include "VertexArrayObject.h"
#include "Drawable.h"

class Square : public Drawable
{
	
public:
	VertexArrayObject vao;
	std::optional<VertexBufferObject> vbo;
	std::optional<IndexBufferObject> ebo;

	GLfloat centerPosX;
	GLfloat centerPosY;
	GLfloat squareWidth;

	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;
public:
	Square(const GLfloat _centerPosX, const GLfloat _centerPosY, int width);
	Square(const GLuint _centerPosX, const GLuint _centerPosY, int width);
	void draw() override;
};

