#include "OBJLoader.h"

OBJLoader* OBJLoader::m_instance = nullptr;

OBJLoader::OBJLoader()
{

}

OBJLoader::~OBJLoader()
{
	delete m_instance;
	m_instance = nullptr;
}

OBJLoader* OBJLoader::Instance()
{
	if (!m_instance)
	{
		m_instance = new OBJLoader();
	}
	return m_instance;
}

Mesh* OBJLoader::LoadOBJToMesh(std::string objPath)
{
	// Open the .obj file
	std::ifstream inFile = std::ifstream(objPath.c_str());

	if (!inFile.good())
	{
		std::cout << "error with file:" << objPath << std::endl;
		return nullptr;
	}

	// Setup vectors for storage.
	Mesh* resultMesh = new Mesh();
	std::vector<Vertex>* verts = new std::vector<Vertex>();
	std::vector<TexCoord>* tex = new std::vector<TexCoord>();
	std::vector<Vector3>* norm = new std::vector<Vector3>();
	std::vector<GLushort>* indices = new std::vector<GLushort>();

	std::vector<Vector3> positions(1, Vector3{ 0, 0, 0 });
	std::vector<TexCoord> texcoords(1, TexCoord{ 0, 0 });
	std::vector<Vector3> normals(1, Vector3{ 0, 0, 0 });
	std::string lineStr;

	// Read the entire .obj file
	while (std::getline(inFile, lineStr))
	{
		//set up strings to be read in and compared for sorting
		std::istringstream lineSS(lineStr);
		std::string lineType;
		lineSS >> lineType;

		// Reading a vertex
		if (lineType == "v")
		{
			float x = 0, y = 0, z = 0;
			lineSS >> x >> y >> z;
			positions.push_back(Vector3{ x, y, z });
		}

		// Reading a Texture UV
		if (lineType == "vt")
		{
			float u = 0, v = 0;
			lineSS >> u >> v;
			texcoords.push_back(TexCoord{ u, v });
		}

		// Reading a Normal
		if (lineType == "vn")
		{
			float i = 0, j = 0, k = 0;
			lineSS >> i >> j >> k;
			normals.push_back(Vector3{ i, j, k });
		}

		// Reading a Face
		if (lineType == "f")
		{
			std::vector<OBJReferances> referances;
			std::string referancesStr;

			// Get each part of the face
			while (lineSS >> referancesStr)
			{
				std::istringstream dataReadIn(referancesStr);
				std::string vStr, vtStr, vnStr;

				// Read the vertex index
				std::getline(dataReadIn, vStr, '/');
				// Read the UV index
				std::getline(dataReadIn, vtStr, '/');
				// Read the normal index
				std::getline(dataReadIn, vnStr, '/');

				int v = atoi(vStr.c_str());
				int vt = atoi(vtStr.c_str());
				int vn = atoi(vnStr.c_str());

				referances.push_back(OBJReferances(v, vt, vn));
			}

			// Add all the read data to the lists using the indices read from the face.
			for (int i = 0; i < referances.size(); i += 3)
			{
				const OBJReferances* p[3] = { &referances[i], &referances[i + 1], &referances[i + 2] };
				for (int j = 0; j < 3; ++j)
				{
					OBJLoaderVertices vert;
					verts->push_back(Vertex{ positions[p[j]->v].x, positions[p[j]->v].y, positions[p[j]->v].z });
					tex->push_back(TexCoord{ texcoords[p[j]->vt].u, texcoords[p[j]->vt].v });
					norm->push_back(Vector3{ normals[p[j]->vn].x, normals[p[j]->vn].y, normals[p[j]->vn].z });
					indices->push_back(indices->size());
				}
			}
		}
	}

	// Copy vertices into mesh
	resultMesh->vertices = &(*verts)[0];
	resultMesh->vertexCount = verts->size();

	// Copy normals into mesh
	resultMesh->normals = &(*norm)[0];
	resultMesh->normalCount = norm->size();

	// Copy UVs into mesh
	resultMesh->texCoords = &(*tex)[0];
	resultMesh->texCoordCount = tex->size();

	// Copy indices into mesh
	resultMesh->indices = &(*indices)[0];
	resultMesh->indexCount = indices->size();

	return resultMesh;
}