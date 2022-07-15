//
// Created by beatrice on 29/06/22.
//

#include "gtest/gtest.h"

#include "../Date.h"

TEST(Date, Constructor) {
    Date d(3, 6, 2022);
    ASSERT_EQ(3, d.getDay());
    ASSERT_EQ(6, d.getMonth());
    ASSERT_EQ(2022, d.getYear());
}

TEST(Date, TestInvalidDate) {
    Date d(3, 6, 2022);
    EXPECT_THROW(d.setDate(31, 6, 2022), std::runtime_error);
}

TEST(Date, TestValidDate) {
    Date d(3, 6, 2022);
    EXPECT_NO_THROW(d.setDate(31, 7, 2022));
    ASSERT_EQ(31, d.getDay());
    ASSERT_EQ(7, d.getMonth());
    ASSERT_EQ(2022, d.getYear());
}