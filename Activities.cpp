//
// Created by uffa on 14/09/2021.
//

#include <iostream>
#include "Activities.h"



const std::string &Activities::getTitle() const {
    return title;
}

void Activities::setTitle(const std::string &basicString) {
    Activities::title = basicString;
}

void Activities::addToDo(const ToDo &aDo) {
    activities.push_back(aDo);
}

void Activities::removeToDo(const ToDo &aDo) {
    activities.remove(aDo);
}

bool Activities::searchToDo(const ToDo &aDo) const {
    for (auto itr: activities) {
        if (itr.getTitle() == aDo.getTitle())
            return true;
    }
    return false;
}

bool Activities::operator==(const Activities &ac) const  {
    if (title == ac.title)
        return true;
    return false;
}

int Activities::countToDo() const {
    int i=0;
    for (auto itr:activities)
        i++;
    return i;
}

void Activities::removeLastToDo() {
    ToDo a;
    for (auto itr:activities) {
        a = itr;
    }
    activities.remove(a);
}

void Activities::printToDo() const {
    for (auto itr: activities)
        std::cout << itr.getTitle() << " con stato: " << itr.isProgress() << std::endl;
}


void Activities::completedToDo(const std::string &ui) const  {
    for (auto itr:activities) {
        if (ui == itr.getTitle())
            itr.setProgress(true);
    }
}

ToDo Activities::searchToDoAndGiveIt(const std::string &rt) const {
    for (auto itr:activities)
        if (rt == itr.getTitle())
            return itr;
}

