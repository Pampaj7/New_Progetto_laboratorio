//
// Created by uffa on 14/09/2021.
//

#ifndef NEW_PROGETTO_LABORATORIO_ACTIVITIES_H
#define NEW_PROGETTO_LABORATORIO_ACTIVITIES_H


#include <list>
#include "ToDo.h"

class Activities {
public:

    explicit Activities(const std::string &title="");
    virtual ~Activities();

    const std::string &getTitle() const;
    void setTitle(const std::string &title);
    void addToDo (const ToDo& aDo);// eccolo
    void removeToDo(const ToDo& aDo);
    void removeLastToDo();
    bool searchToDo(const ToDo& aDo);
    void modToDo(const ToDo& aDo);
    bool operator == (const Activities& ac);
    int countToDo ();


private:
    std::list<ToDo> activities;
    std::string title;

};


#endif //NEW_PROGETTO_LABORATORIO_ACTIVITIES_H
