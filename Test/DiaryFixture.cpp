//
// Created by uffa on 16/09/2021.
//
#include "gtest/gtest.h"
#include "../Diary.h"

class DiarySuite : public::testing::Test {
protected:
    virtual void SetUp() {
        d.setNameDiary("Pablo");
    }
    Diary d;
};


TEST_F (DiarySuite, TestConstructor) {
    ASSERT_EQ("Pablo", d.getNameDiary());
}

TEST_F(DiarySuite, TestEmptyness) {
    ASSERT_EQ(d.countActivities(), 0);
}

TEST_F(DiarySuite, TestNumberElements) {
    Activities ac("sport");
    d.addActivities(ac);
    ASSERT_EQ(d.countActivities(), 1);
    Activities ad("jogging");
    d.addActivities(ad);
    ASSERT_EQ(d.countActivities(), 2);
    d.removeActivities(ac);
    ASSERT_EQ(d.countActivities(), 1);
    d.removeActivities(ad);
    ASSERT_EQ(d.countActivities(), 0);
}

TEST_F(DiarySuite, TestStampActivities) {
    Activities ar("eppp");
    d.addActivities(ar);
    ASSERT_EQ("eppp\n", d.stampActivities());
}