#pragma once

#include <json11.hpp>
#include <array>
#include "PropertyMacro.hpp"

namespace kantai
{
	namespace data
	{
		/*
		* 最大値と最小値を取るクラス
		*/
		class MinMax
		{
			PROPERTY(int, Min);
			PROPERTY(int, Max);

		public:
			/*
			* 最大値と最小値を取るクラス
			*/
			MinMax() {}

			/*
			* 最大値と最小値を取るクラス
			*/
			MinMax(const int min, const int max)
				: Min(min), Max(max) {}

			/*
			* 最大値と最小値を取るクラス
			*/
			MinMax(const std::array<int, 2>& minmax)
				: Min(minmax[0]), Max(minmax[1]) {}

			/*
			* 最大値と最小値を取るクラス
			*/
			MinMax(const json11::Json& json)
			{
				const auto items = json.array_items();
				Min = items[0].int_value();
				Max = items[1].int_value();
			}

			MinMax& operator=(const MinMax& obj)
			{
				Min = obj.Min;
				Max = obj.Max;
				return *this;
			}
		};
	}
}