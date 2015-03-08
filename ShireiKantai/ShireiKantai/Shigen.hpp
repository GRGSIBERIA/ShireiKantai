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
			* Ήπ\·NX
			*/
			class Shigen : public RecordBase
			{
				PROPERTY(int, fuel);
				PROPERTY(int, bullet);
				PROPERTY(int, steel);
				PROPERTY(int, bauxite);

			public:
				Shigen() {}

				/*
				* Ήπ\·NX
				*/
				Shigen(const int fuel, const int bullet, const int steel, const int bauxite)
					: fuel(fuel), bullet(bullet), steel(steel), bauxite(bauxite) {}

				/*
				* Ήπ\·NX
				* \param [in] shigen RΏ/eς/|ή/{[L
				*/
				Shigen(const std::array<int, 4>& shigen)
					: fuel(shigen[0]), bullet(shigen[1]), steel(shigen[2]), bauxite(shigen[3]) {}

				/*
				* Ήπ\·NX
				* \param [in] json ΉJSON
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
				* Ήπ\·NX
				* \param [in] shigen Ή
				*/
				Shigen(const Shigen& shigen)
					: fuel(shigen.fuel), bullet(shigen.bullet), steel(shigen.steel), bauxite(shigen.bauxite) {}

				/*
				* =Zq
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
				* JSONΙΟ·
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