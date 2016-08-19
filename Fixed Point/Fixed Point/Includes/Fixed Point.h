#pragma once

/*
A fixed point value.*/
class fixed {
public:
	fixed();
	fixed(__int32 i);
	fixed(const fixed& f);

	fixed fractionPart();
	fixed integerPart();

	fixed operator~();
	fixed operator-();
	fixed& operator=(__int32 i);
	fixed& operator=(const fixed& f);
	bool operator==(__int32 i);
	bool operator==(const fixed& f);
	bool operator!=(__int32 i);
	bool operator!=(const fixed& f);
	bool operator<=(__int32 i);
	bool operator<=(const fixed& f);
	bool operator<(__int32 i);
	bool operator<(const fixed& f);
	bool operator>=(__int32 i);
	bool operator>=(const fixed& f);
	bool operator>(__int32 i);
	bool operator>(const fixed& f);
	fixed& operator+=(__int32 i);
	fixed& operator+=(const fixed& f);
	fixed operator+(__int32 i);
	fixed operator+(const fixed& f);
	fixed& operator-=(__int32 i);
	fixed& operator-=(const fixed& f);
	fixed operator-(__int32 i);
	fixed operator-(const fixed& f);
	fixed& operator*=(__int32 i);
	fixed& operator*=(const fixed& f);
	fixed operator*(__int32 i);
	fixed operator*(const fixed& f);
	fixed& operator/=(__int32 i);
	fixed& operator/=(const fixed& f);
	fixed operator/(__int32 i);
	fixed operator/(const fixed& f);
	fixed& operator|=(__int32 i);
	fixed operator|(__int32 i);
	fixed& operator&=(__int32 i);
	fixed operator&(__int32 i);
	fixed& operator^=(__int32 i);
	fixed operator^(__int32 i);
	fixed& operator>>=(__int32 i);
	fixed operator >> (__int32 i);
	fixed& operator<<=(__int32 i);
	fixed operator <<(__int32 i);

	__int32& operator()();

	explicit operator __int32();

private:
	__int32 value;

};

namespace Fixed_Point {

	/*
	Returns absolute value of 'f'.*/
	fixed __fastcall abs(const fixed& f);

	/*
	Returns the square root of 'f'.*/
	fixed __fastcall sqrt(const fixed& f);

	/*
	(INCOMPLETE) Returns 'f' to the power of 'p'.*/
	fixed __fastcall pow(const fixed& f, const fixed&p);

}
