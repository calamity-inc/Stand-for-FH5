#pragma once

#include "State.hpp"

#define EXPOSED(ret) extern "C" __declspec(dllexport) ret __cdecl

namespace Stand
{
	EXPOSED(int) patternscanStatus();

	inline bool ready()
	{
		return patternscanStatus() == 1;
	}
}
