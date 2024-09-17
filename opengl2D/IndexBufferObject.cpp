#include "IndexBufferObject.h"

IndexBufferObject::IndexBufferObject(const std::vector<GLuint>& indices)
{
	glGenBuffers(1, &this->ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);


}

void IndexBufferObject::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
}

void IndexBufferObject::unBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}


void IndexBufferObject::Delete()
{
	glDeleteBuffers(1, &this->ID);
}
