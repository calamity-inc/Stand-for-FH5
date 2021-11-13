#pragma once

#include <string>
#include <queue>

namespace Stand
{
	class SqlQueryQueue
	{
	private:
		inline static std::queue<std::string> queue;

	private:
		static void ensureRestoreProc();
		[[nodiscard]] static bool isBusy();
	public:
		[[nodiscard]] static bool ready();
		static void add(std::string&& query);
		static void checkRun();
	};
}
