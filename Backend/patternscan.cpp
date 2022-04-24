#include "common.hpp"

#include <pattern_macros.hpp>
#include <Pattern.hpp>
#include <Thread.hpp>

#include "Pointers.hpp"

namespace Stand
{
	EXPOSED(void) patternscanInit()
	{
		soup::Thread t([]()
		{
			{
				SIG_INST("48 89 5C 24 10 48 89 7C 24 18 55 48 8D 6C 24 A9 48 81 EC B0 00 00 00 33 DB 89 5D 67 48 8B 79 58");
				auto p = State::game_mod->externalScan(sig_inst);
				Pointers::get_credits = p.as<uint8_t*>();
			}

			{
				SIG_INST("48 8B 0D ? ? ? ? E8 ? ? ? ? 90 44 8B C3 33 D2");
				Pointers::get_spin_regular = State::game_mod->externalScan(sig_inst).sub(23).as<get_spin_t>();
			}

			{
				SIG_INST("48 8B 0D ? ? ? ? E8 ? ? ? ? 90 44 8B C3 BA 01");
				Pointers::get_spin_super = State::game_mod->externalScan(sig_inst).sub(23).as<get_spin_t>();
			}

			{
				SIG_INST("80 BD 40 01 00 00 00 74 10 48 8D 15");
				Pointers::available_in_autoshow_cond = State::game_mod->externalScan(sig_inst).add(12).externalRip(*State::game_mod).as<char*>();
			}

			/*{
				SIG_INST("0F 84 87 00 00 00 49 8B 5C 24 08 48 8B 0D");
				Pointers::sql = State::game_mod->externalScan(sig_inst).add(14).externalRip(*State::game_mod);
			}*/

			{
				SIG_INST("66 49 0F 7E D9 48 8D 15 ? ? ? ? 48 8D 4D 00 E8");
				auto p = State::game_mod->externalScan(sig_inst);
				Pointers::sqlhijack_query = p.add(8).externalRip(*State::game_mod);
				Pointers::sqlhijack_detour = p.add(0x57);
			}

			State::patterns_scanned = true;
		});
		t.awaitCompletion();
	}

	EXPOSED(int) patternscanStatus()
	{
		if (State::patterns_scanned)
		{
			if (!Pointers::get_credits)
			{
				return 2;
			}
			if (!Pointers::get_spin_regular)
			{
				return 3;
			}
			if (!Pointers::get_spin_super)
			{
				return 4;
			}
			if (!Pointers::available_in_autoshow_cond)
			{
				return 6;
			}
			if (!Pointers::sqlhijack_query)
			{
				return 7;
			}
			/*if (!Pointers::sql)
			{
				return 8;
			}*/
			return 1;
		}
		return 0;
	}
}