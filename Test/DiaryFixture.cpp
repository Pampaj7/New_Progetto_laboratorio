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
    d.setNameDiary("rapp");
    ASSERT_EQ("rapp", d.getNameDiary());
    d.setNameDiary("!£$%&");
    ASSERT_EQ("!£$%&", d.getNameDiary());
    d.setNameDiary("");
    ASSERT_EQ("", d.getNameDiary());
}

TEST_F(DiarySuite, TestEmptyness) {
    ASSERT_EQ(d.activitiesCounter(), 0);
}

TEST_F(DiarySuite, TestNumberElements) {
    Activities ac;
    ac.setTitle("sport");
    d.addActivities(ac);
    ASSERT_EQ(d.activitiesCounter(), 1);
    Activities ad;
    ad.setTitle("jogging");
    d.addActivities(ad);
    ASSERT_EQ(d.activitiesCounter(), 2);
    d.removeActivities(ac);
    ASSERT_EQ(d.activitiesCounter(), 1);
    d.removeActivities(ad);
    ASSERT_EQ(d.activitiesCounter(), 0);
}

TEST_F(DiarySuite, TestPrintActivities) {
    Activities ar;
    ar.setTitle("eppp");
    d.addActivities(ar);
    ASSERT_EQ("eppp\n", d.printActivities());
}