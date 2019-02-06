#include "glShader.h"
#include "glad/glDebug.h"
#include <iostream>

Shader &Shader::Use()
{
	a3GL(glUseProgram(this->ID));
	return *this;
}

void Shader::Compile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource)
{
	GLuint sVertex, sFragment, gShader;
	// Vertex Shader
	a3GL(sVertex = glCreateShader(GL_VERTEX_SHADER));
	a3GL(glShaderSource(sVertex, 1, &vertexSource, NULL));
	a3GL(glCompileShader(sVertex));
	checkCompileErrors(sVertex, "VERTEX");
	// Fragment Shader
	a3GL(sFragment = glCreateShader(GL_FRAGMENT_SHADER));
	a3GL(glShaderSource(sFragment, 1, &fragmentSource, NULL));
	a3GL(glCompileShader(sFragment));
	checkCompileErrors(sFragment, "FRAGMENT");
	// If geometry shader source code is given, also compile geometry shader
	if (geometrySource != nullptr)
	{
		a3GL(gShader = glCreateShader(GL_GEOMETRY_SHADER));
		a3GL(glShaderSource(gShader, 1, &geometrySource, NULL));
		a3GL(glCompileShader(gShader));
		checkCompileErrors(gShader, "GEOMETRY");
	}
	// Shader Program
	a3GL(this->ID = glCreateProgram());
	a3GL(glAttachShader(this->ID, sVertex));
	a3GL(glAttachShader(this->ID, sFragment));
	if (geometrySource != nullptr)
		a3GL(glAttachShader(this->ID, gShader));
	a3GL(glLinkProgram(this->ID));
	checkCompileErrors(this->ID, "PROGRAM");
	// Delete the shaders as they're linked into our program now and no longer necessery
	a3GL(glDeleteShader(sVertex));
	a3GL(glDeleteShader(sFragment));
	if (geometrySource != nullptr)
		a3GL(glDeleteShader(gShader));
}

void Shader::SetFloat(const GLchar *name, GLfloat value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	a3GL(glUniform1f(glGetUniformLocation(this->ID, name), value));
}
void Shader::SetInteger(const GLchar *name, GLint value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	a3GL(glUniform1i(glGetUniformLocation(this->ID, name), value));
}
void Shader::SetVector2f(const GLchar *name, GLfloat x, GLfloat y, GLboolean useShader)
{
	if (useShader)
		this->Use();
	a3GL(glUniform2f(glGetUniformLocation(this->ID, name), x, y));
}
void Shader::SetVector2f(const GLchar *name, const v2 &value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	a3GL(glUniform2f(glGetUniformLocation(this->ID, name), value.x, value.y));
}
void Shader::SetVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader)
{
	if (useShader)
		this->Use();
	a3GL(glUniform3f(glGetUniformLocation(this->ID, name), x, y, z));
}
void Shader::SetVector3f(const GLchar *name, const v3 &value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	a3GL(glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z));
}
void Shader::SetVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader)
{
	if (useShader)
		this->Use();
	a3GL(glUniform4f(glGetUniformLocation(this->ID, name), x, y, z, w));
}
void Shader::SetVector4f(const GLchar *name, const v4 &value, GLboolean useShader)
{
	if (useShader)
		this->Use();
	a3GL(glUniform4f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z, value.w));
}
void Shader::SetMatrix4(const GLchar *name, const m4x4 &matrix, GLboolean useShader)
{
	if (useShader)
		this->Use();
	a3GL(glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, GL_TRUE, matrix.elements));
}


void Shader::checkCompileErrors(GLuint object, std::string type)
{
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM")
	{
		a3GL(glGetShaderiv(object, GL_COMPILE_STATUS, &success));
		if (!success)
		{
			a3GL(glGetShaderInfoLog(object, 1024, NULL, infoLog));
			std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
		}
	}
	else
	{
		glGetProgramiv(object, GL_LINK_STATUS, &success);
		if (!success)
		{
			a3GL(glGetProgramInfoLog(object, 1024, NULL, infoLog));
			std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
		}
	}
}