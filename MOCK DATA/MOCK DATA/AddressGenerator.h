#pragma once
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<fstream>
#include <filesystem>
#include"IntegerGenerator.h"

using namespace std;
namespace fs = filesystem;


class AddressGenerator;
class FakeHouseNumber;



class AddressGenerator
{
private:
	
	string _provincename;

public:
	AddressGenerator();
	AddressGenerator(string province);
	string getprovince() { return _provincename; }
	
	string next();
	string nextward(string fname);
	string nextstreet(string fname);
	
	string nexthousenum(int Hem);
	 
};

