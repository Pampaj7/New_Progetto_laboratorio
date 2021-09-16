//
// Created by uffa on 16/09/2021.
//

#include "gtest/gtest.h"
#include "../Activities.h"

class ActivitiesSuite : public ::testing::Test {

protected:
    virtual void SetUp() { //fave
        Date d1(30, Months::May, 1492);
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

TEST_F (ActivitiesSuite, TestSet) {
    ASSERT_EQ("Madagascar", activ.getTitle()); // test che i set precedenti non hanno modificato la suite
}

