/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "Integer.hpp"
#include "../Math/Math.hpp"

using namespace Java::Lang;

Integer::Integer() {
	this->original = 0;
	this->string_original = string_from_int(this->original);
}

Integer::Integer(int original) {
	this->original = original;
	this->string_original = string_from_int(this->original);
}
// TODO(thoangminh): Enable after finish parseInt(String inputString, int radix)
// Integer::Integer(String inputStringtringInput) {
// 	this->original = string_to_int(stringInput.toString());
// 	this->string_original = stringInput.toString();
// }

Integer::Integer(const Integer &integer) {
	this->original = integer.original;
	this->string_original = string_from_int(this->original);
}

Integer::~Integer() {
	if (this->string_original != NULL)  {
		free(this->string_original);
	}
}

char Integer::charValue() const {
	string convertResult = string_from_int(this->original);
	char result = string_to_char(convertResult);
	free(convertResult);
	return result;
}

string Integer::stringValue() const {
    return this->string_original;
}

short Integer::shortValue() const {
	return static_cast<short> (this->original);
}

int Integer::intValue() const {
	return this->original;
}

long Integer::longValue() const {
	return static_cast<long> (this->original);
}

float Integer::floatValue() const {
	return static_cast<float> (this->original);
}

double Integer::doubleValue() const {
	return static_cast<double> (this->original);
}

Integer Integer::operator=(const Integer &target) {
	this->original = target.original;
	free(this->string_original);
	this->string_original = string_from_int(this->original);
    return *this;
}

Integer Integer::operator+(const Integer &target) {
	return this->original + target.original;
}

Integer Integer::operator-(const Integer &target) {
	return this->original - target.original;
}

boolean Integer::operator==(const Integer &target) const {
	return this->original == target.original;
}

boolean Integer::operator!=(const Integer &target) const {
	return !this->operator==(target);
}

boolean Integer::operator<(const Integer &target) const {
	return this->original < target.original;
}

boolean Integer::operator>(const Integer &target) const {
	return this->original > target.original;
}

boolean Integer::operator<=(const Integer &target) const {
	return this->original <= target.original;
}

boolean Integer::operator>=(const Integer &target) const {
	return this->original >= target.original;
}

Integer Integer::operator/(const Integer &target) {
	return ( this->original / target.original );
}

Integer Integer::operator*(const Integer &target) {
	return ( this->original * target.original );
}

Integer Integer::operator%(const Integer &target) {
	return ( this->original % target.original );
}

int Integer::bitCount(int inputInt) {
	int resultBitCount = 0;
	
	if ( inputInt < 0 ) {
		resultBitCount = 1;
		inputInt = -inputInt;
	}

	while( (inputInt != 0) || resultBitCount == 32 ) {

		if( (inputInt & 1) == 1 ) {
			resultBitCount++;
		}

		inputInt = inputInt >> 1;
	}

	return resultBitCount;
}

byte Integer::byteValue() {
	return static_cast<byte> (this->original);
}

int Integer::compare(int inputInt1, int inputInt2) {
	if(inputInt1 < inputInt2) {
		return -1;
	}

	if(inputInt1 > inputInt2) {
		return 1;
	}

	return 0;
}

int Integer::compareTo(Integer anotherInteger) {
	return compare(this->original, anotherInteger.intValue());
}

int Integer::compareUnsigned(int inputInt_1, int inputInt_2) {
	return compare(inputInt_1 + MIN_VALUE, inputInt_2 + MIN_VALUE);
}

// Integer Integer::decode(String inputStringtringInput) {


// }

int Integer::divideUnsigned(int dividend, int divisor) {
	return static_cast<int> (toUnsignedLong(dividend) / toUnsignedLong(divisor));
}

// double Integer::doubleValue() {


// }

// boolean Integer::equals(Integer obj) {


// }

// Integer Integer::getInteger(String inputString) {


// }

// Integer Integer::getInteger(String inputString, int inputInt) {


// }

// Integer Integer::getInteger(String inputString, Integer inputInteger) {


// }

// int Integer::hashCode() {


// }

// int Integer::hashCode(int inputInt) {
// 	return inputInt;
// }

int Integer::highestOneBit(int inputInt)  {
	inputInt |= (inputInt >> 1);
    inputInt |= (inputInt >> 2);
    inputInt |= (inputInt >> 4);
    inputInt |= (inputInt >> 8);
    inputInt |= (inputInt >> 16);

    return inputInt - ((unsigned int) inputInt >> 1);
}

int Integer::lowestOneBit(int inputInt) {
	return inputInt & -inputInt;
}

int Integer::max(int inputInt_1, int inputInt_2) {
	return Math::max(inputInt_1, inputInt_2);
}

int Integer::min(int inputInt_1, int inputInt_2) {
	return Math::min(inputInt_1, inputInt_2);
}

int Integer::numberOfLeadingZeros(int inputInt) {
	if (inputInt == 0) {
        return 32;
	}

    int n = 1;

    if ((unsigned int) inputInt >> 16 == 0) {
        n += 16;
        inputInt <<= 16;
    }

    if ((unsigned int) inputInt >> 24 == 0) {
        n += 8;
        inputInt <<= 8;
    }

    if ((unsigned int) inputInt >> 28 == 0) {
        n += 4;
        inputInt <<= 4;
    }

    if ((unsigned int) inputInt >> 30 == 0) {
        n += 2;
        inputInt <<= 2;
    }

    n -= (unsigned int) inputInt >> 31;

    return n;
}

