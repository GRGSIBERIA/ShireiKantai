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
				PROPERTY(int, afterBull);
				PROPERTY(int, afterFuel);
				PROPERTY(int, afterlv);
				PROPERTY(int, buildtime);
				PROPERTY(int, bullMax);
				PROPERTY(int, cNum);
				PROPERTY(int, fuelMax);
				PROPERTY(int, id);
				PROPERTY(int, slotNum);
				PROPERTY(int, sortNo);
				
				PROPERTY(String, aftershipid);
				PROPERTY(String, cType);
				PROPERTY(String, leng);
				PROPERTY(String, name);
				PROPERTY(String, sokuh);
				PROPERTY(String, sType);
				PROPERTY(String, yomi);

				PROPERTY(Shigen, broken);
				PROPERTY(Shigen, powUp);

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
					P_INTEGER(afterBull);
					P_INTEGER(afterFuel);
					P_INTEGER(afterlv);
					P_INTEGER(buildtime);
					P_INTEGER(bullMax);
					P_INTEGER(cNum);
					P_INTEGER(fuelMax);
					P_INTEGER(id);
					P_INTEGER(slotNum);
					P_INTEGER(sortNo);

					P_STRING(aftershipid);
					P_STRING(cType);
					P_STRING(leng);
					P_STRING(name);
					P_STRING(sokuh);
					P_STRING(sType);
					P_STRING(yomi);

					P_CLASS(Shigen, broken);
					P_CLASS(Shigen, powUp);
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
				json11::Json ToJson() const
				{
					return json11::Json::object{
						TO_JSON(afterBull),
						TO_JSON(afterFuel),
						TO_JSON(afterlv),
						TO_JSON(buildtime),
						TO_JSON(bullMax),
						TO_JSON(cNum),
						TO_JSON(fuelMax),
						TO_JSON(id),
						TO_JSON(slotNum),
						TO_JSON(sortNo),

						TO_JSON(aftershipid),
						TO_JSON(cType),
						TO_JSON(leng),
						TO_JSON(name),
						TO_JSON(sokuh),
						TO_JSON(sType),
						TO_JSON(yomi),

						TO_JSON(broken.ToJson()),
						TO_JSON(powUp.ToJson()),
						TO_JSON(houg.ToJson()),
						TO_JSON(kaih.ToJson()),
						TO_JSON(luck.ToJson()),
						TO_JSON(raig.ToJson()),
						TO_JSON(saku.ToJson()),
						TO_JSON(souk.ToJson()),
						TO_JSON(taik.ToJson()),
						TO_JSON(tais.ToJson()),
						TO_JSON(tous.ToJson()),
						TO_JSON(tyku.ToJson()),
						TO_JSON(defeq.ToJson()),
						TO_JSON(maxeq.ToJson())
					};
				}
			};
		}
	}
}