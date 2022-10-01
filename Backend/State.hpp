#pragma once

#include <memory>

#include <BytepatchExternal.hpp>
#include <Module.hpp>
#include <Process.hpp>
#include <UniquePtr.hpp>

namespace Stand
{
	struct State
	{
		inline static soup::UniquePtr<soup::Process> game_process;
		inline static std::shared_ptr<soup::Module> game_mod;
		inline static bool patterns_scanned = false;
		inline static bool game_focused = false;
	};
}
