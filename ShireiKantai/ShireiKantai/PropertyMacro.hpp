#pragma once

#define PROPERTY(TYPE, VAR) \
	private: \
		TYPE VAR; \
	public: \
		TYPE __Get##VAR() const { return VAR; } \
		void __Set##VAR(const TYPE& value) { VAR = value; } \
		__declspec(property(get = __Get##VAR, put = __Set##VAR)) TYPE VAR;

#define PROPERTY_S(TYPE, VAR) \
	private: \
		std::shared_ptr<TYPE> VAR; \
	public: \
		TYPE __Get##VAR() const { return *VAR; } \
		void __Set##VAR(const TYPE& value) { *VAR = value; } \
		__declspec(property(get = __Get##VAR, put = __Set##VAR)) TYPE VAR;