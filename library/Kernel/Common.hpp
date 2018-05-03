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

#ifndef NATIVE_KERNEL_COMMON_HPP
#define NATIVE_KERNEL_COMMON_HPP

// Definitions and macros
#include "Platform.hpp"
#include "Type.hpp"

// C Compatible Library
#include <cerrno>
#include <cassert>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <csignal>
#include <cstdbool>
#include <cctype>
#include <ctime>
#include <regex.h>
#include <stddef.h>

#ifdef LINUX
#include <stdint.h>
#endif

#ifdef DAWIN
#include <stdlib.h>
#include <mach/mach_time.h>
#endif

#ifdef UNIX
#include <unistd.h>
#endif

// C++ Standard Library
#include <atomic>
#include <thread>
#include <mutex>
#include <memory>
#include <algorithm>
#include <stack>
#include <queue>
#include <bitset>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <set>
#include <bitset>
#include <type_traits>
#include <iostream>
#include <typeinfo>
#include <regex>
#include <string>
#include <initializer_list>
#include <functional>

/**
 * Allocate new memory with specific size
 *
 * @param size
 * @return void pointer
 */
inline void *allocateMemory(size_t size) {
    return malloc(size);
}

/**
 * Re-allocate memory with new capacity
 *
 * @param currentPointer
 * @param newCapacity
 * @return void*
 */
inline void *allocateMemory(void *currentPointer, size_t newCapacity) {
    return realloc(currentPointer, newCapacity);
}

/**
 * String copy
 *
 * @param target
 * @return char*
 */
inline char *stringCopy(const char *target) {
    return strdup(target);
}

/**
 * Check if instance t is an instance of Base class
 *
 * @tparam Base
 * @tparam T
 * @param t
 * @return
 */
template<typename Base, typename T>
inline boolean instanceof(T t) {
    return typeid(t).name() == typeid(Base).name();
}

#endif //NATIVE_KERNEL_COMMON_HPP
