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

					P_SHIGEN(broken);
				}
			};
		}
	}
}