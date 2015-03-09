#pragma once

#include <array>
#include <memory>
#include <json11.hpp>

#include "RecordBase.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			/*
			* 資源を表すクラス
			*/
			class Shigen : public RecordBase
			{
				PROPERTY(int, fuel);
				PROPERTY(int, bullet);
				PROPERTY(int, steel);
				PROPERTY(int, bauxite);

			public:
				Shigen() : fuel(0), bullet(0), steel(0), bauxite(0) {}

				/*
				* 資源を表すクラス
				*/
				Shigen(const int fuel, const int bullet, const int steel, const int bauxite)
					: fuel(fuel), bullet(bullet), steel(steel), bauxite(bauxite) {}

				/*
				* 資源を表すクラス
				* \param [in] shigen 燃料/弾薬/鋼材/ボーキ
				*/
				Shigen(const std::array<int, 4>& shigen)
					: fuel(shigen[0]), bullet(shigen[1]), steel(shigen[2]), bauxite(shigen[3]) {}

				/*
				* 資源を表すクラス
				* \param [in] json 資源JSON
				*/
				Shigen(const json11::Json& json)
				{
					const auto items = json.array_items();
					fuel = items[0].int_value();
					bullet = items[1].int_value();
					steel = items[2].int_value();
					bauxite = items[3].int_value();
				}

				/*
				* 資源を表すクラス
				* \param [in] shigen 資源
				*/
				Shigen(const Shigen& shigen)
					: fuel(shigen.fuel), bullet(shigen.bullet), steel(shigen.steel), bauxite(shigen.bauxite) {}

				/*
				* =演算子
				*/
				Shigen& operator=(const Shigen& shigen)
				{
					fuel = shigen.fuel;
					bullet = shigen.bullet;
					steel = shigen.steel;
					bauxite = shigen.bauxite;
					return *this;
				}

				/*
				* JSONに変換
				*/
				json11::Json ToJson() const
				{
					return json11::Json::array{
						fuel, bullet, steel, bauxite
					};
				}
			};
		}
	}
}