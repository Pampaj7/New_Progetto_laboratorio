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
