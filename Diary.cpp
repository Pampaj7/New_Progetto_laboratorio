//
// Created by uffa on 14/09/2021.
//

#include "Diary.h"

Diary::Diary(const std::string &nameDiary) : NameDiary(nameDiary) {}



void Diary::addActivities(const Activities &ac) {
    diary.push_back(ac);
}

void Diary::removeActivities(const Activities &ac) {
    diary.remove(ac);
}

std::string Diary::stampActivities() {
    std::string act;
    for (auto itr:diary)
        act += itr.getTitle() + "\n";
    return act;
}

const std::string &Diary::getNameDiary() const {
    return NameDiary;
}

void Diary::setNameDiary(const std::string &nameDiary) {
    NameDiary = nameDiary;
}

Diary::Diary() {

}

int Diary::countActivities() {
    int i=0;
    for (auto itr:diary)
        i++;
    return i;
}
