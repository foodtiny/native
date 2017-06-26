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
//extern "C" {
//#include "../../../unit_test.h"
//}
//
//#include "Date.hpp"
//
//using namespace Java::Util;
//
//TEST (JavaUtil, DateConstructor) {
//    // Given valid timer of C++ to test current local time
//    time_t now = time(0);
//    tm *currentTime = localtime(&now);
//    int expectedYear = currentTime->tm_year + 1900; // This class return since 1900
//
//    // Given valid constructor and test
//    Date date;
//    ASSERT_EQUAL(expectedYear, date.getYear());
//
//    expectedYear = 2018;
//    date = Date(2018, 05, 20);
//    ASSERT_EQUAL(expectedYear, date.getYear());
//
//    expectedYear = 2019;
//    date = Date(2019, 05, 21, 05, 22);
//    ASSERT_EQUAL(expectedYear, date.getYear());
//
//    expectedYear = 2200;
//    date = Date(2200, 05, 21, 05, 50, 58);
//    ASSERT_EQUAL(expectedYear, date.getYear());
//
//    expectedYear = 2017;
//    date = Date(1498042091); //2017
//    ASSERT_EQUAL(expectedYear, date.getYear());
//
//    expectedYear = 2017;
//    String dateString = "Thu Jun 22 2017 12:35:34";
//    date = Date(dateString);
//    ASSERT_EQUAL(expectedYear, date.getYear());
//
//    Date sameDate = date;
//    ASSERT_EQUAL(sameDate.getYear(), date.getYear());
//}
//
//TEST (JavaUtil, DateGetYear) {
//    // Given valid date to test getYear()
//    int expectedYear = 2018;
//    Date date = Date(2018, 05, 20, 20, 50, 58);
//
//    ASSERT_EQUAL(expectedYear, date.getYear());
//}
//
//TEST (JavaUtil, DateGetMonth) {
//    // Given valid date to test getMonth()
//    int expectedMonth = 05;
//    Date date = Date(2018, 05, 20, 20, 50, 58);
//
//    ASSERT_EQUAL(expectedMonth, date.getMonth());
//}
//
//TEST (JavaUtil, DateGetDayOfMonth) {
//    // Given valid date to test getDate()
//    int expectedDayOfMonth = 20;
//    Date date = Date(2018, 05, 20, 20, 50, 58);
//
//    ASSERT_EQUAL(expectedDayOfMonth, date.getDate());
//}
//
//TEST (JavaUtil, DateGetDayOfWeek) {
//    // Given valid date to test getDay()
//    int expectedDayOfWeek = 4; // Thursday
//    Date date = Date(2017, 05, 22, 20, 50, 58);
//
//    ASSERT_EQUAL(expectedDayOfWeek, date.getDay());
//}
//
//TEST (JavaUtil, DateGetHour) {
//    // Given valid date to test getHours()
//    int expectedHour = 20;
//    Date date = Date(2018, 05, 20, 20, 50, 58);
//
//    ASSERT_EQUAL(expectedHour, date.getHours());
//}
//
//TEST (JavaUtil, DateGetMinutes) {
//    // Given valid date to test getMinutes()
//    int expectedMinutes = 50;
//    Date date = Date(2018, 05, 20, 20, 50, 58);
//
//    ASSERT_EQUAL(expectedMinutes, date.getMinutes());
//}
//
//TEST (JavaUtil, DateGetSeconds) {
//    // Given valid date to test getSeconds()
//    int expectedSecond = 58;
//    Date date = Date(2018, 05, 20, 20, 50, 58);
//
//    ASSERT_EQUAL(expectedSecond, date.getSeconds());
//}
//
//TEST (JavaUtil, DateGetTime) {
//    // Get current time of system to validate getTime()
//    long expectedTime = 1498032610;
//
//    Date date = expectedTime;
//
//    ASSERT_EQUAL(expectedTime, date.getTime());
//}
//
//TEST (JavaUtil, DateSetDate) {
//    // Given valid date to test setDate()
//    Date date;
//    int expectedDayOfMonth = 15;
//
//    date.setDate(expectedDayOfMonth);
//    ASSERT_EQUAL(expectedDayOfMonth, date.getDate());
//}
//
//TEST (JavaUtil, DateSetHours) {
//    // Given valid date to test setHours()
//    Date date;
//    int expectedHour = 20;
//
//    date.setHours(expectedHour);
//    ASSERT_EQUAL(expectedHour, date.getHours());
//}
//
//TEST (JavaUtil, DateSetMinutes) {
//    // Given valid date to test setMinutes()
//    Date date;
//    int expectedMinutes = 58;
//
//    date.setMinutes(expectedMinutes);
//    ASSERT_EQUAL(expectedMinutes, date.getMinutes());
//}
//
//TEST (JavaUtil, DateSetMonth) {
//    // Given valid date to test setMonth()
//    Date date;
//    int expectedMonth = 12;
//
//    date.setMonth(expectedMonth);
//    ASSERT_EQUAL(expectedMonth, date.getMonth());
//}
//
//TEST (JavaUtil, DateSetSeconds) {
//    // Given valid date to test setSeconds()
//    Date date;
//    int expectedSecond = 15;
//
//    date.setSeconds(expectedSecond);
//    ASSERT_EQUAL(expectedSecond, date.getSeconds());
//}
//
//TEST (JavaUtil, DateSetTime) {
//    // Given valid date to test setTime()
//    Date date;
//    int expectedTime = 1498028643;
//
//    date.setTime(expectedTime);
//    ASSERT_EQUAL(expectedTime, date.getTime());
//}
//
//TEST (JavaUtil, DateSetYear) {
//    // Given valid date to test setYear()
//    Date date;
//    int expectedYear = 2022;
//
//    date.setYear(expectedYear);
//    ASSERT_EQUAL(expectedYear, date.getYear());
//}
//
///**
// * This test case aim to make CI happy, no need to do like that
// * Usage:
// *  Date date;
// *  date.toGMTString()
// */
//TEST (JavaUtil, DateGMTString)  {
//    // Given valid date to test GMT time, this test case is based on Date.getTimeZoneOffset
//    Date date = Date(2017, 05, 22, 12, 35, 34);
//    int timeZone = date.getTimezoneOffset();
//
//    string timeString;
//    asprintf(&timeString, "Thu Jun 22 2017 %02d:35:34", 12 - timeZone);
//
//    String expectedGMTString = timeString;
//    free(timeString);
//
//    ASSERT_STR(expectedGMTString.toString(), date.toGMTString().toString());
//}
//
//TEST (JavaUtil, DateLocaleString) {
//    // Given valid date to test local time
//    Date date = Date(2017, 05, 22, 12, 35, 34);
//    String expectedLocaleString = "Thu Jun 22 2017 12:35:34";
//
//    ASSERT_STR(expectedLocaleString.toString(), date.toLocaleString().toString());
//}
//
//TEST (JavaUtil, DateAfter) {
//    // Given valid date to test another date is after this day or not
//    Date date = Date(2017, 05, 21, 14, 05, 43);
//
//    Date dateBefore = Date(2017, 05, 21, 14, 05, 40);
//    ASSERT_TRUE(date.after(dateBefore));
//
//    Date dateAfter = Date(2017, 05, 21, 14, 05, 45);
//    ASSERT_FALSE(date.after(dateAfter));
//}
//
//TEST (JavaUtil, DateBefore) {
//    // Given valid date to test another date is before this day or not
//    Date date = Date(2017, 05, 21, 14, 05, 43);
//
//    Date dateBefore = Date(2017, 05, 21, 14, 05, 40);
//    ASSERT_FALSE(date.before(dateBefore));
//
//    Date dateAfter = Date(2017, 05, 21, 14, 05, 45);
//    ASSERT_TRUE(date.before(dateAfter));
//}
//
//TEST (JavaUtil, DateClone) {
//    // Given valid date and make a copy of this date
//    Date date = Date(2017, 05, 21, 14, 05, 43);
//
//    Date target = date;
//    ASSERT_EQUAL(date.getSeconds(), target.getSeconds());
//}
//
//TEST (JavaUtil, DateCompare) {
//    // Given valid date to test compareTo() with dateBefore, dateAfter, dateEqual
//    Date date = Date(2017, 05, 21, 14, 05, 43);
//
//    Date dateBefore = Date(2017, 05, 21, 14, 05, 25);
//    Date dateAfter = Date(2017, 05, 21, 14, 05, 50);
//    Date dateEqual = Date(2017, 05, 21, 14, 05, 43);
//
//    int expectedResult = 1;
//    ASSERT_EQUAL(expectedResult, date.compareTo(dateBefore));
//
//    expectedResult = -1;
//    ASSERT_EQUAL(expectedResult, date.compareTo(dateAfter));
//
//    expectedResult = 0;
//    ASSERT_EQUAL(expectedResult, date.compareTo(dateEqual));
//}
//
///**
// * This test case aim to make CI happy, no need to do like that
// * Usage:
// *  Date::UTC(...)
// */
//TEST (JavaUtil, DateUTC) {
//    // Given valid date tot est Date::UTC - should to return correct epoch value
//    long result = Date::UTC(2017, 05, 21, 21, 05, 43);
//
//    // Init timer of system
//    tm timePresenter = {0};
//    timePresenter.tm_year = 2017 - 1900; //LocalTimer start since 1900;
//    timePresenter.tm_mon = 05;
//    timePresenter.tm_mday = 21;
//    timePresenter.tm_hour = 21;
//    timePresenter.tm_min = 05;
//    timePresenter.tm_sec = 43;
//
//    long expectedTime = mktime(&timePresenter);
//
//    ASSERT_EQUAL(expectedTime, result);
//}
//
//TEST (JavaUtil, DateGetTimeZone) {
//    // Given valid date to test current time zone, this test case is based on Vietnam GMT+7
//    Date date;
//
//    // Init timer of system to test time zone
//    time_t now = time(0);
//    int expectedTimeZone = localtime(&now)->tm_hour - gmtime(&now)->tm_hour;
//
//    ASSERT_EQUAL(expectedTimeZone, date.getTimezoneOffset());
//}