#pragma once
#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <cstring>

class ShaderProgram {

private:
	unsigned int vertShader = 0;
	unsigned int fragShader = 0;
	unsigned int shaderProgram = 0;

public:
	bool vertShaderSuccess = false;
	bool fragShaderSuccess = false;
	bool linkProgramSuccess = false;

	ShaderProgram();
	~ShaderProgram();
	void Init(const char* vertShaderPath, const char* fragShaderPath);

	


};