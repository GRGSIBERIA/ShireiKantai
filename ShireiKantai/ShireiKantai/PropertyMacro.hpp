#pragma once

// プロパティを指定した型で展開する
#define PROPERTY(TYPE, VAR) \
	private: \
		TYPE VAR; \
	public: \
		TYPE __Get_##VAR() const { return VAR; } \
		void __Set_##VAR(const TYPE& value) { VAR = value; } \
		__declspec(property(get = __Get_##VAR, put = __Set_##VAR)) TYPE VAR;

// shared_ptr版
#define PROPERTY_S(TYPE, VAR) \
	private: \
		std::shared_ptr<TYPE> VAR; \
	public: \
		TYPE __Get_##VAR() const { return *VAR; } \
		void __Set_##VAR(const TYPE& value) { *VAR = value; } \
		__declspec(property(get = __Get_##VAR, put = __Set_##VAR)) TYPE VAR;

#define P_INTEGER(VAR) \
	VAR = json[#VAR].int_value();

#define P_STRING(VAR) \
	VAR = Widen(json[#VAR].string_value());

#define P_CLASS(TYPE, VAR) \
	VAR = TYPE(json[#VAR]);