#pragma once

#include <Windows.h>

namespace Stand
{
	struct Sql;
	struct SqlResult;

	struct SqlResultVft
	{
		void(__fastcall* _0x000)(SqlResult*);
		void(__fastcall* _0x008)(SqlResult*);
		void(__fastcall* _0x010)(SqlResult*);
		void(__fastcall* _0x018)(SqlResult*);
		void(__fastcall* _0x020)(SqlResult*);
		void(__fastcall* _0x028)(SqlResult*);
		void(__fastcall* _0x030)(SqlResult*);
		void(__fastcall* _0x038)(SqlResult*);
		void(__fastcall* _0x040)(SqlResult*);
		void(__fastcall* _0x048)(SqlResult*);
		void(__fastcall* _0x050)(SqlResult*);
		void(__fastcall* _0x058)(SqlResult*);
		void(__fastcall* _0x060)(SqlResult*);
		void(__fastcall* _0x068)(SqlResult*);
		void(__fastcall* _0x070)(SqlResult*);
		void(__fastcall* _0x078)(SqlResult*);
		const char* (__fastcall* getColumnString)(SqlResult*, unsigned int maybe_row, const char* columnName, unsigned int unk_set_to_zero);
		void(__fastcall* _0x088)(SqlResult*);
		void(__fastcall* _0x090)(SqlResult*);
		void(__fastcall* _0x098)(SqlResult*);
		void(__fastcall* _0x0A0)(SqlResult*);
		DWORD(__fastcall* getColumnDword)(SqlResult*, unsigned int maybe_row, const char* columnName, unsigned int unk_set_to_zero);
		void(__fastcall* _0x0B0)(SqlResult*);
		void(__fastcall* _0x0B8)(SqlResult*);
		void(__fastcall* _0x0C0)(SqlResult*);
		void(__fastcall* _0x0C8)(SqlResult*);
		void(__fastcall* _0x0D0)(SqlResult*);
		void(__fastcall* _0x0D8)(SqlResult*);
		void(__fastcall* _0x0E0)(SqlResult*);
		void(__fastcall* _0x0E8)(SqlResult*);
		void(__fastcall* _0x0F0)(SqlResult*);
		void(__fastcall* _0x0F8)(SqlResult*);
		void(__fastcall* _0x100)(SqlResult*);
		void(__fastcall* _0x108)(SqlResult*);
		void(__fastcall* _0x110)(SqlResult*);
		void(__fastcall* _0x118)(SqlResult*);
		void(__fastcall* _0x120)(SqlResult*);
		void(__fastcall* _0x128)(SqlResult*);
		void(__fastcall* _0x130)(SqlResult*);
		void(__fastcall* _0x138)(SqlResult*);
		void(__fastcall* _0x140)(SqlResult*);
		void(__fastcall* _0x148)(SqlResult*);
		DWORD(__fastcall* countRows)(SqlResult*);
	};
	static_assert(sizeof(SqlResultVft) == 0x158);

	struct SqlResult
	{
		SqlResultVft* vft;
		__int64 pad[3];
	};

	struct SqlVft
	{
		void(__fastcall* _0x00)(Sql*);
		void(__fastcall* _0x08)(Sql*);
		void(__fastcall* _0x10)(Sql*);
		void(__fastcall* _0x18)(Sql*);
		void(__fastcall* _0x20)(Sql*);
		void(__fastcall* _0x28)(Sql*);
		void(__fastcall* _0x30)(Sql*);
		void(__fastcall* _0x38)(Sql*);
		void(__fastcall* _0x40)(Sql*);
		void(__fastcall* runSelect)(Sql*, void* out, const char* query);
	};
	static_assert(sizeof(SqlVft) == 0x50);

	struct Sql // ??_R4?$TRefCountedObjectThreadSafe@VCDatabase@Database@@@@6B@
	{
		SqlVft* vft;
	};

	//static void runSqlQuery(const char* query, size_t query_size)
	//{
	//	// Doesn't work because TLS
	//	Pointer pSql = State::game_mod->externalRead<Sql*>(Pointers::sql);
	//	Pointer pVft = State::game_mod->externalRead<SqlVft*>(pSql);
	//	Pointer fpRunSelect = State::game_mod->externalRead<void*>(pVft.add(offsetof(SqlVft, runSelect)));
	//	auto aRes = State::game_mod->allocate(sizeof(SqlResult));
	//	auto aQuery = State::game_mod->copyInto(query, query_size);
	//	AssemblyBuilder b{};
	//	b.beginFunction();
	//	b.setD(aRes->p.as<uint64_t>());
	//	b.set8(aQuery->p.as<uint64_t>());
	//	b.setA(fpRunSelect.as<uint64_t>());
	//	b.callA();
	//	b.endFunction();
	//	auto aProc = State::game_mod->copyInto(b.data(), b.size());
	//	State::game_mod->executeSync(aProc->p.as<void*>(), pSql.as<uintptr_t>());
	//}

	//template <size_t S>
	//static void runSqlQuery(const char(&query)[S])
	//{
	//	runSqlQuery(query, S);
	//}
}
