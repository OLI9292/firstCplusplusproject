//
//  main.cpp
//  FirstProgram
//
//  Created by Oliver  on 10/2/16.
//  Copyright © 2016 Oliver . All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

class AgeCalculator
{
public:
    struct Date
    {
        int month, day, year;
    };
public:
    AgeCalculator();
    Date setDateNow();
    void setAge();
    void calculateAge();
    bool validateInput(string, int, int);
private:
    Date datenow;
    Date birthday;
};

AgeCalculator::AgeCalculator()
{
    datenow = setDateNow();
};

AgeCalculator::Date AgeCalculator::setDateNow()
{
    
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    
    datenow.month = now->tm_mon + 1;
    datenow.day = now->tm_mday;
    datenow.year = now->tm_year + 1900;
    
    return datenow;
};

void AgeCalculator::setAge()
{
    string monthInput;
    string dayInput;
    string yearInput;
    
    bool validMonth;
    bool validDay;
    bool validYear;
    
    cout << "What month were you born?  ";
    getline(cin, monthInput);
    validMonth = validateInput(monthInput, 0, 12);
    
    cout << "What day were you born?  ";
    getline(cin, dayInput);
    validDay = validateInput(dayInput, 0, 31);
    
    cout << "What year were you born?  ";
    getline(cin, yearInput);
    validYear = validateInput(yearInput, 1900, 2016);
    
    if (validMonth && validDay && validYear)
    {
        stringstream(monthInput) >> birthday.month;
        stringstream(dayInput) >> birthday.day;
        stringstream(yearInput) >> birthday.year;
    
        cout << "You were born on " << monthInput
             << "-" << dayInput << "-" << yearInput << endl;
    }
    else
    {
        cout << "Please enter a valid date." << endl;
    }
};

void AgeCalculator::calculateAge()
{
    int ageEst;
    int monthDiff;
    int dayDiff;
    
    ageEst = datenow.year - birthday.year;
    monthDiff = datenow.month - birthday.month;
    
    if (monthDiff < 0)
    {
        --ageEst;
    }
    if (monthDiff == 0)
    {
        dayDiff = datenow.day - birthday.day;
        if (dayDiff < 0)
        {
           --ageEst;
        }
    }
    cout << "You are " << ageEst << " years old!" << endl;
}

bool AgeCalculator::validateInput(string input, int low, int high)
{
    int intInput;
    stringstream(input) >> intInput;
    
    if (intInput > low && intInput <= high)
        return true;
    
    return false;
};

int main() {
    
    AgeCalculator ageCalc;
    ageCalc.setAge();
    ageCalc.calculateAge();
}
