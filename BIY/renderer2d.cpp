#include "renderer2d.h"
#include "glad/glDebug.h"

Renderer2D::Renderer2D(Shader &shader)
{
	this->shader = shader;
	this->initRenderData();
}

Renderer2D::~Renderer2D()
{
	a3GL(glDeleteVertexArrays(1, &this->quadVAO));
}

void Renderer2D::DrawSprite(Texture2D &texture, v2 position, v2 size, GLfloat rotate, v3 color)
{
	// Prepare transformations
	this->shader.Use();
	m4x4 model;
	model = m4x4::TranslationC(v3{ position.x, position.y, 0.0f });  // First translate (transformations are: scale happens first, then rotation and then finall translation happens; reversed order)

	model *= m4x4::TranslationC(v3{ 0.5f * size.x, 0.5f * size.y, 0.0f }); // Move origin of rotation to center of quad
	model *= m4x4::RotationC(rotate, v3{ 0.0f, 0.0f, 1.0f }); // Then rotate
	model *= m4x4::TranslationC(v3{ -0.5f * size.x, -0.5f * size.y, 0.0f }); // Move origin back

	model *= m4x4::ScaleC(v3{ size.x, size.y, 1.0f }); // Last scale

	this->shader.SetMatrix4("model", model);

	// Render textured quad
	this->shader.SetVector3f("spriteColor", color);

	a3GL(glActiveTexture(GL_TEXTURE0));
	texture.Bind();

	a3GL(glBindVertexArray(this->quadVAO));
	a3GL(glDrawArrays(GL_TRIANGLES, 0, 6));
	a3GL(glBindVertexArray(0));
}

void Renderer2D::initRenderData()
{
	// Configure VAO/VBO
	GLuint VBO;
	GLfloat vertices[] = {
		// Pos      // Tex
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};

	a3GL(glGenVertexArrays(1, &this->quadVAO));
	a3GL(glGenBuffers(1, &VBO));

	a3GL(glBindBuffer(GL_ARRAY_BUFFER, VBO));
	a3GL(glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW));

	a3GL(glBindVertexArray(this->quadVAO));
	a3GL(glEnableVertexAttribArray(0));
	a3GL(glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0));
	a3GL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	a3GL(glBindVertexArray(0));
}