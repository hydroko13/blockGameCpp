#include <game/game.h>	
#include <assert.h>



void framebufferResizeCallback(GLFWwindow* win, int width, int height)
{
	glViewport(0, 0, width, height);
}

void DebugCallbackOPENGL(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam) {
	
	
	std::cout << std::string(message, length) << std::endl;

	

}

Game::Game() {
	std::cout << "Game class constructor called!\n";


	if (glfwInit()) {
		std::cout << "GLFW initialization succeeded!\n";
	}
	else {
		std::cout << "GLFW initialization failed!\n";
		throw std::runtime_error("GLFW initialization failed!");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

	this->glfwWindow = glfwCreateWindow(this->windowWidth, this->windowHeight, "blockGameCpp", NULL, NULL);

	if (this->glfwWindow == NULL) {
		std::cout << "GLFW window creation failed!\n";
		throw std::runtime_error("GLFW window creation failed!");
	}
	else {
		std::cout << "GLFW window creation succeeded!\n";
	}


	glfwMakeContextCurrent(this->glfwWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "GLAD OpenGL loading failed!\n";
		throw std::runtime_error("GLAD OpenGL loading failed!");
	}
	else {
		std::cout << "GLAD OpenGL loading succeeded ( " << glGetString(GL_VERSION) << " )\n"; 

	}


	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(DebugCallbackOPENGL, nullptr);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);


	glfwSetFramebufferSizeCallback(this->glfwWindow, framebufferResizeCallback);

	this->shaderProgram.Init("vert.glsl", "frag.glsl");

	this->shaderProgram.Use();
}

Game::~Game() {
	std::cout << "Game class destructor called!\n";



}

GLFWwindow* Game::getWindow() {
	return this->glfwWindow;
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


