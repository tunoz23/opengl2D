#pragma once

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "VertexBufferObject.h"

class VertexArrayObject
{
public:
	GLuint ID;
public:
	VertexArrayObject();
	void linkVBO(const VertexBufferObject& vbo, GLuint layout);
	void bind();
	void unBind();
	void Delete();
};

