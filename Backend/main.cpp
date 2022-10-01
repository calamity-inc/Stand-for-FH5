#include "common.hpp"

#include <Window.hpp>

#include "autoshowAvailable.hpp"
#include "Pointers.hpp"
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
		State::game_process = soup::Process::get("forzahorizon5.exe"); // Steam
		if (!State::game_process)
		{
			State::game_process = soup::Process::get("ForzaHorizon5.exe"); // Xbox
		}
		if (State::game_process)
		{
			State::game_mod = State::game_process->open();
			return true;
		}
		return false;
	}

	EXPOSED(void) mainloop(char* out, size_t outSize)
	{
		if (!soup::Process::get(State::game_process->id))
		{
			strcpy_s(out, outSize, "reset");
			State::game_process.reset();
			State::game_mod.reset();
			State::patterns_scanned = false;

			Pointers::get_spin_regular = nullptr;
			Pointers::get_spin_super = nullptr;
			Pointers::available_in_autoshow_cond = nullptr;
			Pointers::sqlhijack_query = nullptr;

			return;
		}

		if (soup::Window::getFocused().getOwnerPid() == State::game_process->id)
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

		if (SqlQueryQueue::ready())
		{
			SqlQueryQueue::checkRun();
		}
	}

	EXPOSED(void) die()
	{
		autoshowAvailableSet(0);
		if (SqlQueryQueue::ready())
		{
			SqlQueryQueue::finishQuery();
		}
	}
}
