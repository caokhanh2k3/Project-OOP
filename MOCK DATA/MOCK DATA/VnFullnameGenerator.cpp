#include "VnFullnameGenerator.h"
#include <vector>
#include <sstream>
#include "IntegerGenerator.h"
#include"String.h"


string VnFullnameGenerator::next()
{
    vector<string> firsts = Utils::String::ReadFile("Firstname.txt");
    vector<string> middles = Utils::String::ReadFile("Middlename.txt");
    vector<string> lasts = Utils::String::ReadFile("Lastname.txt");

 
    int i = -1;

    IntegerGenerator* intGen = IntegerGenerator::instance();
    i = intGen->next(firsts.size());
    string first = firsts[i];

    i = intGen->next(middles.size());
    string middle = middles[i];


    i = intGen->next(lasts.size());
    string last = lasts[i];

    stringstream builder;
    if (middle == "NOMIDDLENAME") // truong hop kho co ten dem
    {
        builder << first <<" "<< last;
    }
    else
    {
        builder << first << " " << middle << " " << last;
    }
   

    string result = builder.str();
    return result;
}