int Integer::numberOfTrailingZeros(int inputInt) {
	int y;

    if (inputInt == 0)
        return 32;

    int n = 31;
    y = inputInt << 16;

    if (y != 0) {
        n = n - 16;
        inputInt = y;
    }

    y = inputInt << 8;

    if (y != 0) {
        n = n - 8;
        inputInt = y;
    }

    y = inputInt << 4;

    if (y != 0) {
        n = n - 4;
        inputInt = y;
    }

    y = inputInt << 2;

    if (y != 0) {
        n = n - 2;
        inputInt = y;
    }

    return n - ((unsigned int) (inputInt << 1) >> 31);
}

// TODO(thoangminh): Need class NumberFormatException, Character
// int Integer::parseInt(String inputString, int radix) {
	// if (s == null) {
 //        throw new NumberFormatException("null");
 //    }

 //    if (radix < Character.MIN_RADIX) {
 //        throw new NumberFormatException("radix " + radix
 //                + " less than Character.MIN_RADIX");
 //    }

 //    if (radix > Character.MAX_RADIX) {
 //        throw new NumberFormatException("radix " + radix
 //                + " greater than Character.MAX_RADIX");
 //    }

 //    int result = 0;
 //    boolean negative = false;
 //    int i = 0, len = s.length();
 //    int limit = -Integer.MAX_VALUE;
 //    int multmin;
 //    int digit;

 //    if (len > 0) {
 //        char firstChar = s.charAt(0);
 //        if (firstChar < '0') { // Possible leading "+" or "-"
 //            if (firstChar == '-') {
 //                negative = true;
 //                limit = Integer.MIN_VALUE;
 //            } else if (firstChar != '+')
 //                throw NumberFormatException.forInputString(s);

 //            if (len == 1) // Cannot have lone "+" or "-"
 //                throw NumberFormatException.forInputString(s);
 //            i++;
 //        }
 //        multmin = limit / radix;
 //        while (i < len) {
 //            // Accumulating negatively avoids surprises near MAX_VALUE
 //            digit = Character.digit(s.charAt(i++), radix);
 //            if (digit < 0) {
 //                throw NumberFormatException.forInputString(s);
 //            }
 //            if (result < multmin) {
 //                throw NumberFormatException.forInputString(s);
 //            }
 //            result *= radix;
 //            if (result < limit + digit) {
 //                throw NumberFormatException.forInputString(s);
 //            }
 //            result -= digit;
 //        }
 //    } else {
 //        throw NumberFormatException.forInputString(s);
 //    }
 //    return negative ? result : -result;
// }

int Integer::parseInt(String inputString) {
	return string_to_int(inputString.toString());
	// TODO(thoanggminh): enable it after finish
    // Integer::parseInt(String inputString, int radix)
	// return parseInt(inputString,10);
}

// int Integer::parseUnsignedInt(String inputString, int radix) {


// }

// int Integer::parseUnsignedInt(String inputString) {

	
// }

int Integer::remainderUnsigned(int dividend, int divisor) {
	return static_cast<int> (toUnsignedLong(dividend) % toUnsignedLong(divisor));
}

int Integer::reverse(int inputInt) {
	inputInt = (inputInt & 0x55555555) << 1 
				| ((unsigned int) inputInt >> 1) & 0x55555555;

    inputInt = (inputInt & 0x33333333) << 2 
    			| ((unsigned int) inputInt >> 2) & 0x33333333;

    inputInt = (inputInt & 0x0f0f0f0f) << 4 
    			| ((unsigned int) inputInt >> 4) & 0x0f0f0f0f;

    inputInt = (inputInt << 24) | ((inputInt & 0xff00) << 8)
    			| (((unsigned int) inputInt >> 8) & 0xff00)
    			| ((unsigned int) inputInt >> 24);

    return inputInt;
}

int Integer::reverseBytes(int inputInt) {
	inputInt = (((unsigned int) inputInt >> 24))
				| ((inputInt >> 8) & 0xFF00)
				| ((inputInt << 8) & 0xFF0000)
				| ((inputInt << 24));

	return inputInt;
}

int Integer::rotateLeft(int inputInt, int distance) {
	inputInt = (inputInt << distance) 
				| ((unsigned int) inputInt >> -distance);

	return inputInt;
}

int Integer::rotateRight(int inputInt, int distance) {
	return ((unsigned int) inputInt >> distance) | (inputInt << -distance);
}

// int Integer::signum(int inputInt) {


// }

// int Integer::stringSize(int x) {


// }

// int Integer::sum(int a, int b) {


// }

// string Integer::toBinaryString(int inputInt) {


// }

// string Integer::toHexString(int inputInt) {


// }

// string Integer::toOctalString(int inputInt) {


// }

string Integer::toString() const {
	return this->string_original;
}

// String Integer::toString(int i) {


// }

// string Integer::toString(int inputInt, int radix) {


// }

long Integer::toUnsignedLong(int inputInt) {
	// Make the overload bits is 0 to make sure inputInt in 32 bit type.
	return ((long) inputInt) & 0xffffffffL;
}

// string Integer::toUnsignedString(int inputInt, int radix) {


// }

// Integer Integer::valueOf(String inputString) {


// }

// Integer Integer::valueOf(int inputInt) {


// }

// Integer Integer::valueOf(String inputStringtringInput, int radixIntInput) {


// }