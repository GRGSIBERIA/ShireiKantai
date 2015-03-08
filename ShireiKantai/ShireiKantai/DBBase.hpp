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
			�f�[�^�x�[�X�̊��N���X
			*/
			class DBBase
			{
				json11::Json json;	//!< ���ƂȂ�JSON���i�[����N���X

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