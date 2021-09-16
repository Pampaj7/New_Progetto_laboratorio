//
// Created by uffa on 16/09/2021.
//



#include "gtest/gtest.h"
#include "../Date.h"

class DateSuite : public ::testing::Test{
protected:
    virtual void SetUp() {
        dd.setDay(1);
        dd.setMonth(Months::June);
        dd.setYear(1948);
    }
    Date dd;
};

TEST_F(DateSuite, ConstructorTest) {
    ASSERT_EQ(1, dd.getDay());
    ASSERT_EQ(Months::June, dd.getMonth());
    ASSERT_EQ(1948, dd.getYear());
    dd.setDay(2);
    dd.setMonth(Months::August);
    dd.setYear(2019);
    ASSERT_EQ(2, dd.getDay());
    ASSERT_EQ(Months::August, dd.getMonth());
    ASSERT_EQ(2019, dd.getYear());
}

