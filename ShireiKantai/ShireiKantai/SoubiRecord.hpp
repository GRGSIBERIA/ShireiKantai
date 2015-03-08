#pragma once

#include "RecordBase.hpp"

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
				PROPERTY(int, Baku);
				PROPERTY(int, Houg);
				PROPERTY(int, Houk);
				PROPERTY(int, Houm);
				PROPERTY(int, Id);
				PROPERTY(String, Leng);
				PROPERTY(String, Name);
				PROPERTY(int, Raig);
				PROPERTY(int, Raim);
				PROPERTY(int, Rare);
				PROPERTY(int, Saku);
				PROPERTY(int, SortNo);
				PROPERTY(int, Tais);
				PROPERTY(int, Tyku);
				PROPERTY(int, Type1);
				PROPERTY(int, Type2);
				PROPERTY(int, Type3);

				PROPERTY(Shigen, Broken);

			public:
				SoubiRecord() {}

				SoubiRecord(const json11::Json& json) 
				{
					P_INTEGER(Baku);
					P_INTEGER(Houg);
					P_INTEGER(Houk);
					P_INTEGER(Houm);
					P_INTEGER(Raig);
					P_INTEGER(Raim);
					P_INTEGER(Rare);
					P_INTEGER(Saku);
					P_INTEGER(Tais);
					P_INTEGER(Tyku);
					P_INTEGER(Type1);
					P_INTEGER(Type2);
					P_INTEGER(Type3);
					P_INTEGER(Id);
					P_INTEGER(SortNo);

					P_STRING(Leng);
					P_STRING(Name);

					P_CLASS(Shigen, Broken);
				}
			};
		}
	}
}