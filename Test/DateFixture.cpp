//
// Created by uffa on 17/09/2021.
//



#include "gtest/gtest.h"
#include "../Date.h"



class DateSuite : public ::testing::Test {
protected:
    virtual void SetUp() {
        dd.setDay(1);
        dd.setMonth(Months::June);
        dd.setYear(1948);
    }

    Date dd;
};

TEST_F(DateSuite, ConstructorTest) {
    ASSERT_EQ(1, dd.getDay());
    ASSERT_EQ(Months::June, dd.getMonth());
    ASSERT_EQ(1948, dd.getYear());
    dd.setDay(2);
    dd.setMonth(Months::August);
    dd.setYear(2019);
    ASSERT_EQ(2, dd.getDay());
    ASSERT_EQ(Months::August, dd.getMonth());
    ASSERT_EQ(2019, dd.getYear());
    dd.setDay(2);
    ASSERT_EQ(dd.getDay(), 2);

    Date d6;
    d6.setDay(31);
    d6.setMonth(Months::December);
    d6.setYear(1999);

    try {
        d6.setDay(467);
        FAIL() << "Expected std::out_of_range";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(), std::string("OUT OF RANGE! YOUR DAY IS NOT ALLOWED!"));
    }

    ASSERT_EQ(d6.getDay(), 31); // controllato che non sia stato cambiato il giorno

    try {
        d6.setMonth(Months::April);     // avendo come giorno impostato il 31, aprile non è disponibile
        FAIL() << "Expected std::out_of_range";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(), std::string("OUT OF RANGE! THIS MONTH CAN'T BE SETTED!"));
        // eccezione generata confermata
    }

    ASSERT_EQ(d6.getMonth(), Months::December); //controllato che non sia stato cambiato il messe

    try {
        d6.setYear(345678);
        FAIL() << "Expected std::out_of_range";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(), std::string("OUT OF RANGE! YEAR TOO FAR!"));
    }

    ASSERT_EQ(d6.getYear(), 1999); //controllato che non sia stato cambiato l'anno

}

TEST_F(DateSuite, leapYearTest) {
    Date dp;
    dp.setDay(28);
    dp.setMonth(Months::February);
    dp.setYear(2001); //non bisestile

    try {
        dp.setDay(29);
        FAIL() << "Expected std::out_of_range";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(), std::string("OUT OF RANGE! YOUR DAY IS NOT ALLOWED!"));
    }

    ASSERT_EQ(28, dp.getDay());

    dp.setYear(2000); // il 2000 è un anno bisestile
    dp.setDay(29); // ora è possibile dato che il 2000 è bisestile
    ASSERT_EQ(2000, dp.getYear());
    ASSERT_EQ(29, dp.getDay());
    ASSERT_EQ(Months::February, dp.getMonth());

    try {
        dp.setYear(2001); //non bisestile con data precedente 29
        FAIL() << "Expected std::out_of_range";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(), std::string("OUT OF RANGE! NOT LEAP YEAR!"));
    }

    ASSERT_EQ(2000, dp.getYear()); //controllato che l'anno non sia stato assegnato


    dp.setDay(28);
    dp.setYear(1700); //non bisestile

    try {
        dp.setDay(29);
        FAIL() << "Expected std::out_of_range";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(), std::string("OUT OF RANGE! YOUR DAY IS NOT ALLOWED!"));
    }

    ASSERT_EQ(28, dp.getDay());
    ASSERT_EQ(Months::February, dp.getMonth());
    ASSERT_EQ(1700, dp.getYear());
}