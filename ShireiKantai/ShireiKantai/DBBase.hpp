#pragma once

#include <Siv3D.hpp>
#include <json11.hpp>

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			/*
			データベースの基底クラス
			*/
			class DBBase
			{
				json11::Json json;	//!< 元となるJSONを格納するクラス

			public:
				DBBase(const FilePath& path)
				{
					TextReader reader(path);
					const auto str = reader.readContents();
					json = json11::Json(str.narrow());
				}
			};
		}
	}
}