#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadColors(ifstream& inFile, Mesh& mesh);  
	void LoadTextures(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);


	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.vertexCount;

		if (mesh.vertexCount > 0)
		{
			mesh.vertices = new Vertex[mesh.vertexCount];

			for (int i = 0; i < mesh.vertexCount; i++)
			{
				inFile >> mesh.vertices[i].x;
				inFile >> mesh.vertices[i].y;
				inFile >> mesh.vertices[i].z;
			}
		}
	}

	void LoadColors(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.colorCount;
		if (mesh.colorCount > 0)
		{
			mesh.colors = new Color[mesh.colorCount];
			for (int i = 0; i < mesh.colorCount; i++)
			{
				inFile >> mesh.colors[i].r;
				inFile >> mesh.colors[i].g;
				inFile >> mesh.colors[i].b;
			}
		}
		
	}
	
	void LoadTextures(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.texCoordCount;
		mesh.texCoords = new TexCoord[mesh.texCoordCount];
		for (int i = 0; i < mesh.texCoordCount; i++)
		{
			inFile >> mesh.texCoords[i].u;
			inFile >> mesh.texCoords[i].v;

		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.indexCount;
		mesh.indices = new GLushort[mesh.indexCount];
		for (int i = 0; i < mesh.indexCount; i++)
		{
			inFile >> mesh.indices[i];
		}
	}


	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}
		else
		{
			LoadVertices(inFile, *mesh);
			LoadColors(inFile, *mesh);
			LoadTextures(inFile, *mesh);		
			LoadIndices(inFile, *mesh);
		}

		inFile.close();
		

		/*inFile >> mesh->vertexCount;
		mesh->vertices = new Vertex[mesh->vertexCount];
		for (int i = 0; i < mesh->vertexCount; i++)
		{
			inFile >> mesh->vertices[i].x;
			inFile >> mesh->vertices[i].y;
			inFile >> mesh->vertices[i].z;
		}
		inFile >> mesh->colorCount;
		mesh->colors = new Color[mesh->colorCount];
		for (int i = 0; i < mesh->colorCount; i++)
		{
			inFile >> mesh->colors[i].r;
			inFile >> mesh->colors[i].g;
			inFile >> mesh->colors[i].b;
		}
		inFile >> mesh->texCoordCount;
		mesh->texCoords = new TexCoord[mesh->texCoordCount];
		for (int i = 0; i < mesh->texCoordCount; i++)
		{
			inFile >> mesh->texCoords[i].u;
			inFile >> mesh->texCoords[i].v;
			
		}
		inFile >> mesh->indexCount;
		mesh->indices = new GLushort[mesh->indexCount];
		for (int i = 0; i < mesh->indexCount; i++)
		{
			inFile >> mesh->indices[i];
		}

		inFile.close();*/
		


		return mesh;
	}
}