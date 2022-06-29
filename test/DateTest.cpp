//
// Created by beatrice on 29/06/22.
//

#include "gtest/gtest.h"

#include "../Date.h"

TEST(Date, Constructor) {
    Date d(3, 7, 2022);
    ASSERT_EQ(3, d.getDay());
    ASSERT_EQ(7, d.getMonth());
    ASSERT_EQ(2022, d.getYear());
}

TEST(Date, TestInvalidDate) {
    EXPECT_THROW(Date::checkValidity(30, 2, 2022), std::runtime_error);
}

TEST(Date, TestValidDate) {
    EXPECT_NO_THROW(Date::checkValidity(1, 1, 2022));
}

TEST(Date, TestDayCounterLeapYear) {
    int numDays = Date::countMonthDays(2, 2020);
    ASSERT_EQ(numDays, 29);
}

TEST(Date, TestDayCounterNotLeapYear) {
    int numDays = Date::countMonthDays(2, 2022);
    ASSERT_EQ(numDays, 28);
}