#pragma once

#include <json11.hpp>
#include <array>
#include "PropertyMacro.hpp"

namespace kantai
{
	namespace data
	{
		/*
		* �ő�l�ƍŏ��l�����N���X
		*/
		class MinMax
		{
			PROPERTY(int, Min);
			PROPERTY(int, Max);

		public:
			/*
			* �ő�l�ƍŏ��l�����N���X
			*/
			MinMax() {}

			/*
			* �ő�l�ƍŏ��l�����N���X
			*/
			MinMax(const int min, const int max)
				: Min(min), Max(max) {}

			/*
			* �ő�l�ƍŏ��l�����N���X
			*/
			MinMax(const std::array<int, 2>& minmax)
				: Min(minmax[0]), Max(minmax[1]) {}

			/*
			* �ő�l�ƍŏ��l�����N���X
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