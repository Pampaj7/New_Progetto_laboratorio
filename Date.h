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

    explicit Date( int dayX=1, Months monthsX=Months::January, int yearX=2000); //c0'tor
    virtual ~Date();

    Months getMonth() const;
    int getDay() const;
    int getYear() const;

    void setDay(int day);

    void setYear(int year);

    void setMonth(Months month);

    bool operator == (const Date& da);
private:

    int day, year;
    Months month;
    int getMaxDays();
};


#endif //NEW_PROGETTO_LABORATORIO_DATE_H
