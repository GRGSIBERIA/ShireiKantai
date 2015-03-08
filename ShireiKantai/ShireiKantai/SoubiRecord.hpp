#pragma once

#include "RecordBase.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			class SoubiRecord : public RecordBase
			{
				int baku;
				std::shared_ptr<Shigen> broken;
				int houg;
				int houk;
				int houm;
				int id;
				String leng;
				String name;
				int raig;
				int raim;
				int rare;
				int saku;
				int sortno;
				int tais;
				int tyku;
				int type1;
				int type2;
				int type3;

			public:
				SoubiRecord(const json11::Json& json) 
				{
					baku = json["baku"].int_value();
					houg = json["houg"].int_value();
					houk = json["houk"].int_value();
					houm = json["houm"].int_value();
					raig = json["raig"].int_value();
					raim = json["raim"].int_value();
					rare = json["rare"].int_value();
					saku = json["saku"].int_value();
					tais = json["tais"].int_value();
					tyku = json["tyku"].int_value();
					type1 = json["type1"].int_value();
					type2 = json["type2"].int_value();
					type3 = json["type3"].int_value();

					leng = Widen(json["leng"].string_value());
					name = Widen(json["name"].string_value());

					id = json["id"].int_value();
					sortno = json["sortno"].int_value();
				}
			};
		}
	}
}