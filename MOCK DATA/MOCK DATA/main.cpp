
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

class IntegerGenerator;
class StudentIdGenerator;
class VnFullnameGenerator;
class BirthdayGenerator;
class EmailGenerator;




#include "StudentIdGenerator.h"
#include "IntegerGenerator.h"
#include "VnFullnameGenerator.h"
#include "Major.h"
#include "Date.h"
#include "BirthdayGenerator.h"
#include"DateToCurrencyConverter.h"
#include "String.h"
#include "EmailGenenrator.h"
#include"AddressGenerator.h"
#include"TelephonenumberGenerator.h"
#include"GPAGenerator.h"




int main()
{
    //cout << MajorNames[Major::Biology] << endl;
   
    
    StudentIdGenerator idGen;
    set<string> IDlist;

    VnFullnameGenerator nameGen;
    BirthdayGenerator dobGen;
    DateToCurrencyConverter converter;
    converter.SetcurrencyPositive(Majordate::othercountries);


    EmailGenerator mailGen;
    set<string> Listemail;

    AddressGenerator HCM("TP Ho Chi Minh");
    

    
  

    TelephonenumberGenerator Tele;
    set<string> BodyTeleNumberList;
   

    GPAGenerator GPA;




    char esc_char = 27; // the decimal code for escape character is 27


    cout << esc_char << "[1m" << endl << "\t\t\t\t\t\tMOCK DATA" << esc_char << "[0m" << endl << endl;
    cout << esc_char << "[1m" << endl << "\t\t\tGenerate the number of students entered into mockData.txt file" << esc_char << "[0m" << endl << endl;
   

    int numberstuden = 0;
    cout << "Enter number of students: ";
    cin >> numberstuden;

    string filename = "mockData.txt";
    ofstream fout;
    fout.open(filename, ios::out);


    fout << "||" << setw(8) << left << "ID";
    fout << "|";
    fout << setw(25) << left << "FULL NAME";
    fout << "|";
    fout << setw(12) << left << "BIRTHDAY";
    fout << "|";
    fout << setw(35) << left << "EMAIL ADDRESS";
    fout << "|";
    fout << setw(12) << left << "TELE NUMBER";
    fout << "|";
    fout << setw(4) << left << "GPA";
    fout << "|";
    fout << setw(45) << left << "HOME ADDRESS";
    fout << endl;
    fout << "====================================================================================================================================================================================" << endl;


    for (int i = 1; i <= numberstuden; i++)
    {

        string id = idGen.next();
        while (IDlist.contains(id))
        {
            id = idGen.next();
        }
        IDlist.insert(id);
      
        //==============================================================================================================================


        string name = nameGen.next();
        Date dob = dobGen.next();
       

        //==============================================================================================================================

        string email = mailGen.next(name);

        auto tokenemail = Utils::String::split(email, "@");
        string address = tokenemail[0];

        while (Listemail.contains(address))
        {

            stringstream builder;
            address = tokenemail[0];
            string NewAdddress = mailGen.NewEmail(address);
            address = NewAdddress;
            builder << NewAdddress << "@" << tokenemail[1];
            email = builder.str();

        }
        Listemail.insert(address);

        //===============================================================================================================================

        string TeleNumberFull = Tele.next();
        string BodyTelNum = TeleNumberFull.substr(3, TeleNumberFull.length() - 1);
        while (BodyTeleNumberList.contains(BodyTelNum))
        {
            TeleNumberFull = Tele.next();
            BodyTelNum = TeleNumberFull.substr(3, TeleNumberFull.length() - 1);
        }
        BodyTeleNumberList.insert(BodyTelNum);

        //============================================================================================================



        string addresshome = HCM.next();


        //=============================================================================================================
        double gpa = GPA.GetGPA();



        fout << "||" << id << "|" << setw(25) << left << name;
        fout << "|";
        fout << setw(12) << left << converter.convert(dob.toString());
        fout << "|";
        fout << setw(35) << left << email;
        fout << "|";
        fout << setw(12) << left << TeleNumberFull;
        fout << "|";
        fout << setw(4) << left << gpa;
        fout << "|";
        fout << setw(75) << left << addresshome;
        fout << "||";
        fout << endl;
    }
    fout << "====================================================================================================================================================================================";
    fout.close();


   


    return 0;
}
