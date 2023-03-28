#include "Cube.h"
#include <iostream>
#include <fstream>
#include <string>




Cube::Cube(Mesh* mesh, float x, float y, float z) : SceneObject(mesh)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;

	_rotation = 0.0f;

	
}

Cube::~Cube()
{

}

void Cube::Draw()
{
	
	if (_mesh->vertices != nullptr && _mesh->colors != nullptr && _mesh->indices != nullptr)
	{
		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 1.0f, 1.0f);

		glBegin(GL_TRIANGLES);

		for (int i = 0; i < 36; i++)
		{
			glColor3fv(&_mesh->colors[_mesh->indices[i]].r);
			glVertex3fv(&_mesh->vertices[_mesh->indices[i]].x);
		}
	
		glEnd();

	

		glPopMatrix();
	}
	
}

void Cube::Update()
{
	_rotation += 0.5f;
}

