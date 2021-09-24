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
        ToDo doSom;
        doSom.setTitle("some");
        doSom.setProgress(false);
        doSom.setData(d1);
        doSom.setPriority(4);
        ToDo aDo;
        aDo.setPriority(7);
        aDo.setData(d1);
        aDo.setProgress(false);
        aDo.setTitle("aa");
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
    ASSERT_EQ(2, activ.ToDoCounter());
    activ.removeLastToDo();
    ASSERT_EQ(1, activ.ToDoCounter());
    activ.removeLastToDo();
    ASSERT_EQ(0, activ.ToDoCounter());
    Date d0;
    d0.setDay(20);
    d0.setMonth(Months::May);
    d0.setYear(1253);
    ToDo xDo;
    xDo.setProgress(false);
    xDo.setTitle("yy");
    xDo.setData(d0);
    xDo.setPriority(3);
    activ.addToDo(xDo);
    ASSERT_EQ(1, activ.ToDoCounter());
    activ.removeToDo(xDo);
    ASSERT_EQ(0, activ.ToDoCounter());
    ToDo xDone;
    xDone.setPriority(7);
    xDone.setData(d0);
    xDone.setTitle("test");
    xDone.setProgress(false);
    activ.addToDo(xDone);
    ASSERT_EQ(1, activ.ToDoCounter());
}

TEST_F(ActivitiesSuite, TestSearchElements) {
    Date d0;
    d0.setDay(20);
    d0.setMonth(Months::May);
    d0.setYear(1253);
    ToDo xDo;
    xDo.setProgress(false);
    xDo.setTitle("yy");
    xDo.setData(d0);
    xDo.setPriority(3);
    activ.addToDo(xDo);
    ASSERT_EQ(true, activ.searchToDo(xDo));
    ASSERT_EQ(activ.ToDoCounter(), 3);
    activ.removeToDo(xDo);
    ASSERT_EQ(false, activ.searchToDo(xDo));
    ASSERT_EQ(activ.ToDoCounter(), 2);

    ////// Aggiunto test nuovo search
    ToDo lof;
    lof.setProgress(false);
    lof.setData(d0);
    lof.setPriority(2);
    lof.setTitle("we");
    activ.addToDo(lof);
    ASSERT_EQ(activ.searchToDoByTitle("we").getTitle(), "we");
    ASSERT_EQ(activ.searchToDoByTitle("we").isProgress(), false);
    ASSERT_EQ(activ.searchToDoByTitle("we").getPriority(), 2);
    ASSERT_EQ(activ.searchToDoByTitle("we").getData(), d0);

}

