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
#include "Line.h"

static GLfloat scale = 0.1f;
static GLfloat incr = 0.10f;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
int main()
{

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "2D engine", NULL, NULL);
	glfwSetKeyCallback(window, keyCallback);
	if (!window)
	{
		std::cout << "failed to create window";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, 800, 800);

	std::shared_ptr<Line> line1 = std::make_shared<Line>(-1.f, 0.f, 1.f, 0.f);


	Shader shader1("default.vert", "default.frag");

	int width = 10;
	int spacing = 2;
	std::vector<std::shared_ptr<Drawable>> draws;
	
	for (GLfloat x = -300.f; x < 300.f; x += 10.f)
	{
		float tempX = x/400.f;
		
		float tempY = tempX*tempX - 10/400.f;
		draws.push_back(std::make_shared<Square>(tempX, tempY, 30));

	}
	//draws.push_back(line1);

	GLuint uniID = glGetUniformLocation(shader1.ID, "sCale");
	glfwSwapBuffers(window);
	
	while (!glfwWindowShouldClose(window))
	{
		//Timer timer;
		glClearColor(0.03f, 0.10f, 0.12f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shader1.Activate();

		
		for (auto drawableObject : draws)
		{
			glUniform1f(uniID, scale);
			
		
			drawableObject->draw();
		}
		glfwSwapBuffers(window);

		glfwPollEvents();


	}
	glfwTerminate();
	return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//std::cout << key << "\n";

	if (key == GLFW_KEY_SPACE )
	{
		scale += incr;
		incr += 0.1f;
		std::cout << "Space pressed. scale is -> "<< scale << "\n";
	}


}