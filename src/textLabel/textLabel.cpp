#include <textLabel/textLabel.h>


TextLabel::TextLabel(std::string text) {
	this->text = text;




}

void TextLabel::Init() {
	this->vertices.clear();
	this->indices.clear();
	for (int i = 0; i < this->text.length(); i++) {
		this->vertices.push_back(-1.0f + (float)i * 0.1f);
		this->vertices.push_back(1.0f);

		this->vertices.push_back(-1.0f + (float)i * 0.1f);
		this->vertices.push_back(0.9f);

		this->vertices.push_back(-1.0f + (float)i * 0.1f + 0.1f);
		this->vertices.push_back(1.0f);

		this->vertices.push_back(-1.0f + (float)i * 0.1f + 0.1f);
		this->vertices.push_back(0.9f);

		this->indices.push_back(i * 4 + 0);
		this->indices.push_back(i * 4 + 1);
		this->indices.push_back(i * 4 + 2);

		this->indices.push_back(i * 4 + 1);
		this->indices.push_back(i * 4 + 2);
		this->indices.push_back(i * 4 + 3);


		 
	}

	float* verticesArr = this->vertices.data();
	unsigned int* indexArr = this->indices.data();
	int verticesSize = this->vertices.size() * sizeof(float);
	int idxSize = this->indices.size() * sizeof(unsigned int);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &this->VBO);
	glGenBuffers(1, &this->EBO);




	glBindVertexArray(VAO);

	

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, verticesSize, verticesArr, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, idxSize, indexArr, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);


}

void TextLabel::Draw() {
	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, this->vertices.size(), GL_UNSIGNED_INT, 0);
}