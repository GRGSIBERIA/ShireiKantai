#pragma once

#include "DBBase.hpp"
#include "SoubiRecord.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			/*
			* �����p�f�[�^�x�[�X
			*/
			class SoubiDB : public DBBase<SoubiRecord>
			{
			public:
				SoubiDB() : DBBase(L"Resources/soubi.json") { }
			};
		}
	}
}