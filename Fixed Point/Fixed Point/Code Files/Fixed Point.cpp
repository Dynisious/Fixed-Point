#include "..\Includes\Fixed Point.h"

#define FIX_1 0x00010000
#define SHIFT 16
#define SHIFT_SIGN_1 31
#define FRACTIONAL_PART 0x0000ffff
#define INTEGER_PART 0xffff00000
#define SIGN 0x80000000

fixed::fixed() {}

fixed::fixed(__int32 i) {
	_asm {
		mov eax, i;
		sal eax, SHIFT;
		mov[ecx], eax;
	}
}

fixed::fixed(const fixed & f) {
	_asm {
		mov eax, f;
		mov eax, [eax];
		mov[ecx], eax;
	}
}

fixed fixed::fractionPart() {
	_asm {
		mov ebx, [ecx];
		cmp ebx, 0;
		jg positive;
		or ebx, INTEGER_PART;
		jmp end;
positive:
		and ebx, FRACTIONAL_PART;
end:
		mov eax, [ebp + 8];
		mov[eax], ebx;
	}
}

fixed fixed::integerPart() {
	_asm {
		mov ebx, [ecx];
		cmp ebx, 0;
		neg ebx;
		and ebx, INTEGER_PART;
		jg end;
		neg ebx;
end:
		mov eax, [ebp + 8];
		mov[eax], ebx;
	}
}

fixed fixed::operator~() {
	_asm {
		mov ebx, [ecx];
		xor ebx, -1;
		mov eax, [ebp + 8];
		mov[eax], ebx;
	}
}

fixed fixed::operator-() {
	_asm {
		mov ebx, [ecx];
		neg ebx;
		mov eax, [ebp + 8];
		mov[eax], ebx;
	}
}

fixed & fixed::operator=(__int32 i) {
	_asm {
		mov eax, i;
		sal eax, SHIFT;
		mov[ecx], eax;
		mov eax, this;
	}
}

fixed & fixed::operator=(const fixed & f) {
	_asm {
		mov eax, f;
		mov eax, [eax];
		mov[ecx], eax;
		mov eax, this;
	}
}

bool fixed::operator==(__int32 i) {
	_asm {
		mov eax, i;
		sal eax, SHIFT;
		xor eax, [ecx];
		xor eax, -1;
	}
}

bool fixed::operator==(const fixed & f) {
	_asm {
		mov eax, f;
		mov eax, [eax];
		xor eax, [ecx];
		xor eax, -1;
	}
}

bool fixed::operator!=(__int32 i) {
	_asm {
		mov eax, i;
		sal eax, SHIFT;
		xor eax, [ecx];
	}
}

bool fixed::operator!=(const fixed & f) {
	_asm {
		mov eax, f;
		mov eax, [eax];
		xor eax, [ecx];
	}
}

bool fixed::operator<=(__int32 i) {
	_asm {
		mov eax, i;
		sal eax, SHIFT;
		sub eax, [ecx];
		and eax, SIGN;
		xor eax, SIGN;
		shr eax, SHIFT_SIGN_1;
	}
}

bool fixed::operator<=(const fixed & f) {
	_asm {
		mov eax, f;
		mov eax, [eax];
		sub eax, [ecx];
		and eax, SIGN;
		xor eax, SIGN;
		shr eax, SHIFT_SIGN_1;
	}
}

bool fixed::operator<(__int32 i) {
	_asm {
		mov eax, [ecx];
		mov ebx, i;
		sal ebx, SHIFT;
		sub eax, ebx;
		and eax, SIGN;
		shr eax, SHIFT_SIGN_1;
	}
}

bool fixed::operator<(const fixed& f) {
	{
		_asm {
			mov eax, [ecx];
			mov ebx, f;
			mov ebx, [ebx];
			sub eax, ebx;
			and eax, SIGN;
			shr eax, SHIFT_SIGN_1;
		}
	}
}

bool fixed::operator>=(__int32 i) {
	_asm {
		mov eax, [ecx];
		mov ebx, i;
		sal ebx, SHIFT;
		sub eax, ebx;
		and eax, SIGN;
		xor eax, SIGN;
		shr eax, SHIFT_SIGN_1;
	}
}

bool fixed::operator>=(const fixed& f) {
	_asm {
		mov eax, [ecx];
		mov ebx, f;
		mov ebx, [ebx];
		sub eax, ebx;
		and eax, SIGN;
		xor eax, SIGN;
		shr eax, SHIFT_SIGN_1;
	}
}

bool fixed::operator>(__int32 i) {
	_asm {
		mov ebx, [ecx];
		mov eax, i;
		sal eax, SHIFT;
		sub eax, ebx;
		and eax, SIGN;
		shr eax, SHIFT_SIGN_1;
	}
}

bool fixed::operator>(const fixed& f) {
	_asm {
		mov ebx, [ecx];
		mov eax, f;
		mov eax, [eax];
		sub eax, ebx;
		and eax, SIGN;
		shr eax, SHIFT_SIGN_1;
	}
}

