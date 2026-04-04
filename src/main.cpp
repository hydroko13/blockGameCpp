#include <iostream>
#include <game/game.h>
#include <GLFW/glfw3.h>

int main() {

	GLFWwindow* windowPtr;

	{
		Game game;

		game.Run();

		windowPtr = game.getWindow();

		// Game must be dropped here
	}

	glfwDestroyWindow(windowPtr);
	glfwTerminate();

	return 0;
}

