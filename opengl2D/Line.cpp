#include "Line.h"

Line::Line(GLfloat _startX, GLfloat _startY, GLfloat _endX, GLfloat _endY)
{
	
	this->vertices =
	{			//COORDS		//COLORS	
		_startX, _startY, 1.0f,	1.f,1.f,1.f,
		_endX, _endY, 1.0f,		0.5f,.2f,.3f

	};
	vao.bind();
	this->vbo = VertexBufferObject(this->vertices);
	vao.linkAttrib(vbo.value(), 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
	vao.linkAttrib(vbo.value(), 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3*sizeof(GLfloat)));
	vao.unBind();
}

void Line::draw()
{
	vao.bind();
	glDrawArrays(GL_LINES, 0, 2);
	vao.unBind();
}
