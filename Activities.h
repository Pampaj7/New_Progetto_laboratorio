//
// Created by uffa on 14/09/2021.
//

#ifndef NEW_PROGETTO_LABORATORIO_ACTIVITIES_H
#define NEW_PROGETTO_LABORATORIO_ACTIVITIES_H


#include <list>
#include "ToDo.h"

class Activities {
public:

    const std::string &getTitle() const;
    void setTitle(const std::string &basicString);

    void addToDo(const ToDo &aDo);
    void removeToDo(const ToDo &aDo);
    void removeLastToDo();
    bool searchToDo(const ToDo &aDo) const ;

    ToDo searchToDoAndGiveIt(const std::string &rt) const; //TODO FIX IT

    bool operator==(const Activities &ac) const;

    int ToDoCounter() const ;
    void printToDo() const;
    void completedToDo(const std::string &ui) const ;


private:
    std::list<ToDo> activities;
    std::string title;

};


#endif //NEW_PROGETTO_LABORATORIO_ACTIVITIES_H
