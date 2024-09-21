#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

#include "shaderClass.h"
#include "VertexBufferObject.h"
#include "IndexBufferObject.h"
#include "VertexArrayObject.h"
#include "Square.h"
#include "utils.h"
#include "Drawable.h"


int main()
{

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "2D engine", NULL, NULL);
	if (!window)
	{
		std::cout << "failed to create window";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, 800, 800);






	Shader shader1("default.vert", "default.frag");

	int width = 5;
	int spacing = 2;
	//Square square(0.f,0.f, width); //(xPos = 0.f, yPos = 0.f,  width = 400px)
	std::vector<std::shared_ptr<Drawable>> draws;
	//std::vector<VertexArrayObject> VAOs;
	//std::vector<VertexBufferObject> VBOs;
	//std::vector<IndexBufferObject> EBOs;
	//
	for (GLfloat x = -400.f; x < 400.f; x += 0.1f)
	{
		float tempX = x/400.f;
		
		float tempY = log10f(tempX) + tempX* tempX* tempX - log10f(tempX)* tempX;
		draws.push_back(std::make_shared<Square>(tempX, tempY, 4));

	}
	/*for(int y = width/2; y<800; y+= width + spacing)
		for (int x = width/2; x < 800; x += width + spacing)
			squares.push_back(Square((GLuint)x, (GLuint)y, width));*/


	//for (const auto& square : squares)
	//{
	//	VertexArrayObject vao;
	//	vao.bind();
	//	VertexBufferObject vbo(square.vertices);
	//	IndexBufferObject ebo(square.indices);
	//	vao.linkVBO(vbo, 0);
	//	vao.unBind();
	//	ebo.unBind();

	//	VAOs.push_back(vao);
	//	VBOs.push_back(vbo);
	//	EBOs.push_back(ebo);

	

	//VertexArrayObject vao;
	//vao.bind();
	//VertexBufferObject vbo(square.vertices);
	//IndexBufferObject ebo(square.indices);
	//vao.linkVBO(vbo, 0);
	//vao.unBind();
	//ebo.unBind();

	glfwSwapBuffers(window);
	
	while (!glfwWindowShouldClose(window))
	{
		Timer timer;
		glClearColor(0.03f, 0.10f, 0.12f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shader1.Activate();
		for (auto drawableObject : draws)
			drawableObject->draw();

		glfwSwapBuffers(window);

		glfwPollEvents();



	}
	glfwTerminate();
	return 0;
}