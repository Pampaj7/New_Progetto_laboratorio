//
// Created by uffa on 16/09/2021.
//

#include "gtest/gtest.h"
#include "../Activities.h"

class ActivitiesSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        Date d1;
        d1.setDay(30);
        d1.setMonth(Months::May);
        d1.setYear(1492);
        ToDo doSom(false, "some", 4, d1);
        ToDo aDo(false, "aa", 7, d1);
        activ.addToDo(doSom);
        activ.addToDo(aDo);
        activ.setTitle("Madagascar");
    }

    Activities activ;
};

TEST_F (ActivitiesSuite, Constructor) {
    ASSERT_EQ("Madagascar", activ.getTitle());
    activ.setTitle("epp");
    ASSERT_EQ("epp", activ.getTitle());
    ASSERT_EQ(activ.getTitle(), activ.getTitle());
    activ.setTitle((""));
    ASSERT_EQ("", activ.getTitle());
    activ.setTitle("!£$");
    ASSERT_EQ("!£$", activ.getTitle());
}


TEST_F(ActivitiesSuite, TestNumberElements) {
    ASSERT_EQ(2, activ.countToDo());
    activ.removeLastToDo();
    ASSERT_EQ(1, activ.countToDo());
    activ.removeLastToDo();
    ASSERT_EQ(0, activ.countToDo());
    Date d0;
    d0.setDay(20);
    d0.setMonth(Months::May);
    d0.setYear(1253);
    ToDo xDo(false, "yy", 3, d0);
    activ.addToDo(xDo);
    ASSERT_EQ(1, activ.countToDo());
    activ.removeToDo(xDo);
    ASSERT_EQ(0, activ.countToDo());

    ToDo xDone(false, "test", 7, d0);
    activ.addToDo(xDone);
    ASSERT_EQ(1, activ.countToDo());
    //ToDo testTaken = activ.searchToDoAndGiveIt("test");
   // ASSERT_EQ(xDone, testTaken);
} //+search resa todo + eccezione !!!SFGHTSHTSDHSHT

TEST_F(ActivitiesSuite, TestSearchElements) {
    Date d0;
    d0.setDay(20);
    d0.setMonth(Months::May);
    d0.setYear(1253);
    ToDo xDo(false, "yy", 3, d0);
    activ.addToDo(xDo);
    ASSERT_EQ(true, activ.searchToDo(xDo));
    ASSERT_EQ(activ.countToDo(), 3);
    activ.removeToDo(xDo);
    ASSERT_EQ(false, activ.searchToDo(xDo));
    ASSERT_EQ(activ.countToDo(), 2);
}

