#include "StaticObject.h"


StaticObject::StaticObject(Mesh* mesh, float x, float y, float z) : SceneObject(mesh)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

StaticObject::~StaticObject()
{

}

void StaticObject::Draw()
{
	if (_mesh->vertices != nullptr && _mesh->colors != nullptr && _mesh->indices != nullptr)
	{
		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);

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

void StaticObject::Update()
{

}