fixed & fixed::operator+=(__int32 i) {
	_asm {
		mov eax, i;
		sal eax, SHIFT;
		add[ecx], eax;
		mov eax, this;
	}
}

fixed & fixed::operator+=(const fixed & f) {
	_asm {
		mov eax, f;
		mov eax, [eax];
		add[ecx], eax;
		mov eax, this;
	}
}

fixed fixed::operator+(__int32 i) {
	_asm {
		mov ebx, i;
		sal ebx, SHIFT;
		add ebx, [ecx];
		mov eax, [ebp + 8];
		mov[eax], ebx;
	}
}

fixed fixed::operator+(const fixed & f) {
	_asm {
		mov ebx, f;
		mov ebx, [ebx];
		add ebx, [ecx];
		mov eax, [ebp + 8];
		mov[eax], ebx;
	}
}

fixed & fixed::operator-=(__int32 i) {
	_asm {
		mov eax, i;
		sal eax, SHIFT;
		sub[ecx], eax;
		mov eax, this;
	}
}

fixed & fixed::operator-=(const fixed & f) {
	_asm {
		mov eax, f;
		mov eax, [eax];
		sub[ecx], eax;
		mov eax, this;
	}
}

fixed fixed::operator-(__int32 i) {
	_asm {
		mov ebx, i;
		sal ebx, SHIFT;
		sub ebx, [ecx];
		mov eax, [ebp + 8];
		mov[eax], ebx;
	}
}

fixed fixed::operator-(const fixed & f) {
	_asm {
		mov ebx, f;
		mov ebx, [ebx];
		sub ebx, [ecx];
		mov eax, [ebp + 8];
		mov[eax], ebx;
	}
}

fixed & fixed::operator*=(__int32 i) {
	_asm {
		mov eax, i;
		imul[ecx];
		mov[ecx], eax;
		mov eax, this;
	}
}

fixed & fixed::operator*=(const fixed & f) {
	_asm {
		mov eax, f;
		mov eax, [eax];
		mov ebx, ecx;
		imul ebx;
		shrd eax, edx, SHIFT;
		mov[ecx], eax;
		mov eax, this;
	}
}

fixed fixed::operator*(__int32 i) {
	_asm {
		mov eax, i;
		imul[ecx];
		mov[ebp + 8], eax;
		mov eax, ebp;
		add eax, 8;
	}
}

fixed fixed::operator*(const fixed & f) {
	_asm {
		mov eax, f;
		mov eax, [eax];
		mov ebx, [ecx];
		imul ebx;
		shrd eax, edx, SHIFT;
		mov ebx, [ebp + 8];
		mov[ebx], eax;
		mov eax, ebx;
	}
}

fixed & fixed::operator/=(__int32 i) {
	_asm {
		mov eax, [ecx];
		xor edx, edx;
		idiv i;
		mov[ecx], eax;
		mov eax, this;
	}
}

fixed & fixed::operator/=(const fixed & f) {
	_asm {
		mov eax, [ecx];
		mov edx, eax;
		sar edx, SHIFT;
		shl eax, SHIFT;
		xor edx, edx;
		mov ebx, f;
		mov ebx, [ebx];
		idiv ebx;
		mov[ecx], eax;
		mov eax, this;
	}
}

fixed fixed::operator/(__int32 i) {
	_asm {
		mov eax, [ecx];
		xor edx, edx;
		idiv i;
		mov ebx, [ebp + 8];
		mov[ebx], eax;
		mov eax, ebx;
	}
}

fixed fixed::operator/(const fixed & f) {
	_asm {
		mov eax, [ecx];
		mov edx, eax;
		sar edx, SHIFT;
		shl eax, SHIFT;
		mov ebx, f;
		mov ebx, [ebx];
		idiv ebx;
		mov ebx, [ebp + 8];
		mov[ebx], eax;
		mov eax, ebx;
	}
}

fixed & fixed::operator|=(__int32 i) {
	_asm {
		mov eax, [ecx];
		or eax, i;
		mov[ecx], eax;
		mov eax, this;
	}
}

fixed fixed::operator|(__int32 i) {
	_asm {
		mov ebx, [ecx];
		or ebx, i;
		mov eax, [ebp + 8];
		mov[eax], ebx;
	}
}

fixed & fixed::operator&=(__int32 i) {
	_asm {
		mov eax, [ecx];
		and eax, i;
		mov[ecx], eax;
		mov eax, this;
	}
}

fixed fixed::operator&(__int32 i) {
	_asm {
		mov ebx, [ecx];
		and ebx, i;
		mov eax, [ebp + 8];
		mov[eax], ebx;
	}
}

fixed & fixed::operator^=(__int32 i) {
	_asm {
		mov eax, [ecx];
		xor eax, i;
		mov[ecx], eax;
		mov eax, this;
	}
}

fixed fixed::operator^(__int32 i) {
	_asm {
		mov ebx, [ecx];
		xor ebx, i;
		mov eax, [ebp + 8];
		mov[eax], ebx;
	}
}

