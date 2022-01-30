#include "PineClient.h"
#include <stdlib.h>

void PineClient::Init()
{
	pcsx2 = new PCSX2(28011);
	std::cout << "Game: " << pcsx2->GetGameTitle() << std::endl;
	Read();

}

void PineClient::Read()
{
	// Use for structs
	//for (auto i = 0; i < sizeof(Vector4) / sizeof(unsigned int); i++)
	//{
		//buffer[i] = pcsx2->Read<unsigned int>(0x001c503c + (i * sizeof(unsigned int)));
	//}

	unsigned int val = pcsx2->Read<unsigned int>(0x00252a70);
	std::cout << "Value: " << val << std::endl;

	Sleep(500);

	// Ingame Wrk, Field 1
	//pcsx2->Write(0x00252a71, 1);
	pcsx2->Write(0x00343077, 0);

}