//
// Created by uffa on 14/09/2021.
//

#ifndef NEW_PROGETTO_LABORATORIO_DIARY_H
#define NEW_PROGETTO_LABORATORIO_DIARY_H


#include <list>
#include "Activities.h"

class Diary {
public:

    explicit Diary(const std::string &nameDiary);
    virtual ~Diary() = default;
    Diary();
    void addActivities(const Activities& ac); //V
    void removeActivities(const Activities& ac);//V

    std::string stampActivities();

    const std::string &getNameDiary() const;

    void setNameDiary(const std::string &nameDiary);
    int countActivities ();

private:
    std::list <Activities> diary;
    std::string NameDiary;
};


#endif //NEW_PROGETTO_LABORATORIO_DIARY_H
