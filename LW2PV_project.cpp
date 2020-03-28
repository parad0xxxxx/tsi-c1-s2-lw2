#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;

void setW()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void setG()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void setR()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}

void setB()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
}

void setGr()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}

void setDC()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void setM()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
}



string convertToString(char*, int);
char* setMeHigher(char*);
string setMeHigher(string&);

int main()
{
    int charElementsAmount, charElementWidthMax = 255;
    setM();
    cout << "Enter the number of elements: ";
    setG();
    charElementsAmount = 2;
    //    cin >> charElementsAmount;
    //    cin.ignore();
    if (charElementsAmount < 1) {
        setR();
        cout << "The number must be posivive integer.";
        setG();
        return 0;
    }

    char** myntcs = new char* [charElementsAmount]; // ntcs 2d array gen
    for (int i = 0; i < charElementsAmount; i++)
    {
        myntcs[i] = new char[charElementWidthMax];
    }

    for (int i = 0; i < charElementsAmount; i++)  // ntcs 2d array fillin
    {
        setM();
        cout << "Enter a word or sentence nr." << i + 1 << ": ";
        setG();
        cin.getline(myntcs[i], charElementWidthMax);
    }
    setB();
    cout << "\nYour ntcs elements in array:\n";
    setG();

    for (int i = 0; i < charElementsAmount; i++)   // ntcs 2d array cout
    {
        cout << i + 1 << myntcs[i] << strlen(myntcs[i]) << endl;
    }

    string* mystring = new string[charElementsAmount];   // string array gen

    int charElementWidthCurr = 0;

    for (int i = 0; i < charElementsAmount; i++)  // string array fillin by copying from ntcs and flatten
    {
        cout << "conv: " << endl;
        charElementWidthCurr = strlen(myntcs[i]);
        cout << "charElementWidthCurr: " << charElementWidthCurr << endl;
        string s_a = convertToString(myntcs[i], charElementWidthCurr);
        cout << s_a << endl;
        mystring[i] = s_a;
        /*
        string thong;
        for (int j = 0; j < strlen(myntcs[i][j]); j++)
        {
            thong += myntcs[i];
        }
        mystring[i] = thong; */

    }

    setB();
    cout << "\nYour string elements in array:\n";
    setG();
    for (int i = 0; i < charElementsAmount; i++)   // ntcs 2d array cout
    {
        cout << mystring[i] << endl;
    }

    //    cout << "prost: " << *mystring << endl;



    setB();
    cout << "\nChecking against the COVID-19 patterns...\n"; // because eastern eggs is fun =)
    setG();
    srand(time(NULL));
    int corona = rand() % 10;
    if (corona % 2 == 0) {
        setGr();
        cout << "COVID-19 patterns are not found. Environment is safe. Feel free to continue, Cutie =)\n";
        setG();
    }
    else {
        setR();
        cout << "COVID-19 patterns are found! High risk of infection! Leave the room or continue at your own risk, Cutie!\n";
        setG();
    }

    setB();
    cout << "\nProcessing ntcs data...\n"; // load-load-overload
    setG();
    for (int i = 0; i < charElementsAmount; i++)
    {
        setMeHigher(myntcs[i]);
        cout << myntcs[i] << endl;
    }

    setDC();
    cout << "\nProcessing string data...\n"; // and again for strings
    setG();
    for (int i = 0; i < charElementsAmount; i++)
    {
        setMeHigher(mystring[i]);
        cout << mystring[i] << endl;
    }
    setM();
    cout << "\nOperation complete.\n";
    setG();

    delete[] mystring;  // cleaning up

    for (int i = 0; i < charElementsAmount; i++)
        delete[] myntcs[i];
    delete[] myntcs;
    return 0;
}

string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

char* setMeHigher(char* s)
{
    for (int i = 0; i < strlen(s); i++) {
        if (islower(s[i])) {
            s[i] = toupper(s[i]);
        }
    }
    return s;
}

string setMeHigher(string& s)
{
    for (int i = 0; i < s.length(); i++) {
        if (islower(s[i])) {
            s[i] = toupper(s[i]);
        }
    }
    return s;
}