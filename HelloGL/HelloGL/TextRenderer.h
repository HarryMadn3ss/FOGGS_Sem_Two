#pragma once

#include "Structures.h"

class TextRenderer
{
protected:

private:
	TextRenderer();
	static TextRenderer* m_instance;

public:
	~TextRenderer();
	static TextRenderer* Instance();

	void DrawString(const char* text, Vector3* position, Color* color);

};

