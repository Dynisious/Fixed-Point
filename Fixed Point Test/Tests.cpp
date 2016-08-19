#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Fixed Point\Fixed Point\Includes\Fixed Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FixedPointTest {
	TEST_CLASS(FixedPoint_tests) {
public:

	TEST_METHOD(Equivilance_tests) {
		fixed a, b;
		a() = b() = 0x00010000;

		Assert::IsTrue(a == b, L"\"fixed == fixed\" failed.");
		Assert::IsFalse(a != b, L"\"fixed != fixed\" failed.");
		Assert::IsTrue(a == 1, L"\"fixed == int\" failed.");
		Assert::IsFalse(a != 1, L"\"fixed != int\" failed.");
		a = 4;
		Assert::IsTrue(a >= b, L"\"fixed >= fixed\" failed.");
		Assert::IsTrue(a > b, L"\"fixed > fixed\" failed.");
		Assert::IsTrue(a > 1, L"\"fixed > fixed\" failed.");
		Assert::IsTrue(a >= a, L"\"fixed >= fixed\" failed.");
		Assert::IsTrue(a >= 1, L"\"fixed >= int\" failed.");
		Assert::IsTrue(a >= 4, L"\"fixed >= int\" failed.");
		Assert::IsFalse(b >= a, L"\"fixed >= fixed\" failed.");
		Assert::IsFalse(a > a, L"\"fixed > fixed\" failed.");
		Assert::IsTrue(b <= a, L"\"fixed <= fixed\" failed.");
		Assert::IsTrue(b < a, L"\"fixed < fixed\" failed.");
		Assert::IsTrue(b < 4, L"\"fixed < fixed\" failed.");
		Assert::IsTrue(b <= b, L"\"fixed <= fixed\" failed.");
		Assert::IsTrue(b <= 1, L"\"fixed <= int\" failed.");
		Assert::IsTrue(b <= 4, L"\"fixed <= int\" failed.");
		Assert::IsFalse(a <= b, L"\"fixed <= fixed\" failed.");
		Assert::IsFalse(b < b, L"\"fixed < fixed\" failed.");

	}

	TEST_METHOD(IntFixedConvert_tests) {
		fixed fix_1;
		fix_1() = 0x00010000;

		Assert::IsTrue(fix_1 == fixed(1), L"\"fixed from int\" failed.");
		Assert::IsTrue(fix_1 == fixed(fix_1), L"\"fixed from fixed\" failed.");
		Assert::IsTrue(1 == ( __int32 ) fix_1);

	}

	TEST_METHOD(Assignment_tests) {
		fixed fix_1(1), f(0);

		Assert::IsTrue((f = 1) == fix_1, L"\"fixed = int\" failed.");
		f = 0;
		Assert::IsTrue((f = fix_1) == fix_1, L"\"fixed = fixed\" failed.");

	}

	TEST_METHOD(Linear_tests) {
		fixed fix_1(1), f(1);

		Assert::IsTrue((f += fix_1) == 2, L"\"fixed += fixed\" failed.");
		Assert::IsTrue((f - fix_1) == 1, L"\"fixed - fixed\" failed.");
		Assert::IsTrue((f - 1) == 1, L"\"fixed - int\" failed.");
		Assert::IsTrue((f -= fix_1) == 1, L"\"fixed -= fixed\" failed.");
		Assert::IsTrue((f += 1) == 2, L"\"fixed += int\" failed.");
		Assert::IsTrue((f -= 1) == 1, L"\"fixed -= int\" failed.");
		Assert::IsTrue((f + fix_1) == 2, L"\"fixed + fixed\" failed.");
		Assert::IsTrue((f + 1) == 2, L"\"fixed + int\" failed.");

	}

	TEST_METHOD(Logarithmic_tests) {
		fixed fix_1(2), f(2);

		Assert::IsTrue((f *= fix_1) == 4, L"\"fixed *= fixed\" failed.");
		Assert::IsTrue((f / fix_1) == 2, L"\"fixed / fixed\" failed.");
		Assert::IsTrue((f / 2) == 2, L"\"fixed / int\" failed.");
		Assert::IsTrue((f /= fix_1) == 4, L"\"fixed /= fixed\" failed.");
		Assert::IsTrue((f *= 2) == 4, L"\"fixed *= int\" failed.");
		Assert::IsTrue((f /= 2) == 2, L"\"fixed /= int\" failed.");
		Assert::IsTrue((f * fix_1) == 4, L"\"fixed * fixed\" failed.");
		Assert::IsTrue((f * 2) == 4, L"\"fixed * int\" failed.");

	}

	TEST_METHOD(Part_tests) {
		fixed fix_1(1), fix_4(4), fix_d2(fix_1 / 2), fix_d8(fix_1 / 8);

		Assert::IsTrue((fix_1 + fix_d2 + fix_d8).fractionPart() == (fix_d2 + fix_d8), L"\"fraction 1\" failed.");
		Assert::IsTrue((-(fix_1 + fix_d2 + fix_d8)).fractionPart() == -(fix_d2 + fix_d8), L"\"fraction 2\" failed.");
		Assert::IsTrue((fix_1 + fix_4 + fix_d2 + fix_d8).fractionPart() == (fix_d2 + fix_d8), L"\"fraction -1\" failed.");
		Assert::IsTrue((-(fix_1 + fix_4 + fix_d2 + fix_d8)).fractionPart() == -(fix_d2 + fix_d8), L"\"fraction -2\" failed.");
		Assert::IsTrue((fix_1 + fix_d2 + fix_d8).integerPart() == fix_1, L"\"integer 1\" failed.");
		Assert::IsTrue((-(fix_1 + fix_d2 + fix_d8)).integerPart() == -fix_1, L"\"integer 2\" failed.");
		Assert::IsTrue((fix_1 + fix_4 + fix_d2 + fix_d8).integerPart() == (fix_1 + fix_4), L"\"integer -1\" failed.");
		Assert::IsTrue((-(fix_1 + fix_4 + fix_d2 + fix_d8)).integerPart() == -(fix_1 + fix_4), L"\"integer -2\" failed.");

	}

	TEST_METHOD(BitLogic_tests) {
		fixed fix_1(1);

		Assert::IsTrue(-1 == (fix_1 | -1)(), L"\"|\" failed.");
		Assert::IsTrue(-1 == (fix_1 |= -1)(), L"\"|\" failed.");
		Assert::IsTrue(0 == (fix_1 & 0)(), L"\"|\" failed.");
		Assert::IsTrue(0 == (fix_1 &= 0)(), L"\"|\" failed.");
		Assert::IsTrue(-1 == (fix_1 ^ -1)(), L"\"|\" failed.");
		Assert::IsTrue(-1 == (fix_1 ^= -1)(), L"\"|\" failed.");

	}

	TEST_METHOD(Abs_test) {
		fixed f(1);

		Assert::IsTrue(Fixed_Point::abs(f) == 1, L"\"abs+\" failed.");
		Assert::IsTrue(Fixed_Point::abs(-f) == 1, L"\"abs+\" failed.");

	}

	TEST_METHOD(Sqrt_test) {

		Assert::IsTrue(Fixed_Point::sqrt(fixed(4)) == 2, L"\"sqrt 4\" failed.");
		Assert::IsTrue(Fixed_Point::sqrt(fixed(1)) == 1, L"\"sqrt 1\" failed.");
		Assert::IsTrue(Fixed_Point::sqrt(fixed(1) >> 2) == (fixed(1) >> 1), L"\"sqrt 0.25\" failed.");

	}

	};
}