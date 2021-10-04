//
// Created by uffa on 14/09/2021.
//

#ifndef NEW_PROGETTO_LABORATORIO_DATE_H
#define NEW_PROGETTO_LABORATORIO_DATE_H

#include <ostream>

enum class Months {
    January, February, March, April, May, June, July, August, September, October, November, December
};

class Date {
public:
    // explicit Date( int dayX=1, Months monthsX=Months::January, int yearX=2000);

    Months getMonth() const;

    int getDay() const;

    int getYear() const;

    void setDay(int i);

    void setYear(int i);

    void setMonth(Months months);

    bool operator==(const Date &da) const;

    int getMaxDays() const ;



private:

    int day, year;
    Months month;


};


#endif //NEW_PROGETTO_LABORATORIO_DATE_H
