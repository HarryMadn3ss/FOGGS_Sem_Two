#pragma once
#include "Structures.h"

class Lighting
{
protected:

private:
	Lighting();
	static Lighting* m_instance;

public:
	~Lighting();
	static Lighting* Instance();

	LightingStruct* SetLighting(bool on);
	Vector4* SetLightingPosition();
	LightingStruct* GetLighting() { return _lightData; }
	Vector4* GetLightPos() { return _lightPosition; }

	
	Vector4* _lightPosition;
	LightingStruct* _lightData;


};

