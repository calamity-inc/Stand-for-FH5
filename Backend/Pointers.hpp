#pragma once

#include <cstdint>

#include "Pointer.hpp"

namespace Stand
{
	using get_spin_t = void*(__fastcall*)(void*);

	struct Pointers
	{
		inline static uint8_t* get_credits;
		inline static get_spin_t get_spin_regular;
		inline static get_spin_t get_spin_super;
		inline static char* available_in_autoshow_cond;
		//inline static Pointer sql;
		inline static Pointer sqlhijack_query; // char*
		inline static Pointer sqlhijack_detour;
	};
}
