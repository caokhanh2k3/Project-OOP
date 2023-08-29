#pragma once
#include <string>
using namespace std;

class StudentIdGenerator {
public:
    StudentIdGenerator();
    string next();
    string next(int, int);
};