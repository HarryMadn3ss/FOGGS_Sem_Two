#include "StaticObject.h"


StaticObject::StaticObject(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, nullptr)
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
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->texCoords);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);

		glBegin(GL_TRIANGLES);

		for (int i = 0; i < 36; i++)
		{
			glColor3fv(&_mesh->colors[_mesh->indices[i]].r);			
			//glTexCoord2fv(&_mesh->texCoords[_mesh->indices[i]].u);
			glVertex3fv(&_mesh->vertices[_mesh->indices[i]].x);
		}

		glEnd();

		glPopMatrix();
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void StaticObject::Update()
{

}

