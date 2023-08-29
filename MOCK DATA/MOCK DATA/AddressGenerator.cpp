#include"AddressGenerator.h"



AddressGenerator::AddressGenerator(string province)
{
	_provincename = province;
}
AddressGenerator::AddressGenerator()
{
	_provincename = " ";
}



/// <summary>
/// ham random ra 1 dia chi day du
/// </summary>
/// <returns>so nha + ten duong + ten phuong + ten quan + ten tinh</returns>
string AddressGenerator::next()
{
	vector<string> DISTRICT;
	stringstream builder;
	stringstream builder1;

	string filename;

	for (const auto& file : fs::directory_iterator(_provincename))
	{

		stringstream builder2;
		builder2 << file.path().filename().string();
		string districtname = builder2.str();

		DISTRICT.push_back(districtname);
	}
	auto intGen = IntegerGenerator::instance();
	int r = intGen->next(DISTRICT.size());


	builder1 << _provincename << "\\" << DISTRICT[r];
	filename = builder1.str();


	builder << nextward(filename); 
	builder << ", ";
	builder << DISTRICT[r];
	builder << ", " << _provincename;


	string result = builder.str();
	return result;
}

/// <summary>
/// ham random ra dia chi cua 1 quan
/// </summary>
/// <param name="fname">duong dan den folder cua quan (ten tinh thanh \\ ten quan) </param>
/// <returns>so nha + ten duong + ten phuong</returns>
string AddressGenerator::nextward(string fname)
{
	vector<string> WARD;
	
	stringstream builder;
	stringstream builder1;

	string filename;

	for (const auto& file : fs::directory_iterator(fname))
	{

		stringstream builder2;

		builder2 << file.path().filename().string();

		string wardname = builder2.str();
		WARD.push_back(wardname);
	}
	auto intGen = IntegerGenerator::instance();
	int r = intGen->next(WARD.size());


	builder1 << fname << "\\" << WARD[r];
	filename = builder1.str();




	builder << nextstreet(filename);

	builder << ", ";
	builder << WARD[r];


	string result = builder.str();
	return result;
}
/// <summary>
///  ham random ra dia chi cua 1 phuong
/// </summary>
/// <param name="fname">duong dan den folder cua phuong (ten tinh thanh \\ ten quan \\ ten phuong)</param>
/// <returns>so nha + ten duong </returns>
string AddressGenerator::nextstreet(string fname)
{
	vector<string> STREET;

	stringstream builder;
	stringstream builder1;

	string filename;

	for (const auto& file : fs::directory_iterator(fname))
	{

		stringstream builder2;

		builder2 << file.path().filename().string();

		string wardname = builder2.str();
		STREET.push_back(wardname);
	}
	auto intGen = IntegerGenerator::instance();
	int r = intGen->next(STREET.size());


	builder1 << fname << "\\" << STREET[r];
	filename = builder1.str();


	int Hem = intGen->next(1, 4);
	builder << nexthousenum(Hem) << " ";




	builder << STREET[r];

	string result = builder.str();
	return result;
}

/// <summary>
/// ham random ra so nha cua 1 duong
/// </summary>
/// <param name="Hem">random [1, 4]/ (1: XX), (2: XX/XX), (3: XX/XX/XX), (4: XX/XX/XX/XX) </param>
/// <returns>so nha </returns>
string AddressGenerator::nexthousenum(int Hem)
{
	stringstream builder;
	auto intGen = IntegerGenerator::instance();
	int MaxHouseNumber = 450;
	for (int i = 1; i <= Hem; i++)
	{
		int r = intGen->next(1, MaxHouseNumber / 2);
		builder << r;
		if (i < Hem)
		{
			builder << "/";
		}
	}
	string result = builder.str();
	return result;
}