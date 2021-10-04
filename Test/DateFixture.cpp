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

    EXPECT_THROW(d6.setDay(467), std::out_of_range);
    ASSERT_EQ(d6.getDay(), 31); // controllato che non sia stato cambiato il giorno

    EXPECT_THROW(d6.setMonth(Months::April), std::out_of_range);
    ASSERT_EQ(d6.getMonth(), Months::December); //controllato che non sia stato cambiato il messe

    EXPECT_THROW(d6.setYear(34678), std::out_of_range);
    ASSERT_EQ(d6.getYear(), 1999); //controllato che non sia stato cambiato l'anno

}

TEST_F(DateSuite, leapYearTest) {
    Date dp;
    dp.setDay(28);
    dp.setMonth(Months::February);
    dp.setYear(2001); //non bisestile

    EXPECT_THROW(dp.setDay(29), std::out_of_range);
    ASSERT_EQ(28, dp.getDay());

    dp.setYear(2000); // il 2000 è un anno bisestile
    dp.setDay(29); // ora è possibile dato che il 2000 è bisestile
    ASSERT_EQ(2000, dp.getYear());
    ASSERT_EQ(29, dp.getDay());
    ASSERT_EQ(Months::February, dp.getMonth());

    EXPECT_THROW(dp.setYear(2001), std::out_of_range);
    ASSERT_EQ(2000, dp.getYear()); //controllato che l'anno non sia stato assegnato

    dp.setDay(28);
    dp.setYear(1700); //non bisestile

    EXPECT_THROW(dp.setDay(29), std::out_of_range);
    ASSERT_EQ(28, dp.getDay());
    ASSERT_EQ(Months::February, dp.getMonth());
    ASSERT_EQ(1700, dp.getYear());

    EXPECT_THROW(dp.setDay(346), std::out_of_range );

}