#include "Square.h"

GLuint Square::shaderID = 0;

Square::Square(const GLuint _centerPosX, const GLuint _centerPosY, int width)
	:centerPosX((2.0f * _centerPosX / 800.0f) - 1.0f), centerPosY((2.0f * _centerPosY / 800.0f) - 1.0f), squareWidth(width/800.f)
{
	


	//the width of square is 80px as default 
	this->vertices =
	{
		//up left
		centerPosX - squareWidth, centerPosY + squareWidth, 1.f,
		//up right
		centerPosX + squareWidth, centerPosY + squareWidth, 1.f,
		//down left
		centerPosX - squareWidth, centerPosY - squareWidth, 1.f,
		//down right
		centerPosX + squareWidth, centerPosY - squareWidth, 1.f
	};
	this->indices =
	{
		0, 1, 2,  // First triangle (top-left, top-right, bottom-left)
		1, 2, 3   // Second triangle (top-right, bottom-left, bottom-right)
	};
	vao.bind();
	this->vbo = VertexBufferObject(this->vertices);
	this->ebo = IndexBufferObject(this->indices);

	vao.linkAttrib(vbo.value(), 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
	vao.linkAttrib(vbo.value(), 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	vao.unBind();
	vao.unBind();
	ebo.value().unBind();
}

void Square::draw()
{
	vao.bind();
	glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
	vao.unBind();
}

Square::Square(const GLfloat _centerPosX, const GLfloat _centerPosY, int width)
	:centerPosX(_centerPosX), centerPosY(_centerPosY), squareWidth(width / 800.f)
{
	//the width of square is 80px as default 
	this->vertices =
	{
		//up left														COLOR
		centerPosX - squareWidth, centerPosY + squareWidth, 1.f,		.3f,1.f,1.f,
		//up right
		centerPosX + squareWidth, centerPosY + squareWidth, 1.f,		1.f,1.f,.5f,
		//down left
		centerPosX - squareWidth, centerPosY - squareWidth, 1.f,		1.f,.5f,1.f,
		//down right	
		centerPosX + squareWidth, centerPosY - squareWidth, 1.f,		.7f, .1f,.8f
	};
	this->indices =
	{
		0, 1, 2,  // First triangle (top-left, top-right, bottom-left)
		1, 2, 3   // Second triangle (top-right, bottom-left, bottom-right)
	};
	
	vao.bind();
	this->vbo = VertexBufferObject(this->vertices);
	this->ebo = IndexBufferObject(this->indices);
	vao.linkAttrib(vbo.value(), 0,3, GL_FLOAT,6*sizeof(GLfloat),(void*)0);
	vao.linkAttrib(vbo.value(), 1,3, GL_FLOAT,6*sizeof(GLfloat),(void*)(3 * sizeof(GLfloat)));
	vao.unBind();
	ebo.value().unBind();


}
