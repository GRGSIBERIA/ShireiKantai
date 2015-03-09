#pragma once

#include "RecordBase.hpp"

#include "Shigen.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			/*
			* ëïîıÉåÉRÅ[Éh
			*/
			class SoubiRecord : public RecordBase
			{
				PROPERTY(int, baku);
				PROPERTY(int, houg);
				PROPERTY(int, houk);
				PROPERTY(int, houm);
				PROPERTY(int, id);
				PROPERTY(String, leng);
				PROPERTY(String, name);
				PROPERTY(int, raig);
				PROPERTY(int, raim);
				PROPERTY(int, rare);
				PROPERTY(int, saku);
				PROPERTY(int, sortno);
				PROPERTY(int, tais);
				PROPERTY(int, tyku);
				PROPERTY(int, type1);
				PROPERTY(int, type2);
				PROPERTY(int, type3);

				PROPERTY(Shigen, broken);

			public:
				SoubiRecord() 
					: 
					baku(), houg(), houk(), houm(), id(), leng(), 
					name(), raig(), raim(), rare(), saku(), sortno(), 
					tais(), tyku(), type1(), type2(), type3() {}

				SoubiRecord(const json11::Json& json) 
				{
					P_INTEGER(baku);
					P_INTEGER(houg);
					P_INTEGER(houk);
					P_INTEGER(houm);
					P_INTEGER(raig);
					P_INTEGER(raim);
					P_INTEGER(rare);
					P_INTEGER(saku);
					P_INTEGER(tais);
					P_INTEGER(tyku);
					P_INTEGER(type1);
					P_INTEGER(type2);
					P_INTEGER(type3);
					P_INTEGER(id);
					P_INTEGER(sortno);

					P_STRING(leng);
					P_STRING(name);

					P_CLASS(Shigen, broken);
				}

				/*
				* JSONÇ…ïœä∑
				*/
				json11::Json ToJson()
				{
					return json11::Json::object{
						TO_JSON(baku),
						TO_JSON(houg),
						TO_JSON(houk),
						TO_JSON(houm),
						TO_JSON(raig),
						TO_JSON(raim),
						TO_JSON(rare),
						TO_JSON(saku),
						TO_JSON(tais),
						TO_JSON(tyku),
						TO_JSON(type1),
						TO_JSON(type2),
						TO_JSON(type3),
						TO_JSON(id),
						TO_JSON(sortno),

						TO_JSON(leng),
						TO_JSON(name),

						TO_JSONC(broken)
					};
				}
			};
		}
	}
}