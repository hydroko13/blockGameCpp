#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <shaderProgram/shaderProgram.h>


class Game {
	// Game Class

private:

	GLFWwindow* glfwWindow;
	int windowWidth = 800;
	int windowHeight = 450;

	ShaderProgram shaderProgram;

public:

	Game();
	~Game();

	void Run();

	GLFWwindow* getWindow();
	
};


void framebufferResizeCallback(GLFWwindow* win, int width, int height);
void DebugCallbackOPENGL(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);