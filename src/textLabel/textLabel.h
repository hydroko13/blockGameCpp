#pragma once

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>

class TextLabel {
private:
	std::string text;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int VAO;
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
public:
	TextLabel(std::string text);

	void Init();
	void Draw();

};