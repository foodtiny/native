/**
 * Copyright 2017-2020 Tiny Express Project. All rights reserved.
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

#include "../../../../Test.hpp"
#include "Semaphore.hpp"

using namespace Java::Util::Concurrent;

void SemaphoreTestThread(int sleepTime, int releasePermits,
                         Semaphore* semaphore) {
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
    if(semaphore)
        semaphore->release(releasePermits);
}

void SemaphoreTestThread2(int sleepTime, int loopCount, Semaphore* semaphore) {
    for (int i = 0; i < loopCount; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        if (semaphore) {
            semaphore->release();
        }
    }
}

TEST(JavaUtilConcurrentSemaphore, Constructor) {
    {
        Semaphore semaphoreObject;
        assertEquals(0, semaphoreObject.availablePermits());
    }

    {
        const int initPermits = 3;
        Semaphore semaphoreObject(initPermits);
        assertEquals(initPermits, semaphoreObject.availablePermits());
    }
}

TEST(JavaUtilConcurrentSemaphore, ToString) {
    Semaphore semaphoreObject(3);
    String expect = "[Permits = 3]";
    String result;

    result = semaphoreObject.toString();
    assertEquals(expect.toString(), result.toString());
}

TEST(JavaUtilConcurrentSemaphore, Release) {
    const int expectPermits = 2;
    Semaphore semaphoreObject(1);
    semaphoreObject.release();
    assertEquals(semaphoreObject.availablePermits(), expectPermits);
}

TEST(JavaUtilConcurrentSemaphore, AcquireNotPassingPermits) {
    const int expectPermits = 0;
    Semaphore semaphoreObject;
    std::thread testThread(SemaphoreTestThread, 100, 1, &semaphoreObject);
    semaphoreObject.acquire();
    if (testThread.joinable()) {
        testThread.join();
    }

    assertEquals(expectPermits, semaphoreObject.availablePermits());
}

TEST(JavaUtilConcurrentSemaphore, AcquirePassingPermits) {
    const int expectPermits = 1;
    const int threadCount = 3;
    Semaphore semaphoreObject;
    std::vector<std::thread> testThreads(threadCount);
    for (auto& it : testThreads) {
        it = std::move(std::thread(SemaphoreTestThread,
                                   100, 1, &semaphoreObject));
    }

    semaphoreObject.acquire(2);

    for (auto& it : testThreads) {
        if (it.joinable()) {
            it.join();
        }
    }

    assertEquals(expectPermits, semaphoreObject.availablePermits());
}

TEST(JavaUtilConcurrentSemaphore, TryAcquireNotPassingPermits) {
    const int expectPermits = 1;
    Semaphore semaphoreObject;
    std::thread testThread(SemaphoreTestThread,
                           100, 1, &semaphoreObject);
    boolean result = semaphoreObject.tryAcquire();

    if (testThread.joinable()) {
        testThread.join();
    }

    assertFalse(result);
    assertEquals(expectPermits, semaphoreObject.availablePermits());
}

TEST(JavaUtilConcurrentSemaphore, TryAcquirePassingPermitsWithTimeout) {
    const int expectPermits = 0;
    Semaphore semaphoreObject;
    std::thread testThread(SemaphoreTestThread2, 100, 2, &semaphoreObject);

    semaphoreObject.release();
    bool result = semaphoreObject.tryAcquire(3, 1000);

    if (testThread.joinable()) {
        testThread.join();
    }

    assertTrue(result);
    assertEquals(expectPermits, semaphoreObject.availablePermits());
}

TEST(JavaUtilConcurrentSemaphore, TryAcquirePassingPermitsWithInitPermits) {
    const int expectPermits = 1;
    Semaphore semaphoreObject(2);
    semaphoreObject.tryAcquire();
    assertEquals(expectPermits, semaphoreObject.availablePermits());
}