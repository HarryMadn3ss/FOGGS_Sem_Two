#include "Cube.h"

Vertex Cube::indexedVertices[] = { 1, 1, 1,	-1, 1, 1, //v0-v1
									-1, -1, 1,	1, -1, 1, //v2-v3
									1, -1, -1,	1, 1, -1, //v4-v5
									-1, 1, -1,	-1, -1, -1 };

Color Cube::indexedColors[] = { 1, 1, 1,	1, 1, 0,
								1, 0, 0,	1, 0, 1,
								0, 0, 1,	0, 1, 1,
								0, 1, 0,	0, 0, 0 };

GLushort Cube::indices[] = { 0, 1, 2,	2, 3, 0,	//front
								0, 3, 4,	4, 5, 0,	//right
								0, 5, 6,	6, 1, 0,	//top
								1, 6, 7,	7, 2, 1,	//left
								7, 4, 3,	3, 2, 7,	//bottom
								4, 7, 6,	6, 5, 4 };	//back

Cube::Cube(float x, float y, float z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Cube::~Cube()
{

}

void Cube::Draw()
{
	
	glPushMatrix();

	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, 1.0f, 0.0f, 0.0f);

	glBegin(GL_TRIANGLES);

	for (int i = 0; i < 36; i++)
	{
		glColor3fv(&indexedColors[indices[i]].r);
		glVertex3fv(&indexedVertices[indices[i]].x);
	}
	
	glEnd();

	

	glPopMatrix();
}

void Cube::Update()
{
	_rotation += 0.5f;
}