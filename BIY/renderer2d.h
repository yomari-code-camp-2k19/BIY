/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include "glad/glad.h"
#include "common/Core.h"
#include "math/Math.h"
#include "glTexture.h"
#include "glShader.h"
#include "math/Color.h"

class Renderer2D
{
public:
	// Constructor (inits shaders/shapes)
	Renderer2D(Shader &shader);
	// Destructor
	~Renderer2D();
	// Renders a defined quad textured with given sprite
	void Draw(Texture2D &texture, v2 position, v2 size = v2{ 10, 10 }, GLfloat rotate = 0.0f, v3 color = a3::color::White);
private:
	// Render state
	Shader shader;
	GLuint quadVAO;
	// Initializes and configures the quad's buffer and vertex attributes
	void initRenderData();
};

#endif