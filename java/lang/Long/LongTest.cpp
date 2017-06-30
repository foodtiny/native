/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
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

extern "C" {
#include "../../../unit_test.h"
}

#include "Long.hpp"

using namespace Java::Lang;

TEST (JavaLang, LongConstructor) {

	// Given empty value for Long constructor and assign value - Return Long
	Long emptyLong;
	emptyLong = 3;
	ASSERT_EQUAL(3, emptyLong.longValue());

	// Given value for Integer constructor and assign value - Return string
	Long validLong = 3;
	ASSERT_EQUAL(3, validLong.longValue());

	Long test = 3;
	ASSERT_EQUAL(3, test.intValue());
}

TEST (JavaLang, LongComparision) {
	// Give a valid number and make a comparision
	Long validNumber = 123000000000;
	Long targetNumber;

	// Test validNumber is equal targetNumber
	targetNumber = 123000000000;
	ASSERT_TRUE(validNumber == targetNumber);

	// Test validNumber is not equal targetNumber
	targetNumber = 113000000000;
	ASSERT_TRUE(validNumber != targetNumber);

	// Test validNumber is less than targetNumber
	targetNumber = 124000000000;
	ASSERT_TRUE(validNumber < targetNumber);

	// Test validNumber is equal or less then targetNumber
	targetNumber = 125000000000;
	ASSERT_TRUE(validNumber <= targetNumber);

	// Test validNumber is more than targetNumber
	targetNumber = 122000000000;
	ASSERT_TRUE(validNumber > targetNumber);

	// Test validNumber is equal or more than targetNumber
	targetNumber = 121000000000;
	ASSERT_TRUE(validNumber >= targetNumber);
}

TEST (JavaLang, LongOperator) {
	// Given a valid number
	Long validNumber = 5;
	Long targetNumber = 3;

	// Make a summation with targetNumber
	Long summationNumber = 8;
	ASSERT_TRUE(summationNumber == ( validNumber + targetNumber ));

	// Make a subtraction with targetNumber
	Long subtractionNumber = 2;
	ASSERT_TRUE(subtractionNumber == ( validNumber - targetNumber ));

	// Make a multiplication with targetNumber
	Long multiplicationNumber = 15;
	ASSERT_TRUE(multiplicationNumber == ( validNumber * targetNumber ));

	// Make a division with targetNumber
	Long divisionNumber = 1;
	ASSERT_TRUE(divisionNumber == ( validNumber / targetNumber ));

	// Make a modulo with targetNumber
	Long modNumber = 2;
	ASSERT_TRUE(modNumber == ( validNumber % targetNumber ));
}

TEST (JavaLang, LongParseLong) {
	// Given value for Long constructor and assign value - Return long
	Long validLongPointer = Long::parseLong("6");
	ASSERT_EQUAL(6, validLongPointer.longValue());

    // Given valid string to test parseLong with radix 16
    String validNumberString = "1b";
    Long result = Long::parseLong(validNumberString, 16);

    long expectedResult = 27;
    ASSERT_EQUAL(expectedResult, result.longValue());

	String invalidNumbeString = "122q3";
	result = Long::parseLong(invalidNumbeString, 16);

	expectedResult = -1;
	ASSERT_EQUAL(expectedResult, result.longValue());
}

TEST (JavaLang, LongDecode) {
	// Given valid numberString to test decode value
	String validNumberString = "0x1b";
	Long result = Long::decode(validNumberString);

	long expectedResult = 27;
	ASSERT_EQUAL(expectedResult, result.longValue());

	String invalidNumbeString = "0x23xx";
	result = Long::decode(invalidNumbeString);

	expectedResult = -1;
	ASSERT_EQUAL(expectedResult, result.longValue());
}

TEST (JavaLang, LongNumberOfLeadingZeros) {
	// Given valid long number to test leading - this test case was confirmed by java source code
	long validValue = 4053239666997989821L;
	int result = Long::numberOfLeadingZeros(validValue);

	int expectedResult = 2;
	ASSERT_EQUAL(expectedResult, result);

	validValue = 40532396L;
	result = Long::numberOfLeadingZeros(validValue);

	expectedResult = 38;
	ASSERT_EQUAL(expectedResult, result);
}

TEST (JavaLang, LongToHexString) {
	// Given valid long value to test toHexString() - this test case was confirm by java source code
	long validValue = 4053239666997989821;
	String result = Long::toHexString(validValue);

	String expectedString = "384000008cf011bd";
	ASSERT_STR(expectedString.toString(), result.toString());

	validValue = -5603022497796657139;
	result = Long::toHexString(validValue);

	expectedString = "b23e10b96e4ef00d";
	ASSERT_STR(expectedString.toString(), result.toString());
}