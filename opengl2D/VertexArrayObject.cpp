#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &this->ID);
	

}

void VertexArrayObject::linkAttrib(const VertexBufferObject vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	vbo.bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
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
