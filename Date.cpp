//
// Created by uffa on 14/09/2021.
//


#include <ostream>
#include "Date.h"


int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

Months Date::getMonth() const {
    return month;
}

int Date::getMaxDays() {
    switch (month) {
        case Months::September:
        case Months::April:
        case Months::June:
        case Months::November:
            return 30;
        case Months::February:
            return 28;
        default:
            return 31;
    }
}

Date::Date(int d, Months m, int y) : day(d), month(m), year(y) {
    if (day > getMaxDays())
        day = 1;
}


Date::~Date() {

}



