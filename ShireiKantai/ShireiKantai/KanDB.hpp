#pragma once
#include "DBBase.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			/*
			* 艦娘用データベース
			*/
			class KanDB : public DBBase
			{
			public:
				KanDB() : DBBase(L"kan.json") {}
			};
		}
	}
}