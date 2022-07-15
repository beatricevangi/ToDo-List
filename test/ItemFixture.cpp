//
// Created by beatrice on 29/06/22.
//

#include "gtest/gtest.h"

#include "../Item.h"

class ItemSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        i.editDate(18, 7, 2022);
        i.editName("Pizza");
    }
    Item i;
};


TEST_F(ItemSuite, Constructor) {
    ASSERT_EQ("Pizza", i.getName());
    ASSERT_EQ(18, i.getDate().getDay());
    ASSERT_EQ(7, i.getDate().getMonth());
    ASSERT_EQ(2022, i.getDate().getYear());
    ASSERT_FALSE(i.isDone());
}


TEST_F(ItemSuite, TestSetterCompleted) {
    i.setDone(true);
    ASSERT_TRUE(i.isDone());
}


TEST_F(ItemSuite, TestEditDate) {
    i.editDate(28, 7, 2021);
    ASSERT_EQ(28, i.getDate().getDay());
    ASSERT_EQ(7, i.getDate().getMonth());
    ASSERT_EQ(2021, i.getDate().getYear());
}


TEST_F(ItemSuite, TestEditName) {
    i.editName("Grigliata");
    ASSERT_EQ("Grigliata", i.getName());
}