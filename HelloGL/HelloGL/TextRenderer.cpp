#include "TextRenderer.h"

TextRenderer* TextRenderer::m_instance = nullptr;

TextRenderer::TextRenderer()
{

}

TextRenderer::~TextRenderer()
{
	delete m_instance;
	m_instance = nullptr;
}

TextRenderer* TextRenderer::Instance()
{
	if (!m_instance)
	{
		m_instance = new TextRenderer;
	}
	return m_instance;
}

void TextRenderer::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();

	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(-5.0f, 5.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);

	glPopMatrix();
}
