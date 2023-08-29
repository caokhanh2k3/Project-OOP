#include "StudentIdGenerator.h"

#include <sstream>

#include "IntegerGenerator.h"
#include "Major.h"
#include "Date.h"

StudentIdGenerator::StudentIdGenerator() 
{
  
}

string StudentIdGenerator::next() {
    const int year = Date::Now().year();
    //const int year = 2021;
    const int major = Major::IT;

    string result = next(year, major);
    return result;
}

/// <summary>
/// Phat sinh MSSV
/// </summary>
/// <param name="year">Nam hoc</param>
/// <param name="major">Chuyen nganh</param>
/// <returns>MSSV dang XXYYAAAA. XX: Nam hoc, YY: Chuyen nanh, AAAA: STT</returns>
string StudentIdGenerator::next(int year, int major) {
    stringstream builder;
    builder << year % 100 << major;

    auto intGen = IntegerGenerator::instance();

    for (int i = 1; i <= 4; i++) {
        int digit = intGen->next(10); // [0-9]
        builder << digit;
    }

    string result = builder.str();
    return result;
}