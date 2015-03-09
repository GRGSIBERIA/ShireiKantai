﻿#include <Siv3D.hpp>
#include <json11.hpp>

#include "KanDB.hpp"
#include "SoubiDB.hpp"

void Main()
{
	const Font font(30);

	kantai::data::DB::SoubiDB soubi;

	while (System::Update())
	{
		font(L"ようこそ、Siv3D の世界へ！").draw();

		Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
	}
}
