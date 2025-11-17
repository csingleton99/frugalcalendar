// chris singleton, cmpsc 330, Ganther, November 17th, 2025
// This program is designed to calculate the next year for which all the days of a year will align with their weekdays and numbers, day-of-month
//


#include <iostream>
#include <vector>

int yearOne = 1759;
int yearTwo = 2000;
std::vector<int> validYears;

bool isLeapYear(int yearHere)
{
    bool leap;
    if (yearHere / 4 == 0)
        leap = true

    return !(); // leap years are divisible by 4. If no remainder, returns not-0, which is true. If there is a remainder, returns not-remainder, which is false
}

int main()
{
    std::cout << isLeapYear(yearOne) << "\n";
    std::cout << isLeapYear(yearTwo) << "\n";
    // Each non-leap year, the day-of-the-week increments by one, looping at Saturday, except on leap years, where it increments by two
    // So, without leap years, it would increment back around every seven years. With leap years, it increments every six
    // If the year given is, itself, a leap year, things get strange
    std::cout << "Hello World!\n";
}