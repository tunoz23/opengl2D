#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
class IndexBufferObject
{

public:
	GLuint ID;


public:
	IndexBufferObject(const std::vector<GLuint>& indices);
	void bind();
	void unBind();
	void Delete();
};

