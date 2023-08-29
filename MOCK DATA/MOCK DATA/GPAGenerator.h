#pragma once
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<iostream>

#include"IntegerGenerator.h"
using namespace std;

class GPA;

class GPAGenerator
{
private:
	double _Gpa;
public:
	GPAGenerator();
	double GetGPA();
};
GPAGenerator::GPAGenerator()
{
	_Gpa = 0;
}

double GPAGenerator::GetGPA()
{
	auto intGen = IntegerGenerator::instance();
	double Gpa = double(intGen->next(40)) / 10; //[0 - 4.0]
	_Gpa = Gpa;
	return _Gpa;
}