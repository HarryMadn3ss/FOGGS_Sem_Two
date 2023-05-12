#pragma once
#include "Structures.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class OBJLoader
{
protected:

private:
	OBJLoader();

	static OBJLoader* m_instance;
public:
	~OBJLoader();
	static OBJLoader* Instance();

	Mesh* LoadOBJToMesh(std::string objPath);
};

