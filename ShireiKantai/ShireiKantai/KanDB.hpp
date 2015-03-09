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
			* �͖��p�f�[�^�x�[�X
			*/
			class KanDB : public DBBase<KanRecord>
			{
			public:
				KanDB() : DBBase(L"Resources/kan.json") {	}
			};
		}
	}
}