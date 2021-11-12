#include "addxp.hpp"

#include "common.hpp"

#include "Pointers.hpp"

namespace Stand
{
	EXPOSED(void) addxp(int amount)
	{
		if ((amount % 200) != 0)
		{
			set_skill_point_used_xp_values(1, amount);
		}
		else
		{
			set_skill_point_used_xp_values(amount / 200, 200);
		}
	}

	void set_skill_point_used_xp_values(int amount, int xp_value)
	{
		auto p = Pointer(State::game_mod->externalRead<void*>(Pointers::something_xp));
		p = Pointer(State::game_mod->externalRead<void*>(p.add(0x50)));
		p = Pointer(State::game_mod->externalRead<void*>(p.add(0x48)));
		p = Pointer(State::game_mod->externalRead<void*>(p.add(0x50)));
		p = Pointer(State::game_mod->externalRead<void*>(p.add(0xD0)));
		p = Pointer(State::game_mod->externalRead<void*>(p.add(0x18)));
		p = Pointer(State::game_mod->externalRead<void*>(p.add(0x50)));
		
		if (amount != 0)
		{
			State::game_mod->externalWrite<int>(p.add(0xA8), amount);
		}
		State::game_mod->externalWrite<int>(p.add(0xAC), xp_value);
	}
}
