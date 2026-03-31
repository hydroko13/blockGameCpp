#include <game/game.h>	



void framebufferResizeCallback(GLFWwindow* win, int width, int height)
{
	glViewport(0, 0, width, height);
}

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


	glfwMakeContextCurrent(this->glfwWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		throw "ERROR: Glad load failed!";
	}


	glfwSetFramebufferSizeCallback(this->glfwWindow, framebufferResizeCallback);
}

Game::~Game() {
	std::cout << "Game class destructor called!\n";

	glfwDestroyWindow(this->glfwWindow);
	glfwTerminate();

}

void Game::Run() {
	std::cout << "Running game!\n";

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	while (!glfwWindowShouldClose(this->glfwWindow)) {

		glClear(GL_COLOR_BUFFER_BIT);


		glfwSwapBuffers(this->glfwWindow);
		glfwPollEvents();


	}

}

