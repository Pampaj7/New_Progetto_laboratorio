//
// Created by uffa on 14/09/2021.
//

#ifndef NEW_PROGETTO_LABORATORIO_ACTIVITIES_H
#define NEW_PROGETTO_LABORATORIO_ACTIVITIES_H


#include <list>
#include "ToDo.h"

class Activities {
public:

    explicit Activities(const std::string &title = "");


    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    void addToDo(const ToDo &aDo);
    void removeToDo(const ToDo &aDo);

    //void removeToDoByTitle(const std::string& op);
    void removeLastToDo();

    bool searchToDo(const ToDo &aDo) const ; //+ resa todo occ + test const

    //void modToDo(const T& aDo);
    bool operator==(const Activities &ac) const;

    int countToDo() const ;

    void printToDo() const;

    void completedToDo(const std::string &ui) const ;


private:
    std::list<ToDo> activities;
    std::string title;

};


#endif //NEW_PROGETTO_LABORATORIO_ACTIVITIES_H
