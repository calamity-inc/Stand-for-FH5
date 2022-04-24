#include <cstring>

#include <AllocRaiiRemote.hpp>
#include <AssemblyBuilder.hpp>

#include "common.hpp"
#include "Pointers.hpp"

#include "SkillTreePerkVft.hpp"

namespace Stand
{
	static void getSpin(int amount, void* func)
	{
		if (!func)
		{
			return;
		}
		soup::AssemblyBuilder b{};
		b.setA(amount);
		b.retn();
		auto vfunc = State::game_mod->copyInto(b.data(), b.size());
		SkillTreePerkVft mockup;
		mockup.getAmount = vfunc->p.as<void*>();
		auto vftable = State::game_mod->copyInto(&mockup, sizeof(mockup));
		auto pVftable = vftable->p.as<SkillTreePerkVft*>();
		auto inst = State::game_mod->copyInto(&pVftable, sizeof(pVftable));
		State::game_mod->executeSync(func, inst->p.as<uintptr_t>());
	}

	EXPOSED(void) getSpinRegular(int amount)
	{
		getSpin(amount, Pointers::get_spin_regular);
	}
	
	EXPOSED(void) getSpinSuper(int amount)
	{
		getSpin(amount, Pointers::get_spin_super);
	}
}
