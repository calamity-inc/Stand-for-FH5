#include "common.hpp"

#include <AssemblyBuilder.hpp>

#include "Pointers.hpp"

namespace Stand
{
	EXPOSED(void) lockcrSet(int amount)
	{
		if (!ready())
		{
			return;
		}
		AssemblyBuilder b{};
		b.setA(amount);
		b.retn();
		State::get_credits_patch.patch(Pointers::get_credits, b.data(), b.size());
	}

	EXPOSED(void) lockcrUnset()
	{
		State::get_credits_patch.unpatch();
	}
}
