//
// Created by uffa on 14/09/2021.
//


#include <ostream>
#include <iostream>
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

int Date::getMaxDays() const {
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

/*
Date::Date(int d, Months m, int y) : day(d), month(m), year(y) {
   try {
       if (day > getMaxDays())
           throw "Number not allowed";
   }
   catch (const char* messaggio) {
       std::cerr << messaggio << std::endl;
   }

}*/

void Date::setDay(int i) {
    try {
        if (i > getMaxDays())
            throw "Number not allowed!";
    }
    catch (const char *messaggio) {
        std::cerr << messaggio << std::endl;
    }
    Date::day = i;
}

void Date::setYear(int year) {
    Date::year = year;
}

void Date::setMonth(Months month) {
    Date::month = month;
}

bool Date::operator==(const Date &da) const {
    if (day == da.getDay())
        if (year == da.getYear())
            if (month == da.getMonth())
                return true;
    return false;
}





