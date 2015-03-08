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
			class KanRecord : RecordBase
			{
				PROPERTY(int, Afterbull);
				PROPERTY(int, Afterfuel);
				PROPERTY(int, Afterlv);
				PROPERTY(int, Buildtime);
				PROPERTY(int, BullMax);
				PROPERTY(int, CNum);
				PROPERTY(int, FuelMax);
				PROPERTY(int, Id);
				PROPERTY(int, SlotNum);
				PROPERTY(int, SortNo);
				
				PROPERTY(String, Aftershipid);
				PROPERTY(String, CType);
				PROPERTY(String, Leng);
				PROPERTY(String, Name);
				PROPERTY(String, Sokuh);
				PROPERTY(String, SType);
				PROPERTY(String, Yomi);

				PROPERTY(Shigen, Broken);
				PROPERTY(Shigen, PowUp);

				PROPERTY(MinMax, Houg);
				PROPERTY(MinMax, Kaih);
				PROPERTY(MinMax, Luck);
				PROPERTY(MinMax, Raig);
				PROPERTY(MinMax, Saku);
				PROPERTY(MinMax, Souk);
				PROPERTY(MinMax, Taik);
				PROPERTY(MinMax, Tais);
				PROPERTY(MinMax, Tous);
				PROPERTY(MinMax, Tyku);

				PROPERTY(DefEq, Defeq);
				PROPERTY(MaxEq, Maxeq);

			public:
				KanRecord(const json11::Json& json) 
				{
					P_INTEGER(Afterbull);
					P_INTEGER(Afterfuel);
					P_INTEGER(Afterlv);
					P_INTEGER(Buildtime);
					P_INTEGER(BullMax);
					P_INTEGER(CNum);
					P_INTEGER(FuelMax);
					P_INTEGER(Id);
					P_INTEGER(SlotNum);
					P_INTEGER(SortNo);

					P_STRING(Aftershipid);
					P_STRING(CType);
					P_STRING(Leng);
					P_STRING(Name);
					P_STRING(Sokuh);
					P_STRING(SType);
					P_STRING(Yomi);

					P_CLASS(Shigen, Broken);
					P_CLASS(Shigen, PowUp);
					P_CLASS(MinMax, Houg);
					P_CLASS(MinMax, Kaih);
					P_CLASS(MinMax, Luck);
					P_CLASS(MinMax, Raig);
					P_CLASS(MinMax, Saku);
					P_CLASS(MinMax, Souk);
					P_CLASS(MinMax, Taik);
					P_CLASS(MinMax, Tais);
					P_CLASS(MinMax, Tous);
					P_CLASS(MinMax, Tyku);
					P_CLASS(DefEq, Defeq);
					P_CLASS(MaxEq, Maxeq);
				}
			};
		}
	}
}