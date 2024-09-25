#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <optional>

#include "VertexBufferObject.h"
#include "IndexBufferObject.h"
#include "VertexArrayObject.h"
#include "Drawable.h"

class Line : public Drawable
{
public:

	VertexArrayObject vao;
	std::optional<VertexBufferObject> vbo;

	std::vector<GLfloat> vertices;
	Line(GLfloat _startX, GLfloat _startY, GLfloat _endX, GLfloat _endY);
	
	void draw() override;
};

