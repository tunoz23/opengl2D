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
	void linkAttrib(const VertexBufferObject vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	void bind();
	void unBind();
	void Delete();
};

