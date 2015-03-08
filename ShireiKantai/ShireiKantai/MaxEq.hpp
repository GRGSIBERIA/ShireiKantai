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
			* ����������\���N���X
			*/
			class MaxEq : public RecordBase
			{
				std::array<int, 5> Slots;

			public:
				/*
				* ����������\���N���X
				*/
				MaxEq() { }

				/*
				* ����������\���N���X
				*/
				MaxEq(const std::array<int, 5>& equips) { Slots = equips; }

				/*
				* ����������\���N���X
				*/
				MaxEq(const json11::Json& json)
				{
					const auto items = json.array_items();
					for (int i = 0; i < items.size(); ++i)
					{
						Slots[i] = items[i].int_value();
					}
				}

				MaxEq& operator=(const MaxEq& obj)
				{
					Slots = obj.Slots;
					return *this;
				}

				std::array<int, 5>& __GetSlots() { return Slots; }
				int __GetSlots(int i) const { return Slots[i]; }
				void __SetSlots(int i, int val) { Slots[i] = val; }
				__declspec(property(get = __GetSlots, put = __SetSlots)) int Slots[];
			};
		}
	}
}