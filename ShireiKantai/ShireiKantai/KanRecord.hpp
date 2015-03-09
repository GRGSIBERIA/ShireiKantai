#pragma once

#include "RecordBase.hpp"
#include "Shigen.hpp"
#include "MinMax.hpp"
#include "Defeq.hpp"
#include "MaxEq.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			/*
			* äÕñ∫ÉåÉRÅ[Éh
			*/
			class KanRecord : RecordBase
			{
				PROPERTY(int, afterbull);
				PROPERTY(int, afterfuel);
				PROPERTY(int, afterlv);
				PROPERTY(int, buildtime);
				PROPERTY(int, bull_max);
				PROPERTY(int, cnum);
				PROPERTY(int, fuel_max);
				PROPERTY(int, id);
				PROPERTY(int, slot_num);
				PROPERTY(int, sortNo);
				
				PROPERTY(String, aftershipid);
				PROPERTY(String, ctype);
				PROPERTY(String, leng);
				PROPERTY(String, name);
				PROPERTY(String, sokuh);
				PROPERTY(String, stype);
				PROPERTY(String, yomi);

				PROPERTY(Shigen, broken);
				PROPERTY(Shigen, powup);

				PROPERTY(MinMax, houg);
				PROPERTY(MinMax, kaih);
				PROPERTY(MinMax, luck);
				PROPERTY(MinMax, raig);
				PROPERTY(MinMax, saku);
				PROPERTY(MinMax, souk);
				PROPERTY(MinMax, taik);
				PROPERTY(MinMax, tais);
				PROPERTY(MinMax, tous);
				PROPERTY(MinMax, tyku);

				PROPERTY(DefEq, defeq);
				PROPERTY(MaxEq, maxeq);

			public:
				KanRecord() {}

				KanRecord(const json11::Json& json) 
				{
					P_INTEGER(afterbull);
					P_INTEGER(afterfuel);
					P_INTEGER(afterlv);
					P_INTEGER(buildtime);
					P_INTEGER(bull_max);
					P_INTEGER(cnum);
					P_INTEGER(fuel_max);
					P_INTEGER(id);
					P_INTEGER(slot_num);
					P_INTEGER(sortNo);

					P_STRING(aftershipid);
					P_STRING(ctype);
					P_STRING(leng);
					P_STRING(name);
					P_STRING(sokuh);
					P_STRING(stype);
					P_STRING(yomi);

					P_CLASS(Shigen, broken);
					P_CLASS(Shigen, powup);
					P_CLASS(MinMax, houg);
					P_CLASS(MinMax, kaih);
					P_CLASS(MinMax, luck);
					P_CLASS(MinMax, raig);
					P_CLASS(MinMax, saku);
					P_CLASS(MinMax, souk);
					P_CLASS(MinMax, taik);
					P_CLASS(MinMax, tais);
					P_CLASS(MinMax, tous);
					P_CLASS(MinMax, tyku);
					P_CLASS(DefEq, defeq);
					P_CLASS(MaxEq, maxeq);
				}

				/*
				* JSONÇ…ïœä∑
				*/
				json11::Json ToJson()
				{
					return json11::Json::object{
						TO_JSON(afterbull),
						TO_JSON(afterfuel),
						TO_JSON(afterlv),
						TO_JSON(buildtime),
						TO_JSON(bull_max),
						TO_JSON(cnum),
						TO_JSON(fuel_max),
						TO_JSON(id),
						TO_JSON(slot_num),
						TO_JSON(sortNo),

						TO_JSON(aftershipid),
						TO_JSON(ctype),
						TO_JSON(leng),
						TO_JSON(name),
						TO_JSON(sokuh),
						TO_JSON(stype),
						TO_JSON(yomi),

						TO_JSONC(broken),
						TO_JSONC(powup),
						TO_JSONC(houg),
						TO_JSONC(kaih),
						TO_JSONC(luck),
						TO_JSONC(raig),
						TO_JSONC(saku),
						TO_JSONC(souk),
						TO_JSONC(taik),
						TO_JSONC(tais),
						TO_JSONC(tous),
						TO_JSONC(tyku),
						TO_JSONC(defeq),
						TO_JSONC(maxeq)
					};
				}
			};
		}
	}
}