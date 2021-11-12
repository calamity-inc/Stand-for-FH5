#pragma once

#include <memory>

#include <Module.hpp>
#include <Process.hpp>

#include "ExternalBytepatch.hpp"

namespace Stand
{
	struct State
	{
		inline static std::unique_ptr<Process> game_process;
		inline static std::shared_ptr<Module> game_mod;
		inline static bool patterns_scanned = false;
		inline static bool game_focused = false;
		inline static ExternalBytepatch get_credits_patch;
	};
}
