#include <iostream>

#include "glTexture.h"
#include "glad/glDebug.h"

Texture2D::Texture2D()
	: Width(0), Height(0), Internal_Format(GL_RGB), Image_Format(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_LINEAR), Filter_Max(GL_LINEAR)
{
	a3GL(glGenTextures(1, &this->ID));
}

void Texture2D::Generate(GLuint width, GLuint height, unsigned char* data)
{
	this->Width = width;
	this->Height = height;
	// Create Texture
	a3GL(glBindTexture(GL_TEXTURE_2D, this->ID));
	a3GL(glTexImage2D(GL_TEXTURE_2D, 0, this->Internal_Format, width, height, 0, this->Image_Format, GL_UNSIGNED_BYTE, data));
	// Set Texture wrap and filter modes
	a3GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->Wrap_S));
	a3GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->Wrap_T));
	a3GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->Filter_Min));
	a3GL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->Filter_Max));
	// Unbind texture
	a3GL(glBindTexture(GL_TEXTURE_2D, 0));
}

void Texture2D::Bind() const
{
	a3GL(glBindTexture(GL_TEXTURE_2D, this->ID));
}