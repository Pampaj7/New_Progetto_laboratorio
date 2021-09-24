//
// Created by uffa on 14/09/2021.
//

#ifndef NEW_PROGETTO_LABORATORIO_DIARY_H
#define NEW_PROGETTO_LABORATORIO_DIARY_H


#include <list>
#include "Activities.h"

class Diary {
public:


    void addActivities(const Activities &ac);

    void removeActivities(const Activities &ac);

    std::string printActivities() const;

    void printAllToDo() const;

    void completedToDo(std::string const &yt) const;

    const std::string &getNameDiary() const;

    void setNameDiary(const std::string &nameDiary);

    int activitiesCounter() const;


private:
    std::list<Activities> diary;
    std::string NameDiary;
};


#endif //NEW_PROGETTO_LABORATORIO_DIARY_H
