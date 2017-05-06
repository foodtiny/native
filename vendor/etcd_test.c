///**
// * Copyright (c) 2016 Food Tiny Project. All rights reserved.
// *
// * Redistribution and use in source and binary forms, with or without
// * modification, are permitted provided that the following conditions are met:
// *
// * Redistributions of source code must retain the above copyright
// * notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above
// * copyright notice, this list of conditions and the following disclaimer
// * in the documentation and/or other materials provided with the
// * distribution.
// *
// * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// */
//
//#include "../builtin.h"
//#include "../unit_test.h"
//#include "../vendor.h"
//
//TEST(Vendor, ETCDGet) {
//
//    char *node = etcd_get(ETCD_MASTER, "/elassandra/development/seeds/test_node");
//    ASSERT_TRUE(length_pointer_char(node) > 0);
//
//    node = etcd_get("", "/elassandra/development/seeds/test_node");
//    ASSERT_FALSE(length_pointer_char(node) > 0);
//
//    node = etcd_get(ETCD_MASTER, "");
//    ASSERT_FALSE(length_pointer_char(node) > 0);
//}
//
//TEST(Vendor, ETCDSet) {
//
//    char *result = etcd_set(ETCD_MASTER, "/elassandra/development/seeds/test_node", "1223");
//    ASSERT_TRUE(length_pointer_char(result) > 0);
//
//    result = etcd_set(ETCD_MASTER, "/elassandra/development/seeds/test_node", "Hello World");
//    ASSERT_TRUE(length_pointer_char(result) > 0);
//
//    result = etcd_set("", "/elassandra/development/seeds/test_node", "Hello World");
//    ASSERT_FALSE(length_pointer_char(result) > 0);
//
//    result = etcd_set(ETCD_MASTER, "", "Hello World");
//    ASSERT_FALSE(length_pointer_char(result) > 0);
//
//    result = etcd_set(ETCD_MASTER, "/elassandra/development/seeds/test_node", "");
//    ASSERT_FALSE(length_pointer_char(result) > 0);
//}
//
//
