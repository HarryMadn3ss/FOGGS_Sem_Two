#include "Materials.h"


Materials* Materials::m_instance = nullptr;

Materials::Materials()
{

}

Materials::~Materials()
{
	delete _material;
	_material = nullptr;
}

 Materials* Materials::Instance()
{
	if (!m_instance)
	{
		m_instance = new Materials;
	}
	return m_instance;
}

MaterialStruct* Materials::DefineMaterial(enum MATERIALCOLOR color)
{

	switch (color)
	{
	case STANDARD:
		_material = new MaterialStruct();
		//ambient
		_material->ambient.x = 1;
		_material->ambient.y = 1;
		_material->ambient.z = 1;
		_material->ambient.w = 1;

		//diffuse
		_material->diffuse.x = 1;
		_material->diffuse.y = 1;
		_material->diffuse.z = 1;
		_material->diffuse.w = 1.0;

		//specular
		_material->specular.x = 1.0;
		_material->specular.y = 1.0;
		_material->specular.z = 1.0;
		_material->specular.w = 1.0;

		//shininess
		_material->shininess = 100.0f;
		return _material;
		break;

	case RED:
		_material = new MaterialStruct();
		//ambient
		_material->ambient.x = 0.8;
		_material->ambient.y = 0.05;
		_material->ambient.z = 0.05;
		_material->ambient.w = 1;

		//diffuse
		_material->diffuse.x = 0.8;
		_material->diffuse.y = 0.05;
		_material->diffuse.z = 0.05;
		_material->diffuse.w = 1.0;

		//specular
		_material->specular.x = 1.0;
		_material->specular.y = 1.0;
		_material->specular.z = 1.0;
		_material->specular.w = 1.0;

		//shininess
		_material->shininess = 100.0f;
		return _material;
		break;

	case BLUE:
		_material = new MaterialStruct();
		//ambient
		_material->ambient.x = 0.05;
		_material->ambient.y = 0.05;
		_material->ambient.z = 0.8;
		_material->ambient.w = 1;

		//diffuse
		_material->diffuse.x = 0.05;
		_material->diffuse.y = 0.05;
		_material->diffuse.z = 0.8;
		_material->diffuse.w = 1.0;

		//specular
		_material->specular.x = 1.0;
		_material->specular.y = 1.0;
		_material->specular.z = 1.0;
		_material->specular.w = 1.0;

		//shininess
		_material->shininess = 100.0f;
		return _material;
		break;

	case GREEN:
		_material = new MaterialStruct();
		//ambient
		_material->ambient.x = 0.05;
		_material->ambient.y = 0.8;
		_material->ambient.z = 0.05;
		_material->ambient.w = 1;

		//diffuse
		_material->diffuse.x = 0.05;
		_material->diffuse.y = 0.8;
		_material->diffuse.z = 0.05;
		_material->diffuse.w = 1.0;

		//specular
		_material->specular.x = 1.0;
		_material->specular.y = 1.0;
		_material->specular.z = 1.0;
		_material->specular.w = 1.0;

		//shininess
		_material->shininess = 100.0f;
		return _material;
		break;
	default:
		break;
	}
	;
    return nullptr;
}
