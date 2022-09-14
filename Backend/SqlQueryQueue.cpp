#include "SqlQueryQueue.hpp"

#include "Pointers.hpp"
#include "State.hpp"

namespace Stand
{
	static char query_og[] = {
		"UPDATE %s SET TopSpeed=%f, DistanceDriven=%u, TimeDriven=%u, TotalWinnings=%u, TotalRepairs=%u, NumPodiums=%u, Num"
		"Victories=%u, NumRaces=%u, NumOwners=%u, NumTimesSold=%u, TimeDrivenInRoadTrips=%u, CurOwnerNumRaces=%u, CurOwnerW"
		"innings=%u, NumSkillPointsEarned=%u, HighestSkillScore=%u, HasCurrentOwnerViewedCar=%u WHERE Id=%u"
	};

	bool SqlQueryQueue::ready()
	{
		return Pointers::sqlhijack_query.as<void*>() != nullptr;
	}

	void SqlQueryQueue::add(std::string&& query)
	{
		queue.emplace(std::move(query));
		checkRun();
	}

	void SqlQueryQueue::checkRun()
	{
		if (current_query_timer.isActive()
			&& current_query_timer.hasEnded()
			)
		{
			finishQuery();
		}

		if (!current_query_timer.isActive()
			&& !queue.empty()
			)
		{
			auto query = std::move(queue.front());
			queue.pop();
			State::game_mod->externalWrite(Pointers::sqlhijack_query, query.c_str(), query.size() + 1);

			current_query_timer.start(20000);
		}
	}

	void SqlQueryQueue::finishQuery()
	{
		State::game_mod->externalWrite(Pointers::sqlhijack_query, query_og, sizeof(query_og));

		current_query_timer.reset();
	}
}
