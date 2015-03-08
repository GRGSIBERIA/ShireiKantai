#pragma once
#include "DBBase.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			/*
			* 装備用データベース
			*/
			class SoubiDB : public DBBase
			{
			public:
				SoubiDB() : DBBase(L"soubi.json")
			};
		}
	}
}