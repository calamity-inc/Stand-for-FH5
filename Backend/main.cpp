#include "common.hpp"

#include <Window.hpp>

#include "addxp.hpp"
#include "autoshowAvailable.hpp"
#include "SqlQueryQueue.hpp"

BOOL APIENTRY DllMain(HMODULE hmod, DWORD reason, PVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hmod);
	}
	return TRUE;
}

namespace Stand
{
	EXPOSED(bool) checkProcess()
	{
		if (State::game_process = Process::get("ForzaHorizon5.exe"))
		{
			State::game_mod = State::game_process->open();
			State::get_credits_patch.mod = State::game_mod;
			return true;
		}
		return false;
	}

	EXPOSED(void) mainloop(char* out, size_t outSize)
	{
		if (!Process::get(State::game_process->id))
		{
			strcpy_s(out, outSize, "reset");
			State::game_process.reset();
			State::game_mod.reset();
			State::patterns_scanned = false;
			State::get_credits_patch.forget();
			return;
		}

		if (Window::getFocsed().getOwnerProcessId() == State::game_process->id)
		{
			if (!State::game_focused)
			{
				State::game_focused = true;
				strcpy_s(out, outSize, "focus");
			}
		}
		else
		{
			if (State::game_focused)
			{
				State::game_focused = false;
				strcpy_s(out, outSize, "unfocus");
			}
		}

		if (ready())
		{
			SqlQueryQueue::checkRun();
		}
	}

	EXPOSED(void) die()
	{
		if (ready())
		{
			State::get_credits_patch.unpatch();
			set_skill_point_used_xp_values(0, 200);
			autoshowAvailableSet(0);
		}
	}
}
