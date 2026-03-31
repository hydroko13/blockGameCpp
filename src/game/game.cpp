#include <game/game.h>	


Game::Game() {
	std::cout << "Game class constructor called!\n";


	if (!glfwInit()) /* CHECK FOR GLFW INIT ERROR */ {
		throw "ERROR: Glfw initialization failed!";
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->glfwWindow = glfwCreateWindow(this->windowWidth, this->windowHeight, "blockGameCpp", NULL, NULL);

	if (this->glfwWindow == NULL) {
		throw "ERROR: Glfw window creation failed!";
	}


}

Game::~Game() {
	std::cout << "Game class destructor called!\n";

	glfwDestroyWindow(this->glfwWindow);
	glfwTerminate();

}

void Game::Run() {
	std::cout << "Running game!\n";
}

