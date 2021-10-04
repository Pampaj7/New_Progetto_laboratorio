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

int Date::getMaxDays() const { //dipenderà da bisestile o meno
    switch (month) {
        case Months::September:
        case Months::April:
        case Months::June:
        case Months::November:
            return 30;
        case Months::February: {
            if (year % 4 == 0) {
                if (year % 100 == 0) {
                    if (year % 400 == 0)
                        return 29;
                    else
                        return 28;
                } else
                    return 29;
            } else
                return 28;
        }
        default:
            return 31;
    }
}

/*
Date::Date(int d, Months m, int y) : day(d), month(m), year(y) {
   try {
       if (day > getMaxDays())
           throw "Number not allowed";+
   }
   catch (const char* messaggio) {
       std::cerr << messaggio << std::endl;
   }

}*/

void Date::setDay(int i) {

    if (i > getMaxDays())
        throw std::out_of_range("OUT OF RANGE! YOUR DAY IS NOT ALLOWED!");

    Date::day = i;
}

void Date::setYear(int i) {
/*
    if (day == 29) {
        if (i % 4 == 0) {
            if (i % 100 == 0) {
                if (i % 400 == 0)
                    Date::year = i;
                else
                    throw std::out_of_range("OUT OF RANGE! NOT LEAP YEAR!");
            } else
                Date::year = i;
        } else
            throw std::out_of_range("OUT OF RANGE! NOT LEAP YEAR!");
    } */

    int yearnow = year;
    Date::year = i;

    if (day == 29 && getMaxDays() == 28 || i > 4000) {
        Date::year = yearnow;
        throw std::out_of_range("OUT OF RANGE! NOT LEAP YEAR!");
    }


}

void Date::setMonth(Months months) {

    Months mon = getMonth();
    Date::month = months;

    if (getDay() > getMaxDays()) {
        month = mon;
        throw std::out_of_range("OUT OF RANGE! THIS MONTH CAN'T BE SETTED!");
    }

}

bool Date::operator==(const Date &da) const {
    if (day == da.getDay())
        if (year == da.getYear())
            if (month == da.getMonth())
                return true;
    return false;
}






