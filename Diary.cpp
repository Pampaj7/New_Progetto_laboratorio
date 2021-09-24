//
// Created by uffa on 14/09/2021.
//

#include <iostream>
#include "Diary.h"

void Diary::addActivities(const Activities &ac) {
    diary.push_back(ac);
}

void Diary::removeActivities(const Activities &ac) {
    diary.remove(ac);
}

std::string Diary::printActivities() const {
    std::string act;
    for (auto itr: diary)
        act += itr.getTitle() + "\n";
    return act;
}

const std::string &Diary::getNameDiary() const {
    return NameDiary;
}

void Diary::setNameDiary(const std::string &nameDiary) {
    NameDiary = nameDiary;
}

int Diary::activitiesCounter() const {
    int i = 0;
    for (auto itr: diary)
        i++;
    return i;
}

void Diary::printAllToDo() const {
    for (auto itr: diary) {
        std::cout << "Per l'attivita' : " << itr.getTitle() << std::endl << "abbiamo i seguenti ToDo : " << std::endl;
        itr.printToDo();
        std::cout << std::endl;
    }
}


void Diary::completedToDo(const std::string &yt) const {
    for (auto itr: diary) {
        itr.completedToDo(yt);
    }
}



