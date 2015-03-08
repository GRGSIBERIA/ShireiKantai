#pragma once

#include <json11.hpp>
#include <vector>
#include <Siv3D.hpp>

namespace kantai
{
	namespace data
	{
		/*
		* 初期装備を表すクラス
		*/
		class DefEq
		{
			std::vector<String> Equips;

		public:
			/*
			* 初期装備を表すクラス
			*/
			DefEq() { }

			/*
			* 初期装備を表すクラス
			*/
			DefEq(const std::vector<String>& equips) { Equips = equips; }

			/*
			* 初期装備を表すクラス
			*/
			template <int NUM>
			DefEq(const std::array<String, NUM>& equips) { Equips = equips; }

			/*
			* 初期装備を表すクラス
			*/
			DefEq(const json11::Json& json)
			{
				if (json.is_array())
				{
					const auto items = json.array_items();
					for (const auto item : items)
					{
						Equips.push_back(Widen(item.string_value()));
					}
				}
				else
				{
					Equips.push_back(Widen(json.string_value()));
				}
			}

			DefEq& operator=(const DefEq& obj)
			{
				Equips = obj.Equips;
				return *this;
			}

			std::vector<String>& __GetEquips() { return Equips; }
			String __GetEquips(int i) const { return Equips[i]; }
			void __SetEquips(int i, int val) { Equips[i] = val; }
			__declspec(property(get = __GetEquips, put = __SetEquips)) String Equips[];
		};
	}
}