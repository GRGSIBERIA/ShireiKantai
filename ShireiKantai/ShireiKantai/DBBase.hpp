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
			�f�[�^�x�[�X�̊��N���X
			*/
			template <class T>
			class DBBase
			{
			protected:
				std::shared_ptr<json11::Json> json;	//!< ���ƂȂ�JSON���i�[����N���X

				std::vector<T> records;	//!< ���R�[�h

				/*
				* JSON��ǂݍ���Ń��R�[�h������������
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
				* �p�X��ǂݍ���ŏ���������
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