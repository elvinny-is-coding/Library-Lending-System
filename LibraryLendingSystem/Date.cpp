#include "Date.h"

// Constructor
Date::Date(std::string lDate)
{ 
	// Assign the loan date
	this->loanDate = lDate;

	// Calculate due date, based on a week from loan date
	std::string dDueDate = calcDueDate(lDate);

	// Assign the due date
	this->dueDate = dDueDate;

	// Default assignment for return date
	this->returnDate = "0000-00-00";

	// Vector, used to keep track of instance's address
	dateInstances.push_back(this);
}

// Setter, modify date attribute
void Date::setLoanDate(std::string newLoanDate)
{
	Date::loanDate = newLoanDate;   // Modify loan date
}

void Date::setDueDate(std::string newDueDate)
{
	Date::dueDate = newDueDate;     // Modify due date
}

void Date::setReturnDate(std::string newReturnDate)
{
	Date::returnDate = newReturnDate;   // Modify return date
}

// Getter, display date attribute
std::string Date::getLoanDate()
{
	return Date::loanDate;  // Obtain loan date
}

std::string Date::getDueDate()
{
	return Date::dueDate;   // Obtain due date
}

std::string Date::getReturnDate()
{
	return Date::returnDate;    // Obtain return date
}

// Used to find if an date instance exist, return pointer to date instance if exist
Date* Date::searchDate(const std::string& lDate)
{
	// For every instance that exist
	for (Date* date : dateInstances)
	{
		// If found the date instance specified
		if (date->getLoanDate() == lDate)
		{
			// Return a pointer to the instance specified
			return date;
		}
	}
	// Return a nullptr if instance is not found
	return nullptr;
}

// Checks if the year is evenly divisible by 4 and not evenly divisible by 100, or if it is evenly divisible by 400
bool Date::isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Check for the max days in a month
int Date::getMaxDaysInMonth(int month, int year) {
	if (month == 2) {
		// February: Check if it is a leap year
		// If it is a leap year, return 29 days, otherwise return 28 days
		return isLeapYear(year) ? 29 : 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		// Months with 30 days: April, June, September, November
		return 30;
	}
	else {
		// Months with 31 days: January, March, May, July, August, October, December
		return 31;
	}
}

// Calculate the due date 7 days after loan date
std::string Date::calcDueDate(std::string lDate) {
	// Parse the date string and extract the year, month, and day
	int year = std::stoi(lDate.substr(0, 4));
	int month = std::stoi(lDate.substr(5, 2));
	int day = std::stoi(lDate.substr(8, 2));

	// Calculate the date one week from the given date
	day += 7;

	// Check if the day exceeds the maximum days in the month
	if (day > getMaxDaysInMonth(month, year)) {
		day -= getMaxDaysInMonth(month, year);
		month++;

		// Check if the month exceeds 12
		if (month > 12) {
			month = 1;
			year++;
		}
	}

	// Return the date in YYYY-MM-DD format, add 0 as padding if only contain 1 digit
	std::string formattedMonth = std::to_string(month);
	if (formattedMonth.length() == 1) {
		formattedMonth = "0" + formattedMonth;
	}
	std::string formattedDay = std::to_string(day);
	if (formattedDay.length() == 1) {
		formattedDay = "0" + formattedDay;
	}

	// Return YYYY-MM-DD
	return std::to_string(year) + "-" + formattedMonth + "-" + formattedDay;
}

// To validate date format
bool Date::isDateValid(std::string lDate) {
	// Create a regular expression to match the date string.
	std::regex dateRegex("^\\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[01])$");

	// Return true if the date matches the format, otherwise false.
	return std::regex_match(lDate, dateRegex);
}

// Used to check if date is consistent, return true if date is consistent
bool Date::isDateConsistent(std::string lDate)
{
	// Check if the date is valid
	if (!isDateValid(lDate)) {
		return false;
	}

	// Extract year, month, and day from the date string
	int year = std::stoi(lDate.substr(0, 4));
	int month = std::stoi(lDate.substr(5, 2));
	int day = std::stoi(lDate.substr(8, 2));

	// Check if the month is within the valid range (1-12)
	if (month < 1 || month > 12) {
		return false;
	}

	// Check if the day is within the valid range for the given month and year
	if (day < 1 || day > getMaxDaysInMonth(month, year)) {
		return false;
	}

	// The date is consistent
	return true;
}
