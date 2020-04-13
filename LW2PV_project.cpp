#include <windows.h>

#include <iostream>
#include <string>
#include <time.h>

const std::string INT_EXPECTED_ERROR = "The number must be posivive integer.";
const std::string PROGRAM_EXIT_INFO = "\nBye, Cutie. It\'s a pleasure, as always =)\n";

void setConsoleColor(int);
void warnCutie(std::string);
void logInfo(std::string m);
std::string convertToString(char*);
void setToUpper(char*);
void setToUpper(std::string&);
void coronavirusCheck();

int main()
{
    int charElementsAmount;
    const int charElementWidthMax = 255;
    setConsoleColor(9);
    std::cout << "Enter the number of elements (words or sentences): ";
    setConsoleColor(8);
    std::cin >> charElementsAmount;
    std::cin.ignore(32767, '\n');

    if (charElementsAmount < 1) {
        warnCutie(INT_EXPECTED_ERROR);
        return 0;
    }

    char** myntcs = new char* [charElementsAmount]; // ntcs 2d array gen
    for (int i = 0; i < charElementsAmount; i++)
    {
        myntcs[i] = new char[charElementWidthMax];
    }

    for (int i = 0; i < charElementsAmount; i++)  // ntcs 2d array fillin
    {
        setConsoleColor(3);
        std::cout << "Element " << i + 1 << ": ";
        setConsoleColor(8);
        std::cin.getline(myntcs[i], charElementWidthMax);
    }

    setConsoleColor(9);
    std::cout << "\nYour ";
    setConsoleColor(6);
    std::cout << "ntcs ";
    setConsoleColor(9);
    std::cout << "elements in array:\n";
    setConsoleColor(8);

    for (int i = 0; i < charElementsAmount; i++)   // ntcs 2d array cout
    {
        std::cout << i + 1 << ". " << myntcs[i] << std::endl;
    }

    setConsoleColor(9);
    std::cout << "\nYour ";
    setConsoleColor(5);
    std::cout << "string ";
    setConsoleColor(9);
    std::cout << "elements in array:\n";
    setConsoleColor(8);

    std::string* mystring = new std::string[charElementsAmount];   // string array gen

    for (int i = 0; i < charElementsAmount; i++)  // string array fillin by copying from ntcs and flatten
    {
        std::string tempString = convertToString(myntcs[i]);
        mystring[i] = tempString;
    }

    for (int i = 0; i < charElementsAmount; i++)   // string array cout
    {
        std::cout << i + 1 << ". " << mystring[i] << std::endl; ///
    }

    coronavirusCheck();

    setConsoleColor(9);
    std::cout << "\nProcessing ";
    setConsoleColor(6);
    std::cout << "ntcs ";
    setConsoleColor(9);
    std::cout << "data...\n";
    setConsoleColor(15);

    for (int i = 0; i < charElementsAmount; i++) // load-load-overload
    {
        setToUpper(myntcs[i]);
        std::cout << i + 1 << ". " << myntcs[i] << std::endl;
    }

    setConsoleColor(9);
    std::cout << "\nProcessing ";
    setConsoleColor(5);
    std::cout << "string ";
    setConsoleColor(9);
    std::cout << "data...\n";
    setConsoleColor(15);

    for (int i = 0; i < charElementsAmount; i++) // and again for strings
    {
        setToUpper(mystring[i]);
        std::cout << i + 1 << ". " << mystring[i] << std::endl;
    }

    setConsoleColor(9);
    std::cout << "\nOperation complete.\n";
    setConsoleColor(7);

    delete[] mystring;  // cleaning up

    for (int i = 0; i < charElementsAmount; i++)
        delete[] myntcs[i];
    delete[] myntcs;

    system("pause");
    system("cls");

    logInfo(PROGRAM_EXIT_INFO);

    return 0;
}

void setConsoleColor(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void warnCutie(std::string cutiepie)
{
    setConsoleColor(4);
    std::cout << std::endl << cutiepie << std::endl << std::endl;
    setConsoleColor(7);
}

void logInfo(std::string m)
{
    setConsoleColor(11);
    std::cout << m << std::endl;
    setConsoleColor(7);
}

std::string convertToString(char* a)
{
    std::string s = "";
    for (int i = 0; i < strlen(a); i++) {
        s += a[i];
    }
    return s;
}

void setToUpper(char* s)
{
    for (int i = 0; i < strlen(s); i++) {
        if (islower(s[i])) {
            s[i] = toupper(s[i]);
        }
    }
}

void setToUpper(std::string& s)
{
    for (int i = 0; i < s.length(); i++) {
        if (islower(s[i])) {
            s[i] = toupper(s[i]);
        }
    }
}

void coronavirusCheck()
{
    setConsoleColor(9);
    std::cout << "\nChecking against the COVID-19 patterns...\n"; // because eastern eggs is fun =)
    setConsoleColor(7);
    srand(time(NULL));
    int corona = rand() % 10;
    if (corona % 2 == 0) {
        setConsoleColor(2);
        std::cout << "COVID-19 patterns are not found. Environment is safe. Feel free to continue, Cutie =)\n";
        setConsoleColor(7);
    }
    else {
        setConsoleColor(4);
        std::cout << "COVID-19 patterns are found! High risk of infection! Leave the room or continue at your own risk, Cutie!\n";
        setConsoleColor(7);
    }
}