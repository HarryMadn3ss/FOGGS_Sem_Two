#pragma once

#include "Structures.h"

class Texture2D
{
protected:


private:
	

public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);

	GLuint GetID() const { return _ID;  }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }

	GLuint _ID;
	int _width, _height;
};

