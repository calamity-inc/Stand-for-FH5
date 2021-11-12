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
		static bool isBusy();
	public:
		static void add(std::string&& query);
		static void checkRun();
	};
}
