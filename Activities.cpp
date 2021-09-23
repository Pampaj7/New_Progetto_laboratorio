//
// Created by uffa on 14/09/2021.
//

#include <iostream>
#include "Activities.h"

Activities::~Activities() {

}

Activities::Activities(const std::string &title) : title(title) {}

const std::string &Activities::getTitle() const {
    return title;
}

void Activities::setTitle(const std::string &title) {
    Activities::title = title;
}

void Activities::addToDo(const ToDo &aDo) {
    activities.push_back(aDo);
}

void Activities::removeToDo(const ToDo &aDo) {
    activities.remove(aDo);
}

bool Activities::searchToDo(const ToDo &aDo) {
    for (auto itr: activities) {
        if (itr.getTitle() == aDo.getTitle())
            return true;
    }
    return false;
}

/*void Activities::modToDo(const ToDo &aDo) {
    std::string choice;
    std::string titleX;
    for (auto itr: activities) {
        if (itr.getTitle() == aDo.getTitle()) {
            std::cout << "Vuoi cambiare il titolo dell'attività? si o no?" << std::endl;
            std::cin >> choice;
            if (choice == "si") {
                std::cout << "Immetti il nuovo titolo" << std::endl;
                std::cin >> titleX;
                itr.setTitle(titleX);
            }
        }
    }

}*/

bool Activities::operator==(const Activities &ac) {
    if (title == ac.title)
        return true;
    return false;
}

int Activities::countToDo() {
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

void Activities::stampToDo() {
    for (auto itr: activities)
        std::cout << itr.getTitle() << " con stato: " << itr.isProgress() << std::endl;
}

/*void Activities::removeToDoByTitle(const std::string &op) {
    for (auto itr:activities) {
        if (op == itr.getTitle())
            activities.remove(itr);
    }
}*/

void Activities::changeProgress(const std::string &ui) {
    for (auto itr:activities) {
        if (ui == itr.getTitle())
            itr.setProgress(true);
    }
}

