#include "common.hpp"

#include "Pointers.hpp"

namespace Stand
{
	EXPOSED(void) autoshowAvailableSet(int mode)
	{
		if (!ready())
		{
			return;
		}

		switch (mode)
		{
		default:
			State::game_mod->externalWrite(Pointers::available_in_autoshow_cond, " AND NotAvailableInAutoshow=0");
			break;

		case 1:
			State::game_mod->externalWrite(Pointers::available_in_autoshow_cond, "");
			break;

		case 2:
			State::game_mod->externalWrite(Pointers::available_in_autoshow_cond, " AND NotAvailableInAutoshow=1");
			break;
		}
	}
}
