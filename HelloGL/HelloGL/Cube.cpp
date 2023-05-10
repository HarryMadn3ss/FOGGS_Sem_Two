#include "Cube.h"
#include <iostream>
#include <fstream>
#include <string>




Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;

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
	
	/*if (_mesh->vertices != nullptr && _mesh->normals != nullptr && _mesh->indices != nullptr)
	{*/		

	std::ifstream inFile("files/OBJFiles/Earth.obj");

		glBindTexture(GL_TEXTURE_2D, _texture->GetID());		
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		//glTexCoordPointer(2, GL_FLOAT, 0, _mesh->texCoords);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glEnable(GL_NORMAL_ARRAY);
		//glNormalPointer(GL_FLOAT, 0, _mesh->normals);

		//material
		
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->shininess);

		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 1.0f, 1.0f);

		glBegin(GL_TRIANGLES);

		//for (int i = 0; i < 36; i++)
		//{			
		//	/*glTexCoord2fv(&_mesh->texCoords[_mesh->indices[i]].u);
		//	glNormal3fv(&_mesh->normals[_mesh->indices[i]].x);
		//	glVertex3fv(&_mesh->vertices[_mesh->indices[i]].x);*/

		//}

		OBJLoader::Instance()->LoadOBJ(inFile);
	
		glEnd();

	

		glPopMatrix();
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	//}
	
}

void Cube::Update()
{
	_rotation += 0.5f;
	_material = Materials::Instance()->GetMaterial();
}

