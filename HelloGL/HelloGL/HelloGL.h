#pragma once

#include <ctime>
#include <cstdlib>


#include "MeshLoader.h"
#include "GLUTCallbacks.h"

#include "Cube.h"
#include "StaticObject.h"
#include "LinkedList.h"

#define REFRESHRATE 16


class HelloGL
{
protected:

private:
	float triRotation;
	float squRotation;
	float rectRotation;

	Camera* camera;
		
	//SceneObject* objects[OBJECTARRAY];

	LinkedList* objectList;
	ListNode* objectHead;

	//lighting
	Vector4* _lightPosition;
	Lighting* _lightData;

	//text
	Vector3 _textVector = { 0.0f, 0.0f, 0.0f };
	Color _textColor = { 0.0f, 1.0f, 0.0f }; 

public:

	HelloGL(int argc, char* argv[]);

	~HelloGL(void);

	void Display();

	void Update();

	void Keyboard(unsigned char key, int x, int y);
	
	void InitObjects();

	void InitGL(int argc, char* argv[]);

	void InitLighting();

	void DrawString(const char* text, Vector3* position, Color* color);
};

