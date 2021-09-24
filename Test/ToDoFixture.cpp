//
// Created by uffa on 16/09/2021.
//


#include "gtest/gtest.h"
#include "../ToDo.h"

class ToDoSuite : public::testing::Test {
protected:
    virtual void SetUp() {

        to.setProgress(false);
        to.setData(d1);
        to.setTitle("spade laser");
        to.setPriority(2);
        d1.setDay(5);
        d1.setMonth(Months::May);
        d1.setYear(2341);
    }
    ToDo to;
    Date d1;
};

TEST_F (ToDoSuite, TestConstructor) {
    ASSERT_EQ(false, to.isProgress());
    ASSERT_EQ("spade laser", to.getTitle());
    ASSERT_EQ(2, to.getPriority());
}

TEST_F(ToDoSuite, TestProgress) {
    to.makeProgress();
    ASSERT_EQ(true, to.isProgress());
}