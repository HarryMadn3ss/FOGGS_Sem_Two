#include "Cube.h"
#include <iostream>
#include <fstream>
#include <string>




Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;

	_scale = Vector3{ 1,1,1 };

	_rotation = 0.0f;

	//material
	_material = Materials::Instance()->DefineMaterial(STANDARD);
	
}

Cube::Cube(Mesh* mesh, Texture2D* texture, Vector3 position, Vector3 scale) : SceneObject(mesh, texture)
{
	_position.x = position.x;
	_position.y = position.y;
	_position.z = position.z;

	_scale.x = scale.x;
	_scale.y = scale.y;
	_scale.z = scale.z;

	_rotation = 0.0f;

	//material
	_material = Materials::Instance()->DefineMaterial(STANDARD);

}

Cube::~Cube()
{
	delete _material;
	_material = nullptr;
}

void Cube::Draw()
{
	
	if (_mesh->vertices != nullptr && _mesh->normals != nullptr && _mesh->indices != nullptr)
	{	
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());		
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		//glTexCoordPointer(2, GL_FLOAT, 0, _mesh->texCoords);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glEnable(GL_NORMAL_ARRAY);
		//glNormalPointer(GL_FLOAT, 0, _mesh->normals);

		//material
		
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->shininess);


		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 1.0f, 1.0f);
		glScalef(_scale.x, _scale.y, _scale.z);

		glBegin(GL_TRIANGLES);

		for (int i = 0; i < _mesh->indexCount; i++)
		{		
			glTexCoord2fv((GLfloat*)&_mesh->texCoords[_mesh->indices[i]]);
			glNormal3fv((GLfloat*)&_mesh->normals[_mesh->indices[i]]);
			glVertex3fv((GLfloat*)&_mesh->vertices[_mesh->indices[i]]);

		}

		
	
		glEnd();

	

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
	
}

void Cube::Update()
{
	_rotation += 0.5f;
	_material = Materials::Instance()->GetMaterial();
}

