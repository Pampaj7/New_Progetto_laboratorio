//
// Created by uffa on 14/09/2021.
//

#ifndef NEW_PROGETTO_LABORATORIO_DIARY_H
#define NEW_PROGETTO_LABORATORIO_DIARY_H


#include <list>
#include "Activities.h"

class Diary {
public:

    Diary(const std::string &nameDiary);
    virtual ~Diary() = default;

    void addActivities(const Activities& ac);
    void removeActivities(const Activities& ac);
    std::string stampActivities();

private:
    std::list <Activities> diary;
    std::string NameDiary;
};


#endif //NEW_PROGETTO_LABORATORIO_DIARY_H
