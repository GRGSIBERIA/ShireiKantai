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
			class DefEq : public RecordBase
			{
				std::vector<String> equips;

			public:
				/*
				* ����������\���N���X
				*/
				DefEq() { }

				/*
				* ����������\���N���X
				*/
				DefEq(const std::vector<String>& equips) { this->equips = equips; }

				/*
				* ����������\���N���X
				*/
				template <int NUM>
				DefEq(const std::array<String, NUM>& equips) { this->equips = equips; }

				/*
				* ����������\���N���X
				*/
				DefEq(const json11::Json& json)
				{
					const auto items = json.array_items();
					for (const auto item : items)
					{
						equips.push_back(Widen(item.string_value()));
					}
				}

				DefEq& operator=(const DefEq& obj)
				{
					equips = obj.equips;
					return *this;
				}

				/*
				* Json�ɕϊ�
				*/
				json11::Json ToJson() const
				{
					std::vector<std::string> strings;
					for (unsigned int i = 0; i < equips.size(); ++i)
						strings.push_back(equips[i].narrow());

					return json11::Json::array{
						strings
					};
				}

				std::vector<String>& __Get_equips() { return equips; }
				String __Get_equips(int i) const { return equips[i]; }
				void __Set_equips(int i, const String& val) { equips[i] = val; }
				__declspec(property(get = __Get_equips, put = __Set_equips)) String equips[];
			};
		}
	}
}