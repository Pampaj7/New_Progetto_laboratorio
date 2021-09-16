//
// Created by uffa on 16/09/2021.
//


#include "gtest/gtest.h"
#include "../ToDo.h"

class ToDoSuite : public::testing::Test {
protected:
    virtual void SetUp() {
        Date d1(5, Months::October, 2730);
        to.setProgress(false);
        to.setData(d1);
        to.setTitle("spade laser");
        to.setPriority(2);
    }
    ToDo to;
};

TEST_F (ToDoSuite, TestConstructor) {
    Date d1(5, Months::October, 2730);
    ASSERT_EQ(false, to.isProgress());
    ASSERT_EQ(d1, to.getData()); //TODO errore
    ASSERT_EQ("spade laser", to.getTitle());
    ASSERT_EQ(2, to.getPriority());
}

TEST_F(ToDoSuite, TestProgress) {
    to.makeProgeress();
    ASSERT_EQ(true, to.isProgress());
}