#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

constexpr auto WIDTH = (800);
constexpr auto HEIGHT = (600);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void initGlad();

int main() 
{
	initGlad();

	// init window
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);

	if (!window) 
	{
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// make sure glad is initialized	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// setup view size for openGL.
	// x and y are bottom left coordinates.
	glViewport(0, 0, WIDTH, HEIGHT);

	// callback for when window is resized.
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// game loop
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void initGlad()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}