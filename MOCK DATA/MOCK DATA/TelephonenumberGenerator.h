#pragma once
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<iostream>
#include"String.h"

using namespace std;
class TelephonenumberGenerator;


class TelephonenumberGenerator 
{
public:
    TelephonenumberGenerator();
    string next();
    string next(string);
    void ReadFileTelNumber(vector<string>& MobileNetwork, string filename);
};
