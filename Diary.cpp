//
// Created by uffa on 14/09/2021.
//

#include <iostream>
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
    for (auto itr: diary)
        act += itr.getTitle() + "\n";
    return act;
}

const std::string &Diary::getNameDiary() const {
    return NameDiary;
}

void Diary::setNameDiary(const std::string &nameDiary) {
    NameDiary = nameDiary; //XXX ecc
}

Diary::Diary() {

}

int Diary::countActivities() {
    int i = 0;
    for (auto itr: diary)
        i++;
    return i;
}

void Diary::stampAllToDo() {
    for (auto itr: diary) {
        std::cout << "Per l'attivita' : " << itr.getTitle() << std::endl << "abbiamo i seguenti ToDo : " << std::endl;
        itr.printToDo();
        std::cout << std::endl;
    }
}

/*
void Diary::removeToDoSelected(const std::string &ws) {
 for (auto itr:diary)
     itr.removeToDoByTitle(ws);
}*/

void Diary::markProgressToDo(const std::string &yt) {
    for (auto itr: diary) {
        itr.completedToDo(yt);
    }
}



