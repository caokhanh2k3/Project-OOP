#include "EmailGenenrator.h"
#include <vector>
#include <sstream>
#include "String.h"
#include"IntegerGenerator.h"

string EmailGenerator::next(string fullname) {
    stringstream builder;
    const string SEPARATOR = " ";

    vector<string> tokens = Utils::String::split(fullname, SEPARATOR);
    // Chua tinh middle rong! / 2 hoac 3 tu tro len
    if (tokens.size() == 2)
    {
        builder << tokens[0][0] << tokens[1];
    }
    else if (tokens.size() == 3)
    {
        builder << tokens[0][0] << tokens[1][0] << tokens[2];
    }
    else if (tokens.size() == 4)
    {
        builder << tokens[0][0] << tokens[1][0] << tokens[2][0] << tokens[3];
    }
    


    vector<string> Domain = Utils::String::ReadFile("Domain.txt");
    auto intGen = IntegerGenerator::instance();
    int i = intGen->next(Domain.size());
    string Domainemail = Domain[i];
    builder << Domainemail;



    string result = builder.str();
    return result;
}



/// <summary>
/// ham tao moi 1 email khi co 2 email trung nhau.
/// vd:
/// Nguyen Huu Huy => NHHuy + @ + domain.
/// Nguyen Hoai Huy =>NHHuy+ XX + @ +  domain.
/// </summary> 
/// <param name="Emailpre"></param>
/// <returns>1 dia chi email moi </returns>
string EmailGenerator::NewEmail(string Emailpre)
{
    stringstream builder;
    auto intGen = IntegerGenerator::instance();
    int i = intGen->next(1000);
    builder << Emailpre << i;

    string result = builder.str();
    return result;
}