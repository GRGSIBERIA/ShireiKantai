#pragma once
#include "DBBase.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			/*
			* �͖��p�f�[�^�x�[�X
			*/
			class KanDB : public DBBase
			{
			public:
				KanDB() : DBBase(L"kan.json") {}
			};
		}
	}
}