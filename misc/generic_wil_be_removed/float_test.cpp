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
#include "../../unit_test.h"
}

#include "../../library.hpp"

TEST (Generic, Float) {
	
	double string_to_float = Float(std::string("123456"));
	ASSERT_EQUAL(123456.0, string_to_float);
	
	double string_to_float_not_valid = Float((char *) "Hello world");
	ASSERT_EQUAL(0, string_to_float_not_valid);
	
	double string_to_float_valid_1 = Float((char *) "-12345");
	ASSERT_EQUAL(-12345.0, string_to_float_valid_1);
	
	double string_to_float_valid_2 = Float((char *) "-123.45");
	ASSERT_EQUAL(-123.0, string_to_float_valid_2);
	
	double double_to_float = Float(0.0023);
	ASSERT_EQUAL(0.0023, double_to_float);
	
	double long_to_float = Double(2147483647);
	ASSERT_EQUAL(2147483647.0, long_to_float);
	
	double integer_to_float = Float(2345);
	ASSERT_EQUAL(2345.0, integer_to_float);
}