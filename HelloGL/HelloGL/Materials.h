#pragma once
#include "Structures.h"



enum MATERIALCOLOR
{
	RED, BLUE, GREEN, STANDARD
};


class Materials
{
protected:

private:
	Materials();
	static Materials* m_instance;

public:
	~Materials();
	static Materials* Instance();

	MaterialStruct* DefineMaterial(enum MATERIALCOLOR color);
	MaterialStruct* GetMaterial() { return _material; }
	
	MaterialStruct* _material;

};