fixed & fixed::operator>>=(__int32 i) {
	_asm {
		mov eax, [ecx];
		mov ebx, ecx;
		mov ecx, i;
		shr eax, cl;
		mov[ebx], eax;
		mov eax, ebx;
	}
}

fixed fixed::operator >> (__int32 i) {
	_asm {
		mov ebx, [ecx];
		mov ecx, i;
		shr ebx, cl;
		mov eax, [ebp + 8];
		mov[eax], ebx;
	}
}

fixed & fixed::operator<<=(__int32 i) {
	_asm {
		mov eax, [ecx];
		mov ebx, ecx;
		mov ecx, i;
		shl eax, cl;
		mov[ebx], eax;
		mov eax, ebx;
	}
}

fixed fixed::operator << (__int32 i) {
	_asm {
		mov ebx, [ecx];
		mov ecx, i;
		shl ebx, cl;
		mov eax, [ebp + 8];
		mov[eax], ebx;
	}
}

__int32& fixed::operator()() {
	_asm mov eax, ecx;
}

fixed::operator __int32() {
	_asm {
		mov eax, [ecx];
		sar eax, SHIFT;
	}
}

fixed __fastcall Fixed_Point::abs(const fixed & f) {
	_asm {
		mov eax, [edx];
		cmp eax, 0;
		jg end;
		neg eax;
end:
		mov[ebp + 8], eax;
		mov eax, ebp;
		add eax, 8;
	}
}

fixed __fastcall Fixed_Point::sqrt(const fixed & f) {
	_asm {
		mov[esp - 4], ecx;
		mov edx, [edx];
		mov[esp], edx;
		mov ecx, FIX_1;
difference:
		mov eax, [esp];
		mov edx, eax;
		shl eax, SHIFT;
		shr edx, SHIFT;
		idiv ecx;
		mov edx, [esp];
		sub edx, eax;
		cmp edx, 0;
		jg check;
		neg edx;
check:
		cmp edx, 0x00000008;
		jl end;

		//New guess.
		add ecx, eax;
		shr ecx, 1;
		jmp difference;
end:
		mov eax, [esp - 4];
		mov[eax], ecx;
	}
}

//fixed __fastcall Fixed_Point::pow(const fixed & f, const fixed & p) {
//	fixed res(f);
//	for (unsigned __int32 i((*( fixed* ) &p).integerPart()()); i > 0; i--)
//		res *= res;
//	fixed _root(f);
//	fixed roots((*( fixed* ) &p).fractionPart());
//	__int32 i(0x00001000);
//	while (( __int32 ) roots) {
//		_root = sqrt(_root);
//		if (( __int32 ) roots & i) {
//			roots ^= i;
//			res += _root;
//		}
//	}
//	return ((*( __int32* ) &p) > 0) ? res : fixed(1) / res;
//}

fixed& (__thiscall fixed::*mulEq)(const fixed&) = &fixed::operator*=;
fixed& (__thiscall fixed::*divEq)(const fixed&) = &fixed::operator/=;

fixed __fastcall Fixed_Point::pow(const fixed & f, const fixed & p) {
	_asm {
		//Memory
		add esp, -16;
		mov[esp + 4], ecx; //Return address 'ret'.
		mov[esp + 8], edx; //'f'.
		//+12: 'posPow' //true if 'p' is positive.
		//+16: 'fracP' //The fractional portion of 'p'.
		//Memory
		mov[ecx], FIX_1; //'f' value into 'ret'.
		mov eax, p; //'p' into eax.
		mov eax, [eax]; //'p' value into eax.
		mov[esp + 12], eax; //'p' value into 'posPow'.

		//abs 'p' value; 'posPow' calc.
		cmp eax, 0;
		jg greater;
		neg eax;
		xor ebx, ebx;
		mov[esp + 12], ebx; //'posPow' = false.
greater:
		mov ebx, -1;
		mov[esp + 12], ebx; //'posPow' = true.
		//abs 'p' value; 'posPow' calc.

		//'fracP' and integer of 'p' calc.
		mov ecx, eax;
		and eax, FRACTIONAL_PART;
		mov[esp + 16], eax; //save 'fracP'.
		and ecx, INTEGER_PART;
		sar ecx, SHIFT; //integer portion of 'p'.
		//'fracP' and integer of 'p'  calc.

		//porform power part of operation.
		cmp ecx, 0;
		je endPow;
		add esp, -4; //Preper saved & param memory.
power:
		mov[esp + 4], ecx; //save loop counter. 
		mov ecx, [esp + 12]; //Get 'f'.
		push ecx; //Save 'f' param.
		mov ecx, [esp + 12]; //Get 'ret' as 'this' param.
		call mulEq; //multiply 'ret' by 'f'.
		mov ecx, [esp + 4]; //get loop counter.
		loop power;
		add esp, 4; //Dealoc memory.
endPow:
		//porform power part of operation.

		//porform frac power part of operation.
		mov ecx, [esp + 16]; //Get 'fracP'.
		cmp ecx, 0;
		je endFrac;
frac:

endFrac:
		//porform frac power part of operation.

		mov eax, [esp + 4];
		add esp, 16;
	}
}
