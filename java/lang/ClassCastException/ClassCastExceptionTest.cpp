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

#include "../../../kernel/Test.hpp"
#include "ClassCastException.hpp"

using namespace Java::Lang;

TEST (JavaLangClassCastException, Constructor) {
    // Constructs a new ClassCastException with null as its detail message.
    ClassCastException classCastExceptionWithNullMessage;
    assertEquals("", classCastExceptionWithNullMessage.getMessage());

    // Constructs a new ClassCastException with the specified detail message.
    ClassCastException classCastExceptionWithMessage = ClassCastException(
            "ClassCastException with the specified message");
    assertEquals("ClassCastException with the specified message",
                 classCastExceptionWithMessage.getMessage());

    // Constructs a new ClassCastException with the specified detail message and cause.
    ClassCastException classCastExceptionWithMessageAndCause = ClassCastException(
            "ClassCastException with the specified message and cause",
            &classCastExceptionWithMessage);
    assertEquals("ClassCastException with the specified message and cause",
                 classCastExceptionWithMessageAndCause.getMessage());
    assertEquals("ClassCastException with the specified message",
                 classCastExceptionWithMessageAndCause.getCause()->getMessage());

    // Constructs a new ClassCastException with the specified cause.
    ClassCastException classCastExceptionWithCause = ClassCastException(
            &classCastExceptionWithMessageAndCause);
    assertEquals("ClassCastException with the specified message and cause",
                 classCastExceptionWithCause.getCause()->getMessage());
    assertEquals("ClassCastException with the specified message",
                 classCastExceptionWithCause.getCause()->getCause()->getMessage());
}

TEST (JavaLangClassCastException, TryCatch) {
    try {
        throw ClassCastException("Throw ClassCastException");
    }
    catch (ClassCastException e) {
        assertEquals("Throw ClassCastException", e.getMessage());
    }
}