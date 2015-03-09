#include <Siv3D.hpp>
#include <json11.hpp>

#include "Shigen.hpp"

void Main()
{
	const Font font(30);

	kantai::data::DB::Shigen record;

	auto json = json11::Json::object{ { "test", record.ToJson() } };
	auto test = json["test"].array_items();

	while (System::Update())
	{
		font(L"ようこそ、Siv3D の世界へ！").draw();

		Circle(Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
	}
}
