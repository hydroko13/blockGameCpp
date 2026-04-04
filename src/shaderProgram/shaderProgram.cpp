#include <shaderProgram/shaderProgram.h>


ShaderProgram::ShaderProgram() {

}

ShaderProgram::~ShaderProgram() {
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	if (this->programCreated) {
		glDeleteProgram(this->shaderProgram);
	}
	
}

void ShaderProgram::Init(const char* vertShaderPath, const char* fragShaderPath) {

	std::filesystem::path resFolderPath = RESOURCES_PATH;

	std::filesystem::path vertPathFull = resFolderPath / vertShaderPath;
	std::filesystem::path fragPathFull = resFolderPath / fragShaderPath;

	std::ifstream vertShaderFile(vertPathFull);
	std::ifstream fragShaderFile(fragPathFull);

	if (!vertShaderFile.is_open()) {
		std::cout << "(shaderProgram.cpp) Failed to open file: " << vertPathFull << std::endl;
		throw std::runtime_error("(shaderProgram.cpp) Failed to open file!");

	}
	else {
		std::cout << "(shaderProgram.cpp) successfully opened file: " << vertPathFull << std::endl;
	}

	if (!fragShaderFile.is_open()) {
		std::cout << "(shaderProgram.cpp) Failed to open file: " << fragPathFull << std::endl;
		throw std::runtime_error("(shaderProgram.cpp) Failed to open file!");

	}
	else {
		std::cout << "(shaderProgram.cpp) successfully opened file: " << fragPathFull << std::endl;
	}

	std::ostringstream oss;
	std::string line;


	while (std::getline(vertShaderFile, line)) {
		oss << line << "\n";
	}

	std::string vertShaderSourceCode = oss.str();

	std::ostringstream oss2;
	std::string line2;


	while (std::getline(fragShaderFile, line2)) {
		oss2 << line2 << "\n";
	}

	std::string fragShaderSourceCode = oss2.str();

	const char* vertShaderSource = vertShaderSourceCode.c_str();
	const char* fragShaderSource = fragShaderSourceCode.c_str();
	int vertLen = std::strlen(vertShaderSource);
	int fragLen = std::strlen(fragShaderSource);

	this->vertShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(this->vertShader, 1, &vertShaderSource, &vertLen);

	this->fragShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(this->fragShader, 1, &fragShaderSource, &fragLen);

	glCompileShader(this->vertShader);
	int vertStatus;
	
	glGetShaderiv(this->vertShader, GL_COMPILE_STATUS, &vertStatus);
	if (vertStatus == GL_FALSE) {
		char shaderInfoLog[1024];
		glGetShaderInfoLog(vertShader, 1024, NULL, shaderInfoLog);
		this->vertShaderSuccess = false;
		std::cout << "(shaderProgram.cpp) vertex shader [" << vertPathFull << "] failed to compile: " << shaderInfoLog << std::endl;

	}
	else {
		std::cout << "(shaderProgram.cpp) vertex shader [" << vertPathFull << "] compiled successfully!\n";
		this->vertShaderSuccess = true;
	}

	glCompileShader(this->fragShader);
	int fragStatus;
	glGetShaderiv(this->fragShader, GL_COMPILE_STATUS, &fragStatus);

	if (fragStatus == GL_FALSE) {
		char shaderInfoLog[1024];
		glGetShaderInfoLog(fragShader, 1024, NULL, shaderInfoLog);
		std::cout << "(shaderProgram.cpp) fragment shader [" << fragPathFull << "] failed to compile: " << shaderInfoLog << std::endl;
		this->fragShaderSuccess = false;

	}
	else {
		std::cout << "(shaderProgram.cpp) fragment shader [" << fragPathFull << "] compiled successfully!\n";
		this->fragShaderSuccess = true;
	}

	if (fragShaderSuccess && vertShaderSuccess) {
		std::cout << "(shaderProgram.cpp) Both vertex and fragment shaders compiled succesfully, linking shader program...\n";
		this->shaderProgram = glCreateProgram();
		this->programCreated = true;

		glAttachShader(this->shaderProgram, this->vertShader);
		glAttachShader(this->shaderProgram, this->fragShader);

		glLinkProgram(this->shaderProgram);


		int linkStatus;
		glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &linkStatus);

		if (linkStatus == GL_FALSE) {
			char programInfoLog[1024];
			glGetProgramInfoLog(this->shaderProgram, 1024, NULL, programInfoLog);
			std::cout << "(shaderProgram.cpp) shader program failed to link: " << programInfoLog << std::endl;
			this->linkProgramSuccess = false;
		}
		else {
			std::cout << "(shaderProgram.cpp) shader program linked successfully!\n";
			this->linkProgramSuccess = true;
		}

		

	}
	else {
		std::cout << "(shaderProgram.cpp) Shader compilation failed, skipping shader program link!\n";
		linkProgramSuccess = false;
		this->programCreated = false;
	}
	

}

void ShaderProgram::Use() {
	assert(this->linkProgramSuccess && this->programCreated);
	glUseProgram(this->shaderProgram);
	std::cout << "Using shader program!\n";
}