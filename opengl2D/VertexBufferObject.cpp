#include "VertexBufferObject.h"

VertexBufferObject::VertexBufferObject(const std::vector<GLfloat>& vertices)
{

	glGenBuffers(1, &this->ID);
	glBindBuffer(GL_ARRAY_BUFFER, this->ID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);

}


void VertexBufferObject::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER,this->ID);
	
}

void VertexBufferObject::unBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBufferObject::Delete()
{
	glDeleteBuffers(1, &this->ID);
}
