#include "Square.h"

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

}

Square::Square(const GLfloat _centerPosX, const GLfloat _centerPosY, int width)
	:centerPosX(_centerPosX), centerPosY(_centerPosY), squareWidth(width / 800.f)
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

}
