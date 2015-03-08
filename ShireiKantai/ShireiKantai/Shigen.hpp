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
		* ������\���N���X
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
			* ������\���N���X
			*/
			Shigen(const int fuel, const int bullet, const int steel, const int bauxite)
				: Fuel(fuel), Bullet(bullet), Steel(steel), Bauxite(bauxite) {}

			/*
			* ������\���N���X
			* \param [in] shigen �R��/�e��/�|��/�{�[�L
			*/
			Shigen(const std::array<int, 4>& shigen)
				: Fuel(shigen[0]), Bullet(shigen[1]), Steel(shigen[2]), Bauxite(shigen[3]) {}

			/*
			* ������\���N���X
			* \param [in] json ����JSON
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
			* ������\���N���X
			* \param [in] shigen ����
			*/
			Shigen(const Shigen& shigen)
				: Fuel(shigen.Fuel), Bullet(shigen.Bullet), Steel(shigen.Steel), Bauxite(shigen.Bauxite) {}

			/*
			* =���Z�q
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