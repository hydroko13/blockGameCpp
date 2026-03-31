#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

class Game {
	// Game Class

private:

	GLFWwindow* glfwWindow;
	int windowWidth = 1024;
	int windowHeight = 720;

public:

	Game();
	~Game();

	void Run();
	
};

