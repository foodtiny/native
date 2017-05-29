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

#include "../string.h"
#include "../unit_test.h"

TEST (String, ConvertFromChar) {
	char number_character = '6';
	ASSERT_STR("6", string_from_char(number_character));
	
	char null_character = '\0';
	ASSERT_STR("", string_from_char(null_character));
}

TEST (String, ConvertFromShort) {
	int number = 123;
	char *expect = "123";
	char *result = string_from_short(number);
	ASSERT_STR(expect, result);
	
	int number2 = -123;
	char *expect2 = "-123";
	char *result2 = string_from_short(number2);
	ASSERT_STR(expect2, result2);
}

TEST (String, ConvertFromInt) {
	int input = 0;
	char *expect = "0";
	char *result = string_from_int(input);
	ASSERT_STR(expect, result);
	
	int input1 = 1;
	char *expect1 = "1";
	char *result1 = string_from_int(input1);
	ASSERT_STR(expect1, result1);
	
	int input2 = 10;
	char *expect2 = "10";
	char *result2 = string_from_int(input2);
	ASSERT_STR(expect2, result2);
	
	int input3 = 2147483647;
	char *expect3 = "2147483647";
	char *result3 = string_from_int(input3);
	ASSERT_STR(expect3, result3);
	
	int input4 = -2147483647;
	char *expect4 = "-2147483647";
	char *result4 = string_from_int(input4);
	ASSERT_STR(expect4, result4);
}

TEST (String, ConvertFromLong) {
	long input = 2147483647;
	char *expect = "2147483647";
	char *result = string_from_long(input);
	ASSERT_STR(expect, result);
	
	long input1 = -2147483647;
	char *expect1 = "-2147483647";
	char *result1 = string_from_long(input1);
	ASSERT_STR(expect1, result1);
}

TEST (String, ConvertFromFloat) {
	float input = 12.56;
	char *expect = "12.56";
	char *result = string_from_float(input);
	ASSERT_STR(expect, result);
	
	float input1 = -1.56799;
	char *expect1 = "-1.56799";
	char *result1 = string_from_float(input1);
	ASSERT_STR(expect1, result1);
}

TEST (String, ConvertFromDouble) {
	double input = 125.569123;
	char *expect = "125.569123";
	char *result = string_from_double(input);
	ASSERT_STR(expect, result);
	
	double input1 = -125.56123;
	char *expect1 = "-125.56123";
	char *result1 = string_from_double(input1);
	ASSERT_STR(expect1, result1);
}

TEST (String, ConvertToShort) {
	ASSERT_EQUAL(0, string_to_short(NULL));
	
	char *input = "123";
	short result = string_to_short(input);
	ASSERT_EQUAL(123, result);
	
	char *input1 = "-123";
	short result1 = string_to_short(input1);
	ASSERT_EQUAL(-123, result1);
}

TEST (String, ConvertToInt) {
	char *input = "123\0";
	int result = string_to_int(input);
	ASSERT_EQUAL(123, result);
	
	char *input1 = "-123\0";
	int result1 = string_to_int(input1);
	ASSERT_EQUAL(-123, result1);
	
	char *input2 = "\0";
	int result2 = string_to_int(input2);
	ASSERT_EQUAL(0, result2);
	
	char *input3 = "";
	int result3 = string_to_int(input3);
	ASSERT_EQUAL(0, result3);
	
	char *input4 = "12.321";
	int result4 = string_to_int(input4);
	ASSERT_EQUAL(12, result4);
	
	char *input5 = "kajshdkashd";
	int result5 = string_to_int(input5);
	ASSERT_EQUAL(0, result5);
	
	char *input6 = NULL;
	int result6 = string_to_int(input6);
	ASSERT_EQUAL(0, result6);
	
	char *input7 = "foodtiny.com";
	int result7 = string_to_int(input7);
	ASSERT_EQUAL(0, result7);
}

TEST (String, ConvertToLong) {
	char *input = "21474836";
	long result = string_to_long(input);
	ASSERT_EQUAL(21474836, result);
	
	char *input1 = "-21474836";
	long result1 = string_to_long(input1);
	ASSERT_EQUAL(-21474836, result1);
	
	char *input2 = "Hello world";
	long result2 = string_to_long(input2);
	ASSERT_EQUAL(0, result2);
}

TEST (String, ConvertToFloat) {
	char *input = "12.56";
	float result = string_to_float(input);
	ASSERT_EQUAL(12.56, result);
	
	char *input1 = "-1.56799";
	float result1 = string_to_float(input1);
	ASSERT_EQUAL(-1.56799, result1);
}

TEST (String, ConvertToDouble) {
	char *input = "125.569123";
	double result = string_to_double(input);
	ASSERT_EQUAL(125.569123, result);
	
	char *input1 = "-125.56123";
	double result1 = string_to_double(input1);
	ASSERT_EQUAL(-125.56123, result1);
}

TEST (String, ConvertToBoolean) {
	char *target0 = "1";
	int boolean0 = string_to_boolean(target0);
	ASSERT_TRUE(boolean0);
	
	char *target1 = "TRUE";
	int boolean1 = string_to_boolean(target1);
	ASSERT_TRUE(boolean1);
	
	char *target2 = "True";
	int boolean2 = string_to_boolean(target2);
	ASSERT_TRUE(boolean2);
	
	char *target3 = "true";
	int boolean3 = string_to_boolean(target3);
	ASSERT_TRUE(boolean3);
	
	char *target4 = "FALSE";
	int boolean4 = string_to_boolean(target4);
	ASSERT_FALSE(boolean4);
	
	char *target5 = "False";
	int boolean5 = string_to_boolean(target5);
	ASSERT_FALSE(boolean5);
	
	char *target6 = "false";
	int boolean6 = string_to_boolean(target6);
	ASSERT_FALSE(boolean6);
}
