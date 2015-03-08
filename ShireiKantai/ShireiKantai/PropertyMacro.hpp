#pragma once

// プロパティを指定した型で展開する
#define PROPERTY(TYPE, VAR) \
	private: \
		TYPE VAR; \
	public: \
		TYPE __Get##VAR() const { return VAR; } \
		void __Set##VAR(const TYPE& value) { VAR = value; } \
		__declspec(property(get = __Get##VAR, put = __Set##VAR)) TYPE VAR;

// shared_ptr版
#define PROPERTY_S(TYPE, VAR) \
	private: \
		std::shared_ptr<TYPE> VAR; \
	public: \
		TYPE __Get##VAR() const { return *VAR; } \
		void __Set##VAR(const TYPE& value) { *VAR = value; } \
		__declspec(property(get = __Get##VAR, put = __Set##VAR)) TYPE VAR;

#define P_INTEGER(VAR) \
	VAR = json[#VAR].int_value();

#define P_STRING(VAR) \
	VAR = Widen(json[#VAR].string_value());

#define P_SHIGEN(VAR) \
	VAR = Shigen(json[#VAR]);
