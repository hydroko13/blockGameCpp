#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Game {
	// Game Class

private:

	GLFWwindow* glfwWindow;
	int windowWidth = 800;
	int windowHeight = 450;

public:

	Game();
	~Game();

	void Run();
	
};


void framebufferResizeCallback(GLFWwindow* win, int width, int height);
void DebugCallbackOPENGL();