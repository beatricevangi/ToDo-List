//
// Created by beatrice on 29/06/22.
//

#include "gtest/gtest.h"

#include "../ToDoList.h"

class ToDoListSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        toDoList.clearAll();
        Item k1("TestA", 11, 11, 2022);
        toDoList.insertItem(k1);
    }

    ToDoList toDoList;
};

TEST_F(ToDoListSuite, TestInsert){
    EXPECT_EQ(1, toDoList.getList().size());
    Item k("primo impegno", 11, 11, 2022);
    toDoList.insertItem(k);
    ASSERT_LT(1, toDoList.getList().size());
}

TEST_F(ToDoListSuite, TestDeletion){
    EXPECT_EQ(1, toDoList.getList().size());
    auto item = toDoList.getItem(1);
    toDoList.deleteItem(*item);
    ASSERT_GT(1, toDoList.getList().size());
}

TEST_F(ToDoListSuite, TestClearAll){
    Item i("TestB", 12, 11, 2022);
    toDoList.insertItem(i);
    EXPECT_EQ(2, toDoList.getList().size());
    toDoList.clearAll();
    EXPECT_EQ(0, toDoList.getList().size());
}

TEST_F(ToDoListSuite, TestInvalidInput){
    EXPECT_EQ(1, toDoList.getList().size());
    EXPECT_THROW(toDoList.getItem(1000), std::runtime_error);
}
