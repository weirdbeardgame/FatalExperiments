#include <iostream>
#include "pine.h"
#include "PS2Math.h"

using namespace PINE;

class PineClient
{
private:
	
	Vector4 position;

	Shared* pcsx2;

	bool active;


	// cam_type

	unsigned int buffer[sizeof(Vector4) * sizeof(unsigned int)];

public:
	void Init();
	void Read();
};