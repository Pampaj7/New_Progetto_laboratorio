//
// Created by uffa on 14/09/2021.
//

#ifndef NEW_PROGETTO_LABORATORIO_TODO_H
#define NEW_PROGETTO_LABORATORIO_TODO_H


#include <string>
#include "Date.h"

class ToDo {
public:


    bool isProgress() const;

    void setProgress(bool progress);

    const std::string &getTitle() const;

    void setTitle(const std::string &activity);

    int getPriority() const;

    void setPriority(int priority);

    const Date &getData() const;

    void setData(const Date &data);

    bool operator==(const ToDo &todo) const;

    void makeProgress();


private:
    bool progress;
    std::string Title;
    int priority;
    Date data;
};


#endif //NEW_PROGETTO_LABORATORIO_TODO_H
