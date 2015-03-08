#pragma once

#pragma once

#include <json11.hpp>
#include <vector>
#include <Siv3D.hpp>

#include "RecordBase.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			/*
			* 初期装備を表すクラス
			*/
			class MaxEq : public RecordBase
			{
				std::array<int, 5> slots;

			public:
				/*
				* 初期装備を表すクラス
				*/
				MaxEq() { }

				/*
				* 初期装備を表すクラス
				*/
				MaxEq(const std::array<int, 5>& slots) { this->slots = slots; }

				/*
				* 初期装備を表すクラス
				*/
				MaxEq(const json11::Json& json)
				{
					const auto items = json.array_items();
					for (int i = 0; i < items.size(); ++i)
					{
						slots[i] = items[i].int_value();
					}
				}

				MaxEq& operator=(const MaxEq& obj)
				{
					slots = obj.slots;
					return *this;
				}

				std::array<int, 5>& __Get_slots() { return slots; }
				int __Get_slots(int i) const { return slots[i]; }
				void __Set_slots(int i, int val) { slots[i] = val; }
				__declspec(property(get = __Get_slots, put = __Set_slots)) int slots[];
			};
		}
	}
}