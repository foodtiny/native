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

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "../Common.hpp"
#include "../Type.hpp"
#include "../String.hpp"

/**
 * Convert generic types to string
 *
 * @param target
 * @return string
 */
#define STR_FROM(NAME, TYPE, FORMAT); \
char* Kernel::stringFrom##NAME(TYPE target) {\
        char *convert;\
        asprintf(&convert, FORMAT, target);\
        return convert;\
}

/**
 * Convert string to generic types
 *
 * @param target
 * @return generic values
 */
#define STR_TO(NAME, TYPE, FORMAT);\
TYPE Kernel::stringTo##NAME(char *target) {\
    if (target == NULL || strcmp(target, "\0") == 0) return 0;\
        TYPE result;\
    sscanf(target, FORMAT, &result);\
    return result;\
}
STR_FROM(Short, short, "%d");
STR_FROM(Int, int, "%d");
STR_FROM(Long, long, "%ld");
STR_FROM(Float, float, "%g");
STR_FROM(Double, double, "%.16g");
STR_TO(Short, short, "%hi");
STR_TO(Float, float, "%g");
STR_TO(Double, double, "%lg");

/**
 * String from char
 *
 * @param target
 * @return string
 */
char *Kernel::stringFromChar(char target) {
	if (target == '\0') {
		return strdup("");
	}
	char *result = (char *)calloc(2, sizeof(char));
	result[ 0 ] = target;
	result[ 1 ] = '\0';
	return result;
}

/**
 * String to char
 *
 * @param target
 * @return string
 */
char Kernel::stringToChar(char *target) {
	if (isEmptyString(target)) {
		return '\0';
	}
	return target[ 0 ];
}

/**
 * String to int
 *
 * @param target
 * @return string
 */
int Kernel::stringToInt(char *target) {
	if (target == NULL) {
		return 0;
	}
	return atoi(target);
}

/**
 * String to long
 *
 * @param target
 * @return string
 */
long Kernel::stringToLong(char *target) {
	if (target == NULL) {
		return 0;
	}
	return atol(target);
}

/**
 * String to boolean
 *
 * @param target
 * @return TRUE | FALSE
 */
int Kernel::stringToBoolean(char *target) {
	if (lengthPointerChar(target) == 0) {
		return FALSE;
	}
	char *boolean_value = stringLower(target);
	if (stringEquals(boolean_value, "true")) {
		free(boolean_value);
		return TRUE;
	}
	if (stringToInt(boolean_value) == TRUE) {
		free(boolean_value);
		return TRUE;
	}
	free(boolean_value);
	return FALSE;
}

/**
 * String from boolean
 *
 * @param target
 * @return string
 */
char *Kernel::stringFromBoolean(int target) {
    if (target == FALSE) {
        return strdup("false");
    }

    return strdup("true");
}
