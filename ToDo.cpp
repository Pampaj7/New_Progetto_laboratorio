//
// Created by uffa on 14/09/2021.
//

#include "ToDo.h"

bool ToDo::isProgress() const {
    return progress;
}

void ToDo::setProgress(bool progress) {
    ToDo::progress = progress;
}

const std::string &ToDo::getTitle() const {
    return Title;
}

void ToDo::setTitle(const std::string &activity) {
    ToDo::Title = activity;
}

int ToDo::getPriority() const {
    return priority;
}

void ToDo::setPriority(int priority) {
    ToDo::priority = priority;
}

const Date &ToDo::getData() const {
    return data;
}

void ToDo::setData(const Date &data) {
    ToDo::data = data;
}


bool ToDo::operator==(const ToDo &todo) const {
    if (todo.Title == Title)
        if (todo.progress == progress)
            if (todo.priority == priority)
                return true;
    return false;
}

void ToDo::makeProgress() {
    progress = true;
}

