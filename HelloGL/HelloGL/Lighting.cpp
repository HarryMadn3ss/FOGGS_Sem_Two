#include "Lighting.h"


Lighting* Lighting::m_instance = nullptr;

Lighting::Lighting()
{

}

Lighting::~Lighting()
{
	
	delete _lightData;
	_lightData = nullptr;

	delete _lightPosition;
	_lightPosition = nullptr;
}

Lighting* Lighting::Instance()
{
	if (!m_instance)
	{
		m_instance = new Lighting;
	}
	return m_instance;
}

LightingStruct* Lighting::SetLighting(bool on)
{
	if (on)
	{
		_lightData = new LightingStruct();
		_lightData->ambient.x = 0.2;
		_lightData->ambient.y = 0.2;
		_lightData->ambient.z = 0.2;
		_lightData->ambient.w = 1.0;
		_lightData->diffuse.x = 0.8;
		_lightData->diffuse.y = 0.8;
		_lightData->diffuse.z = 0.8;
		_lightData->diffuse.w = 1.0;
		_lightData->specular.x = 0.2;
		_lightData->specular.y = 0.2;
		_lightData->specular.z = 0.2;
		_lightData->specular.w = 1.0;

		return _lightData;
	}
	else
	{
		_lightData = new LightingStruct();
		_lightData->ambient.x = 0;
		_lightData->ambient.y = 0;
		_lightData->ambient.z = 0;
		_lightData->ambient.w = 0;
		_lightData->diffuse.x = 0;
		_lightData->diffuse.y = 0;
		_lightData->diffuse.z = 0;
		_lightData->diffuse.w = 0;
		_lightData->specular.x = 0;
		_lightData->specular.y = 0;
		_lightData->specular.z = 0;
		_lightData->specular.w = 0;

		return _lightData;
	}
	return nullptr;
}

Vector4* Lighting::SetLightingPosition()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;
	return _lightPosition;
}
