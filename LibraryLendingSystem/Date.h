#ifndef DATE_H
#define DATE_H

// Prerequisite header
#include "Common.h"
#include <ctime>                    // Used for date calculation
#include <sstream>                  // Used for date calculation

class Date
{
private: 
    // Date Attributes
    std::string loanDate;           // Refer to start of book loan date
    std::string dueDate;            // Refer to end of book loan date
    std::string returnDate;         // Refer to the date when book is return

    // Used to keep track of the date instances created
    static std::vector<Date*> dateInstances;

protected:
    // To calculate due date based on loan date
    std::string calcDueDate(std::string lDate);

    // To check if the day exceeds the maximum days in the month
    static int getMaxDaysInMonth(int month, int year);

    // To check if the the current year is leap year
    static bool isLeapYear(int year);

public:
    // Constructor
    Date(std::string lDate);
    
    // To modify date attribute
    void setLoanDate(std::string newLoanDate);
    void setDueDate(std::string newDueDate);
    void setReturnDate(std::string newReturnDate);

    // To display date attribute
    std::string getLoanDate();
    std::string getDueDate();
    std::string getReturnDate();

    static Date* searchDate(const std::string& lDate);

    // To validate date format
    static bool isDateValid(std::string lDate);

    // To checks for leap year, maximum days in a month, valid date format (YYYY-MM-DD)
    static bool isDateConsistent(std::string lDate);
};


#endif // DATE_H

