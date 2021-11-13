#include "common.hpp"

#include "SqlQueryQueue.hpp"

namespace Stand
{
	EXPOSED(void) autoshowAllfree()
	{
		SqlQueryQueue::add("UPDATE Data_Car SET BaseCost=0");
	}
}
