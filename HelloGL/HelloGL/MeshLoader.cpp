#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadNormals(ifstream& inFile, Mesh& mesh);  
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

	void LoadNormals(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.normalCount;
		if (mesh.normalCount > 0)
		{
			mesh.normals = new Vector3[mesh.normalCount];
			for (int i = 0; i < mesh.normalCount; i++)
			{
				inFile >> mesh.normals[i].x;
				inFile >> mesh.normals[i].y;
				inFile >> mesh.normals[i].z;
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
			LoadTextures(inFile, *mesh);
			LoadNormals(inFile, *mesh);			
			LoadIndices(inFile, *mesh);
		}

		inFile.close();

		return mesh;
	}
}