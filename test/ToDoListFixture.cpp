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
    EXPECT_EQ(1, toDoList.countItems());
    EXPECT_EQ(1, toDoList.countItemsToBeDone());
    Item i("TestB", 11, 11, 2022);
    i.setDone(true);
    toDoList.insertItem(i);
    ASSERT_LT(1, toDoList.countItems());
    ASSERT_EQ(1, toDoList.countItemsToBeDone());
}


TEST_F(ToDoListSuite, TestDeletion){
    EXPECT_EQ(1, toDoList.countItems());
    toDoList.deleteItem(*toDoList.getItem(1));
    ASSERT_GT(1, toDoList.countItems());
}


TEST_F(ToDoListSuite, TestToggle){
    EXPECT_EQ(false,toDoList.getItem(1)->isDone());
    toDoList.toggle(*toDoList.getItem(1));
    ASSERT_EQ(true,toDoList.getItem(1)->isDone());

}


TEST_F(ToDoListSuite, TestClearAll){
    Item i("TestB", 12, 11, 2022);
    toDoList.insertItem(i);
    EXPECT_EQ(2, toDoList.countItems());
    toDoList.clearAll();
    EXPECT_EQ(0, toDoList.countItems());
}


TEST_F(ToDoListSuite, TestInvalidInput){
    EXPECT_EQ(1, toDoList.countItems());
    EXPECT_THROW(toDoList.getItem(1000), std::runtime_error);
}
