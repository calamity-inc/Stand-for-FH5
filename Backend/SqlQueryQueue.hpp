#pragma once

#include <string>
#include <queue>

#include <Timer.hpp>

namespace Stand
{
	class SqlQueryQueue
	{
	private:
		inline static std::queue<std::string> queue;
		inline static soup::Timer current_query_timer;

	public:
		[[nodiscard]] static bool ready();
		static void add(std::string&& query);
		static void checkRun();
		static void finishQuery();
	};
}
