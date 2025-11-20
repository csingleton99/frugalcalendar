// chris singleton, cmpsc 330, Ganther, November 17th, 2025
// This program is designed to calculate the next year for which all the days of a year will align with their weekdays and numbers, day-of-month
//

#include <iostream>
#include<string>
#include <vector>

int currentSelection = 1;
std::string userEntryTemp;
int userEntry;
bool isGivenLeap = false;
bool isCurrentLeap = false;

void inputValidation()
{
    bool noErrors = false;

    while (noErrors == false)
    {
        try
        {
            userEntry = std::stoi(userEntryTemp);
            noErrors = true;
        }
        catch (const std::exception& e)
        {
            std::cout << "Something is wrong with your entry: " << e.what() << ". Enter a new, positive integer now:\n";
            std::cin >> userEntryTemp;
            system("cls");
        }
    }

    if (userEntry != 0)
    {
        while (userEntry < 1700 or userEntry > 2024)
        {
            std::cout << "Your input is not valid! Please enter a year between 1700 and 2024 or later: \n";
            std::cin >> userEntry;
            system("cls");
        }
    }
}

bool isLeapYear(int yearHere)
{
    return !(yearHere % 4); // 0 is falsy, anything else is truthy
}

void validCalendars(int yearHere)
{
    std::vector<int> validYears;
    int currentDay = 0;
    int currentYear = yearHere;
    isGivenLeap = isLeapYear(currentYear);

    while (validYears.size() < 5 and currentYear < 3500)
    {
        currentYear++;
        isCurrentLeap = isLeapYear(currentYear);
        if (isCurrentLeap)
            currentDay += 2;
        else
            currentDay++;

        if (currentDay % 7 == 0 and isGivenLeap == isCurrentLeap)
        {
            validYears.push_back(currentYear);
        }
    }

    std::cout << "This calendar may be reused during the years:\n";

    for (int years : validYears)
    {
        
        std::cout << years << "\n";
    }
    std::cout << "\n";
    
}

int main()
{
    while (currentSelection != 0)
    {
        std::cout << "This program will determine up to five years for which you may reuse a given calendar between the years 1700 and 2024.\nPlease enter the year of your calendar now, or enter 0 to exit the program: ";
        std::cin >> userEntryTemp;
        system("cls");
        inputValidation();


        if (userEntry != 0)
        {
            validCalendars(userEntry);
        }
        else
            currentSelection = 0;

    }

    std::cout << "Thank you for using this program! Bye!\n";
}