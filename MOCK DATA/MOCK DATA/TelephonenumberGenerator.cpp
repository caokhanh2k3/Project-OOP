#include"TelephonenumberGenerator.h"
#include"String.h"
#include"IntegerGenerator.h"



TelephonenumberGenerator::TelephonenumberGenerator()
{

}
string TelephonenumberGenerator::next()
{
    vector<string> MobileNetwork;
    auto intGen = IntegerGenerator::instance();

    ReadFileTelNumber(MobileNetwork, "HeaderNumberMobileNetwork.txt");
    int r = intGen->next(MobileNetwork.size());// [0- ]

    string HeaderNumberMobileNetwork = MobileNetwork[r];


    string result = next(HeaderNumberMobileNetwork);
    return result;
}

/// <summary>
/// Phat sinh MSSV
/// </summary>
/// <param name="year">Nam hoc</param>
/// <param name="major">Chuyen nganh</param>
/// <returns>MSSV dang XXYYAAAA. XX: Nam hoc, YY: Chuyen nanh, AAAA: STT</returns>
string TelephonenumberGenerator::next(string HeaderNumberMobile) {
    stringstream builder;
    builder << HeaderNumberMobile;

    auto intGen = IntegerGenerator::instance();

    for (int i = 1; i <= 7; i++) {
        int digit = intGen->next(10); // [0-9]
        builder << digit;
    }

    string result = builder.str();
    return result;
}
/// <summary>
/// ham doc 3 so dau cua cac nha mang
/// </summary>
/// <param name="MobileNetwork">:danh sach 3 so dau cua 1 so dien thoai</param>
/// <param name="filename">:ten file</param>
void TelephonenumberGenerator::ReadFileTelNumber(vector<string>& MobileNetwork, string filename)
{
    ifstream fin;
    fin.open(filename, ios::in);
    while (!fin.eof())
    {
        /*
        Viettel: 12
        086
        096
        097
        098
        039
        038
        037
        036
        035
        034
        033
        032
        */
        string MobileNetworkNameAndNumber; 
        getline(fin, MobileNetworkNameAndNumber); // MobileNetworkNameAndNumber = "Viettel: 12"

        auto Tokens = Utils::String::split(MobileNetworkNameAndNumber, ": ");


        int n = stoi(Tokens[1]); // n = 12

        for (int i = 0; i < n; i++)
        {
            string HeaderNumber;
            getline(fin, HeaderNumber);

            MobileNetwork.push_back(HeaderNumber);
        }

    }


    fin.close();

}
