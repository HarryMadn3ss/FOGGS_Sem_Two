#include "Texture2D.h"
#include <iostream>
#include <fstream>
#include <string>


Texture2D::Texture2D()
{

}

Texture2D::~Texture2D()
{
	glDeleteTextures();
}

bool Texture2D::Load(char* path, int width, int height)
{

}

GLuint Texture2D::GetID() const { return _ID; }
int Texture2D::GetWidth() const { return _width; }
int Texture2D::GetHeight() const { return _height; }