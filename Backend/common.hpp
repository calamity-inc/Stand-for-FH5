#pragma once

#include "State.hpp"

#define EXPOSED(ret) extern "C" __declspec(dllexport) ret __cdecl
