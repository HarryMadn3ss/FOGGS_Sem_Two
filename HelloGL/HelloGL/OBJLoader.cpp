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

std::vector<OBJLoaderVertices> OBJLoader::LoadOBJ(std::istream& inFile)
{
	std::vector<OBJLoaderVertices> _verts;

	std::vector<Vector4> positions(1, Vector4{0, 0, 0, 0});
	std::vector<Vector3> texcoords(1, Vector3{ 0, 0, 0 });
	std::vector<Vector3> normals(1, Vector3{ 0, 0, 0 }); 
	std::string lineStr;

	while (std::getline(inFile, lineStr))
	{
		//set up strings to be read in and compared for sorting
		std::istringstream lineSS(lineStr);
		std::string lineType;
		lineSS >> lineType;

		//vertex
		if (lineType == "v")
		{
			float x = 0, y = 0, z = 0, w = 1;
			lineSS >> x >> y >> z >> w;
			positions.push_back(Vector4{ x, y, z, w });
		}

		//texture
		if (lineType == "vt")
		{
			float u = 0, v = 0, w = 0;
			lineSS >> u >> v >> w;
			texcoords.push_back(Vector3{ u, v, w });
		}

		//normal
		if (lineType == "vn")
		{
			float i = 0, j = 0, k = 0;
			lineSS >> i >> j >> k;
			normals.push_back(Vector3{ i, j, k });
		}

		//faces
		if (lineType == "f")
		{
			std::vector<OBJReferances> referances;
			std::string referancesStr;
			while (lineSS >> referancesStr)
			{
				std::istringstream dataReadIn(referancesStr);
				std::string vStr, vtStr, vnStr;

				std::getline(dataReadIn, vStr, '/');
				std::getline(dataReadIn, vtStr, '/');
				std::getline(dataReadIn, vnStr, '/');

				int v = atoi(vStr.c_str());
				int vt = atoi(vtStr.c_str());
				int vn = atoi(vnStr.c_str());

				v = (v >= 0 ? v : positions.size() + v);
				v = (vt >= 0 ? vt : texcoords.size() + vt);
				v = (vn >= 0 ? vn : normals.size() + vn);
				referances.push_back(OBJReferances(v, vt, vn));

			}


		}
		return _verts;
	}

	return std::vector<OBJLoaderVertices>();
}
