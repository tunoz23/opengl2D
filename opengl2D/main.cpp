#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shaderClass.h"
#include "VertexBufferObject.h"
#include "IndexBufferObject.h"
#include "VertexArrayObject.h"

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
	

	std::vector<GLfloat> vertices =
	{	-0.5f, -0.5f,1.f,
		 0.5f,-0.5f,1.f,
		 0.0f,0.5f,1.0f,
		0.3f,0.7f,1.0f
	};
	
	std::vector<GLuint> indices =
	{
		0,1,2,3,0,1
	};
	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0, 0, 800, 800);


	Shader shader1("default.vert", "default.frag");



	VertexArrayObject vao;
	vao.bind();
	VertexBufferObject vbo(vertices);
	IndexBufferObject ebo(indices);
	vao.linkVBO(vbo, 0);
	vao.unBind();
	ebo.unBind();

	glfwSwapBuffers(window);
	
	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0.03f, 0.10f, 0.12f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shader1.Activate();
		vao.bind();
		glDrawElements(GL_TRIANGLES, indices.size(),GL_UNSIGNED_INT,0);
		glfwSwapBuffers(window);

		glfwPollEvents();



	}

	glfwTerminate();
	return 0;
}