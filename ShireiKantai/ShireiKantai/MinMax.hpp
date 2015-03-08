#pragma once

#include <json11.hpp>
#include <array>

#include "RecordBase.hpp"
#include "PropertyMacro.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			/*
			* �ő�l�ƍŏ��l�����N���X
			*/
			class MinMax : public RecordBase
			{
				PROPERTY(int, min);
				PROPERTY(int, max);

			public:
				/*
				* �ő�l�ƍŏ��l�����N���X
				*/
				MinMax() {}

				/*
				* �ő�l�ƍŏ��l�����N���X
				*/
				MinMax(const int min, const int max)
					: min(min), max(max) {}

				/*
				* �ő�l�ƍŏ��l�����N���X
				*/
				MinMax(const std::array<int, 2>& minmax)
					: min(minmax[0]), max(minmax[1]) {}

				/*
				* �ő�l�ƍŏ��l�����N���X
				*/
				MinMax(const json11::Json& json)
				{
					const auto items = json.array_items();
					min = items[0].int_value();
					max = items[1].int_value();
				}

				MinMax& operator=(const MinMax& obj)
				{
					min = obj.min;
					max = obj.max;
					return *this;
				}
			};
		}
	}
}