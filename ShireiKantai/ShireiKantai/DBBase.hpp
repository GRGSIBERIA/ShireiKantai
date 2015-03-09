#pragma once

#include <Siv3D.hpp>
#include <json11.hpp>

#include "RecordBase.hpp"

namespace kantai
{
	namespace data
	{
		namespace DB
		{
			/*
			データベースの基底クラス
			*/
			template <class T>
			class DBBase
			{
			protected:
				std::shared_ptr<json11::Json> json;	//!< 元となるJSONを格納するクラス

				std::vector<T> records;	//!< レコード

				/*
				* JSONを読み込んでレコードを初期化する
				*/
				void InitializeRecords(const json11::Json& json)
				{
					const auto items = json["objects"].array_items();
					for (const auto& item : items)
					{
						records.emplace_back(item);
					}
				}

			public:
				/*
				* パスを読み込んで初期化する
				*/
				DBBase(const FilePath& path)
				{
					TextReader reader(path, TextEncoding::UTF8);
					const auto str = reader.readContents();
					const std::string puyo = str.narrow();
					std::string err;
					const auto hoge = json11::Json::parse(puyo, err);
					json = std::shared_ptr<json11::Json>(new json11::Json(str.narrow()));

					InitializeRecords(*json);
				}
			};
		}
	}
}