#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &this->ID);
	

}

void VertexArrayObject::linkVBO(const VertexBufferObject& vbo, GLuint layout)
{
	vbo.bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
	glEnableVertexAttribArray(layout);
	vbo.unBind();
}

void VertexArrayObject::bind()
{
	glBindVertexArray(this->ID);
}

void VertexArrayObject::unBind()
{
	glBindVertexArray(0);
}

void VertexArrayObject::Delete()
{
	glDeleteVertexArrays(1, &this->ID);
}
