#pragma once
#include "Common/Core.h"
#include "Glad.h"

inline s8 a3_GLGetErrorString(u32 errorCode)
{
	switch(errorCode)
	{
		case GL_INVALID_ENUM:                  return "Invalid enum";
		case GL_INVALID_VALUE:                 return "Invalid value";
		case GL_INVALID_OPERATION:             return "Invalid operation";
		case GL_OUT_OF_MEMORY:                 return "Out of memory";
		case GL_INVALID_FRAMEBUFFER_OPERATION: return "Invalid frame buffer operation";
		default: return "Unknow OpenGL error";
	}
}

#define a3GL(x) \
x;\
{\
GLenum error = glGetError();\
while (error != GL_NO_ERROR)\
{\
	printf("OpenGL Call[%d]: %s", error, a3_GLGetErrorString(error));\
	a3Assert(error == GL_NO_ERROR);\
	error = glGetError();\
}\
}
