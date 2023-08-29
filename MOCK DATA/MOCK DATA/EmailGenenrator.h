#pragma once
#include <string>
using namespace std;

class EmailGenerator {
public:
    string next(string fullname);
    string NewEmail(string emailprel);
};
