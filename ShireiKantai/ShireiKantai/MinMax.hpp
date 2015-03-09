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
			* 最大値と最小値を取るクラス
			*/
			class MinMax : public RecordBase
			{
				PROPERTY(int, min);
				PROPERTY(int, max);

			public:
				/*
				* 最大値と最小値を取るクラス
				*/
				MinMax() : min(0), max(0) {}

				/*
				* 最大値と最小値を取るクラス
				*/
				MinMax(const int min, const int max)
					: min(min), max(max) {}

				/*
				* 最大値と最小値を取るクラス
				*/
				MinMax(const std::array<int, 2>& minmax)
					: min(minmax[0]), max(minmax[1]) {}

				/*
				* 最大値と最小値を取るクラス
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

				/*
				* JSONに変換
				*/
				json11::Json ToJson() const
				{
					return json11::Json::array{
						min, max
					};
				}
			};
		}
	}
}