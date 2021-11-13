#include "SqlQueryQueue.hpp"

#include <AssemblyBuilder.hpp>
#include <RemoteAllocRaii.hpp>

#include "Pointers.hpp"
#include "State.hpp"

namespace Stand
{
	static char query_og[] = {
		"UPDATE %s SET TopSpeed=%f, DistanceDriven=%u, TimeDriven=%u, TotalWinnings=%u, TotalRepairs=%u, NumPodiums=%u, Num"
		"Victories=%u, NumRaces=%u, NumOwners=%u, NumTimesSold=%u, TimeDrivenInRoadTrips=%u, CurOwnerNumRaces=%u, CurOwnerW"
		"innings=%u, NumSkillPointsEarned=%u, HighestSkillScore=%u, HasCurrentOwnerViewedCar=%u WHERE Id=%u"
	};

	static uint8_t detour_og[] = {
		0x49, 0xC7, 0xC6, 0xFF, 0xFF, 0xFF, 0xFF, 0x4D, 0x8B, 0xC6, 0x0F, 0x1F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x49, 0xFF, 0xC0, 0x46, 0x38, 0x3C, 0x00, 0x75, 0xF7
	};

	static std::unique_ptr<RemoteAllocRaii> restore_proc;

	void SqlQueryQueue::ensureRestoreProc()
	{
		if (!restore_proc)
		{
			AssemblyBuilder b{};
			b.beginFunction();

			b.setA(Pointers::sqlhijack_detour.as<uint64_t>());
			for (const auto& v : detour_og)
			{
				b.movPtrRAX(v);
				b.incRAX();
			}

			b.setA(Pointers::sqlhijack_query.as<uint64_t>());
			for (const auto& v : query_og)
			{
				b.movPtrRAX(v);
				b.incRAX();
			}

			b.endFunction();
			restore_proc = State::game_mod->copyInto(b.data(), b.size());
		}
	}

	bool SqlQueryQueue::isBusy()
	{
		if (restore_proc)
		{
			uint8_t detour_cur[sizeof(detour_og)];
			State::game_mod->externalRead(Pointers::sqlhijack_detour, &detour_cur, sizeof(detour_cur));
			return memcmp(detour_cur, detour_og, sizeof(detour_og)) != 0;
		}
		return false;
	}

	bool SqlQueryQueue::ready()
	{
		return Pointers::sqlhijack_detour.as<void*>() != nullptr;
	}

	void SqlQueryQueue::add(std::string&& query)
	{
		queue.emplace(std::move(query));
		checkRun();
	}

	void SqlQueryQueue::checkRun()
	{
		if (!queue.empty() && !isBusy())
		{
			ensureRestoreProc();
			auto query = std::move(queue.front());
			queue.pop();
			AssemblyBuilder b{};
			b.nop();
			b.nop();
			b.nop();
			b.nop();
			b.set8(query.size());
			b.setA(restore_proc->p.as<uint64_t>());
			b.callA();
			if (b.size() != sizeof(detour_og))
			{
				throw 0;
			}
			State::game_mod->externalWrite(Pointers::sqlhijack_query, query.data(), query.size());
			State::game_mod->externalWrite(Pointers::sqlhijack_detour, b.data(), b.size());
		}
	}
}
