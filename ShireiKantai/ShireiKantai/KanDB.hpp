#pragma once
#include "DBBase.hpp"
#include "KanRecord.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			/*
			* 艦娘用データベース
			*/
			class KanDB : public DBBase<KanRecord>
			{
			public:
				KanDB() : DBBase(L"Resources/kan.json") {	}
			};
		}
	}
}