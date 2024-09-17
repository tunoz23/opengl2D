#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
class VertexBufferObject
{

public:
	GLuint ID;

public:
	VertexBufferObject(const std::vector<GLfloat>& vertices);

	void bind() const;
	void unBind() const;
	void Delete();






};

