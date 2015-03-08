#pragma once

#include <array>
#include <memory>
#include <json11.hpp>

namespace kantai
{
	namespace data
	{
		/*
		* ������\���N���X
		*/
		class Shigen
		{
			int fuel;
			int bullet;
			int steel;
			int bauxite;

			const int pFuel() { return fuel; }
			const int pBullet() { return bullet; }
			const int pSteel() { return steel; }
			const int pBauxite() { return bauxite; }

		public:
			/*
			* ������\���N���X
			*/
			Shigen(const int fuel, const int bullet, const int steel, const int bauxite)
				: fuel(fuel), bullet(bullet), steel(steel), bauxite(bauxite) {}

			/*
			* ������\���N���X
			* \param [in] shigen �R��/�e��/�|��/�{�[�L
			*/
			Shigen(const std::array<int, 4>& shigen)
				: fuel(shigen[0]), bullet(shigen[1]), steel(shigen[2]), bauxite(shigen[3]) {}

			/*
			* ������\���N���X
			* \param [in] json ����JSON
			*/
			Shigen(const json11::Json& json)
			{
				const auto items = json.array_items();
				fuel = items[0].int_value();
				bullet = items[1].int_value();
				steel = items[2].int_value();
				bauxite = items[3].int_value();
			}

			__declspec(property(get = pFuel)) const int Fuel;		//!< �R��
			__declspec(property(get = pBullet)) const int Bullet;	//!< �e��
			__declspec(property(get = pSteel)) const int Steel;		//!< �|��
			__declspec(property(get = pBauxite)) const int Bauxite;	//!< �{�[�L
		};
	}
}