#include "GLUTCallbacks.h"
#include "HelloGL.h"



namespace GLUTCallbacks
{
	namespace
	{
		HelloGL* helloGL = nullptr;
	}

	void init(HelloGL* gl)
	{
		helloGL = gl;
	}

	void Display()
	{
		if (helloGL != nullptr)
		{
			helloGL->Display();
		}
	}

	void Timer(int preferredRefresh)
	{
		helloGL->Update();
		glutTimerFunc(preferredRefresh, GLUTCallbacks::Timer, preferredRefresh);
	}
}

