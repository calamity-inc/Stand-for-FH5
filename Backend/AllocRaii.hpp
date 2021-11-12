#pragma once

#include <cstdlib>

namespace Stand
{
	struct AllocRaii
	{
		void* data;

		AllocRaii() noexcept
			: data(nullptr)
		{
		}

		AllocRaii(void* data) noexcept
			: data(data)
		{
		}

		AllocRaii(size_t size)
			: AllocRaii(malloc(size))
		{
		}

		~AllocRaii()
		{
			release();
		}
		
		void release()
		{
			if (data != nullptr)
			{
				free(data);
				data = nullptr;
			}
		}

		void operator=(AllocRaii&& b)
		{
			release();
			data = b.data;
			b.data = nullptr;
		}

		operator bool() const noexcept
		{
			return data != nullptr;
		}

		operator void* () const noexcept
		{
			return data;
		}
	};
}
