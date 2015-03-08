#pragma once

#include <Siv3D.hpp>
#include <json11.hpp>

#include "PropertyMacro.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			/*
			* ���R�[�h�̃x�[�X�N���X
			*/
			class RecordBase
			{
			public:
				RecordBase() {}

				virtual json11::Json ToJson() const { return json11::Json(); }
			};
		}
	}
}