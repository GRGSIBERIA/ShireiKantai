#pragma once

#include <array>
#include <memory>
#include <json11.hpp>

#include "PropertyMacro.hpp"

namespace kantai
{
	namespace data
	{
		/*
		* 資源を表すクラス
		*/
		class Shigen
		{
			PROPERTY(int, Fuel);
			PROPERTY(int, Bullet);
			PROPERTY(int, Steel);
			PROPERTY(int, Bauxite);

		public:
			Shigen() {}

			/*
			* 資源を表すクラス
			*/
			Shigen(const int fuel, const int bullet, const int steel, const int bauxite)
				: Fuel(fuel), Bullet(bullet), Steel(steel), Bauxite(bauxite) {}

			/*
			* 資源を表すクラス
			* \param [in] shigen 燃料/弾薬/鋼材/ボーキ
			*/
			Shigen(const std::array<int, 4>& shigen)
				: Fuel(shigen[0]), Bullet(shigen[1]), Steel(shigen[2]), Bauxite(shigen[3]) {}

			/*
			* 資源を表すクラス
			* \param [in] json 資源JSON
			*/
			Shigen(const json11::Json& json)
			{
				const auto items = json.array_items();
				Fuel = items[0].int_value();
				Bullet = items[1].int_value();
				Steel = items[2].int_value();
				Bauxite = items[3].int_value();
			}

			/*
			* 資源を表すクラス
			* \param [in] shigen 資源
			*/
			Shigen(const Shigen& shigen)
				: Fuel(shigen.Fuel), Bullet(shigen.Bullet), Steel(shigen.Steel), Bauxite(shigen.Bauxite) {}

			/*
			* =演算子
			*/
			Shigen& operator=(const Shigen& shigen)
			{
				Fuel = shigen.Fuel;
				Bullet = shigen.Bullet;
				Steel = shigen.Steel;
				Bauxite = shigen.Bauxite;
				return *this;
			}
		};
	}
}