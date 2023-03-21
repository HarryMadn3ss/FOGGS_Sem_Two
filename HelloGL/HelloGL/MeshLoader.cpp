#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadColours(ifstream& inFile, Mesh& mesh);
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

	void LoadColours(ifstream& inFile, Mesh& mesh)
	{
		//TODO: LOAD COLOURS
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		//TODO: Load Indices
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
		

		inFile >> mesh->vertexCount;
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
		inFile >> mesh->indexCount;
		mesh->indices = new GLushort[mesh->indexCount];
		for (int i = 0; i < mesh->indexCount; i++)
		{
			inFile >> mesh->indices[i];
		}

		inFile.close();
		


		return mesh;
	}
}