#pragma once

class HelloGL; //forward decleration to prevent cycle of dependency

namespace GLUTCallbacks
{
	void init(HelloGL* gl);

	void Display();

	void Timer(int preferredRefresh);

};

