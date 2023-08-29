#include "BirthdayGenerator.h"
#include "IntegerGenerator.h"


Date BirthdayGenerator::next() {
    const int MAX_AGE = 118; // guiness
    auto intGen = IntegerGenerator::instance();

    int age = intGen->next(MAX_AGE * 10);
    if (age > MAX_AGE*7 && age <MAX_AGE*9) // nam sinh 2003 chiem 20%
    {
        age = 103;
    }
    else if (age > MAX_AGE * 9)// nam sinh 2002 chiem 10%
    {
        age = 102;
    }
    else if (age > MAX_AGE  && age < MAX_AGE *7)// nam sinh 2004 chiem 60%
    {
        age = 104;
    }
    
    // cac nam sinh con lai chiem 10%
    int year = 1900 + age;




    int month = intGen->next(1, 12);
    auto maxDaysInMonth = Date::maxDaysInMonth(year);
    int day = intGen->next(1, maxDaysInMonth[month]);

    Date result(day, month, year);
    return result;
}