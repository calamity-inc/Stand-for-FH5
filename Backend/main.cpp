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
		if (State::game_process = soup::Process::get("ForzaHorizon5.exe"))
		{
			State::game_mod = State::game_process->open();
			State::get_credits_patch.mod = State::game_mod;
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
			State::get_credits_patch.forget();

			Pointers::get_credits = nullptr;
			Pointers::get_spin_regular = nullptr;
			Pointers::get_spin_super = nullptr;
			Pointers::available_in_autoshow_cond = nullptr;
			Pointers::sqlhijack_query = nullptr;
			Pointers::sqlhijack_detour = nullptr;

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
		State::get_credits_patch.unpatch();
		autoshowAvailableSet(0);
	}
}
