#pragma once

#include <array>
#include <memory>
#include <json11.hpp>

#include "RecordBase.hpp"
#include "PropertyMacro.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{

			/*
			* Ήπ\·NX
			*/
			class Shigen : public RecordBase
			{
				PROPERTY(int, Fuel);
				PROPERTY(int, Bullet);
				PROPERTY(int, Steel);
				PROPERTY(int, Bauxite);

			public:
				Shigen() {}

				/*
				* Ήπ\·NX
				*/
				Shigen(const int fuel, const int bullet, const int steel, const int bauxite)
					: Fuel(fuel), Bullet(bullet), Steel(steel), Bauxite(bauxite) {}

				/*
				* Ήπ\·NX
				* \param [in] shigen RΏ/eς/|ή/{[L
				*/
				Shigen(const std::array<int, 4>& shigen)
					: Fuel(shigen[0]), Bullet(shigen[1]), Steel(shigen[2]), Bauxite(shigen[3]) {}

				/*
				* Ήπ\·NX
				* \param [in] json ΉJSON
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
				* Ήπ\·NX
				* \param [in] shigen Ή
				*/
				Shigen(const Shigen& shigen)
					: Fuel(shigen.Fuel), Bullet(shigen.Bullet), Steel(shigen.Steel), Bauxite(shigen.Bauxite) {}

				/*
				* =Zq
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
}