/*
This program is library lending system, designed for librarian to manage a library that loans book
*/ 


#include <iostream>
#include <regex>
#include <string>
#include "LoanList.h"
#include "LoanNode.h"
#include "Book.h"
#include "Date.h"
#include "Member.h"
#include "LibrarySystem.h"
#include "main.h"

std::vector<Book*> Book::bookInstances;
std::vector<Member*> Member::memInstances;
std::vector<Date*> Date::dateInstances;

int main()
{
	// Variable declaration
	bool quitProgram = false;		// Used to stop the program
	std::string userInput;			// Used to store user input

	
	// Declare a linked list instance
	LoanList loans; 
		

	// Start of program
	// Login menu
	displayLoginScreen();

	do 
	{
		// Goes back to main menu
		clearScreen();
		std::cin.clear();
		displayMainMenu();
		displayMainMenuOptions();
		std::cin >> userInput;

		std::cout.clear();
		std::cin.ignore(INTMAX_MAX, '\n');

		// Used to display all available book
		if (userInput == "1a")
		{
			displayBookMenu();
			std::cout << std::endl << "Press any key to go back to main menu..." << std::endl;
			std::cin >> userInput;
			addDelay();
			clearScreen();
		}
		// Used to sort and display book by genre
		else if (userInput == "1b")
		{
			displayBookByGenre();
			std::cout << std::endl << "Press any key to go back to main menu..." << std::endl;
			std::cin >> userInput;
			addDelay();
			clearScreen();
		}
		// Used to create book
		else if (userInput == "1c")
		{
			clearScreen();
			// Variable to store input
			std::string userInputBookName;
			int userInputBookGenre;

			// Enter the name of the book
			std::cout << "Please enter a name for the book you want to create" << std::endl;
			std::getline(std::cin, userInputBookName);

			clearScreen();

			do
			{
				// Categorizing based on genre given
				std::cout << "Categorize the book from the following genre list" << std::endl;
				std::cout << "by entering their respective number." << std::endl << std::endl; // Added two endl for spacing
				std::cout << "0. Horror" << std::endl;
				std::cout << "1. Romance" << std::endl;
				std::cout << "2. Sci-Fi" << std::endl;
				std::cout << "3. Fantasy" << std::endl;
				std::cout << "4. Adventure" << std::endl;

				std::cout << std::endl << "Enter a number from 0 to 4: ";
				std::cin >> userInputBookGenre;

				if (std::cin.fail() || userInputBookGenre > 4 || userInputBookGenre < 0)
				{
					std::cout << std::endl << "ERROR: Invalid input. Please choosen between 0 to 4.";
					std::cout.clear();
					std::cin.ignore(INTMAX_MAX, '\n');
					addDelay();
					clearScreen();
				}
				else
				{
					break;
				}

			} while (true);
			
			clearScreen();

			// Create an instance of book
			Book* newBook = new Book(userInputBookName, userInputBookGenre);

			addDelay();
		}
		// Used to delete book
		else if (userInput == "1d")
		{
			clearScreen();
			std::string userInputBookID;
			
			// Display all available book
			Book::getAllBook();

			if (Book::isLibraryEmpty() == true)
			{
				addDelay();
				clearScreen();
			}
			else if (Book::isLibraryEmpty() == false)
			{
				// Enter the book index
				std::cout << "Please note that Book ID is case-sensitive." << std::endl;
				std::cout << "Enter the Book ID of the book you want to remove: ";
				std::getline(std::cin, userInputBookID);

				Book::removeBook(userInputBookID);
				addDelay();
			}
		}
		// Used to display all member
		else if (userInput == "2a")
		{
			displayMemberMenu();
			std::cout << std::endl << "Press any key to go back to main menu..." << std::endl;
			std::cin >> userInput;
			addDelay();
			clearScreen();
		}
		// Used to add member
		else if (userInput == "2b")
		{
			clearScreen();

			// Variable to store input
			std::string inputName;

			// Is the input name valid
			bool isNameValid = false;

			// Ask user to enter name
			std::cout << "Please enter a name for the member: ";
			getline(std::cin, inputName);

			while (isNameValid == false)
			{
				// Create a regex that has valid name format
				// [Jonathan Von der Hompton] is valid, that is, word with capital will also work
				std::regex validMemberName("^[A-Z]'?[- a-zA-Z]+$");

				// Match regex to see if member name is valid
				if (std::regex_match(inputName, validMemberName) == true)
				{
					isNameValid = true;
					break;
				}
				else if (std::regex_match(inputName, validMemberName) == false)
				{
					// Ask user to enter name
					std::cout << "ERROR: Invalid name entered." << std::endl << "Please enter a name for the member: ";
					getline(std::cin, inputName);
					std::cin.clear();
					std::cin.ignore(INTMAX_MAX, '\n');
				}
			}

			// Create an instance of book
			Member* newMem = new Member(inputName);

			addDelay();
		}
		// Used to delete member
		else if (userInput == "2c")
		{
			clearScreen();
			std::string userInputName;

			// Display all available book
			Member::getAllMember();

			if (Member::isMemberEmpty() == true)
			{
				addDelay();
				clearScreen();
			}
			else if (Member::isMemberEmpty() == false)
			{
				// Enter the book index
				std::cout << "Please note that Member ID is case-sensitive." << std::endl;
				std::cout << "Enter the Member ID of the book you want to remove: ";
				std::getline(std::cin, userInputName);

				Member::removeMember(userInputName);
				addDelay();
			}
		}
		// Used to display all loan
		else if (userInput == "3a")
		{
			loans.displayAllLoans();
			std::cout << "Press any key to go back to main menu..." << std::endl;
			std::cin >> userInput;
			addDelay();
			clearScreen();
		}
		// Used to add loan
		else if (userInput == "3b")
		{
			clearScreen();
			loans.displayAllLoans();
			std::string tempBookID;
			std::string tempMemberID;
			std::string tempStartDate;

			std::cout << "Enter the book ID: ";
			std::getline(std::cin, tempBookID);

			std::cout << "Enter the member ID: ";
			std::getline(std::cin, tempMemberID);

			std::cout << "Enter the starting date (YYYY-MM-DD): ";
			std::getline(std::cin, tempStartDate);

			while (true)
			{
				if (Date::isDateValid(tempStartDate) == true)
				{
					break;
				}
				else
				{
					std::cout << "ERROR: Invalid value entered for date. Try again." << std::endl;
					std::cout << "Enter the starting date (YYYY-MM-DD): ";
					std::getline(std::cin, tempStartDate);
				}
			}

			// Create vectors to hold book, member, and date instances
			std::vector<Book*> pBooks;
			std::vector<Member*> pMembers;
			std::vector<Date*> pDates;
			
			Book* book = Book::searchBook(tempBookID);
			Member* member = Member::searchMember(tempMemberID);
			Date* date = new Date(tempStartDate);

			if (book != nullptr && member != nullptr && date != nullptr)
			{
				pBooks.push_back(book);
				pMembers.push_back(member);
				pDates.push_back(date);

				// Add the loan to the loan list
				loans.addLoan(pBooks, pMembers, pDates);

				std::cout << "Loan added successfully!" << std::endl;
			}
			else
			{
				std::cout << "ERROR: Invalid book ID, member ID, or date format. Please check your input." << std::endl;
			}

			std::cout << "Press any key to go back to main menu..." << std::endl;
			std::cin >> userInput;
			addDelay();
			clearScreen();
		}
		// Used to remove loan
		else if (userInput == "3c")
		{
			clearScreen();
			loans.displayAllLoans();
			std::string tempBookID;
			std::string tempMemberID;
			std::string tempStartDate;

			std::cout << "Enter the book ID: ";
			std::getline(std::cin, tempBookID);

			std::cout << "Enter the member ID: ";
			std::getline(std::cin, tempMemberID);

			std::cout << "Enter the starting date (YYYY-MM-DD): ";
			std::getline(std::cin, tempStartDate);

			while (true)
			{
				if (Date::isDateConsistent(tempStartDate) == true)
				{
					break;
				}
				else
				{
					std::cout << "ERROR: Invalid value entered for date. Try again." << std::endl;
					std::cout << "Enter the starting date (YYYY-MM-DD): ";
					std::getline(std::cin, tempStartDate);
				}
			}

			// Create vectors to hold book, member, and date instances
			std::vector<Book*> pBooks;
			std::vector<Member*> pMembers;
			std::vector<Date*> pDates;

			// Search for book, member, and date using the given IDs
			Book* book = Book::searchBook(tempBookID);
			Member* member = Member::searchMember(tempMemberID);
			Date* date = new Date(tempStartDate);

			if (book != nullptr && member != nullptr && date != nullptr)
			{
				pBooks.push_back(book);
				pMembers.push_back(member);
				pDates.push_back(date);

				// Remove the loan from the loan list
				loans.removeLoan(pBooks, pMembers, pDates);

				std::cout << "Loan removed successfully!" << std::endl;
			}
			else
			{
				std::cout << "ERROR: Invalid book ID, member ID, or date format. Please check your input." << std::endl;
			}

			std::cout << "Press any key to go back to main menu..." << std::endl;
			std::cin >> userInput;
			addDelay();
			clearScreen();
		}
		// Used to edit loan
		else if (userInput == "3d")
		{
			clearScreen();
			loans.displayAllLoans();
			std::string tempBookID;
			std::string tempMemberID;
			std::string tempStartDate;
			int loanIndex = -1;

			std::cout << "Enter the book ID: ";
			std::getline(std::cin, tempBookID);

			std::cout << "Enter the member ID: ";
			std::getline(std::cin, tempMemberID);

			std::cout << "Enter the starting date (YYYY-MM-DD): ";
			std::getline(std::cin, tempStartDate);

			while (true)
			{
				if (Date::isDateConsistent(tempStartDate) == true)
				{
					break;
				}
				else
				{
					std::cout << "ERROR: Invalid value entered for date. Try again." << std::endl;
					std::cout << "Enter the starting date (YYYY-MM-DD): ";
					std::getline(std::cin, tempStartDate);
				}
			}

			// Create vectors to hold book, member, and date instances
			std::vector<Book*> tempBooks;
			std::vector<Member*> tempMembers;
			std::vector<Date*> tempDates;

			// Search for book, member, and date using the given IDs
			Book* book = Book::searchBook(tempBookID);
			Member* member = Member::searchMember(tempMemberID);
			Date* date = Date::searchDate(tempStartDate);

			if (book != nullptr && member != nullptr && date != nullptr)
			{
				tempBooks.push_back(book);
				tempMembers.push_back(member);
				tempDates.push_back(date);

				// Search for the loan in the loan list
				LoanNode* loan = loans.searchLoan(tempBooks, tempMembers, tempDates);

				loanIndex = loans.searchLoanIndex(tempBooks, tempMembers, tempDates);

				if (loan != nullptr)
				{
					tempBooks.clear();
					tempMembers.clear();

					std::cout << std::endl << "Enter the book ID to change loan to different existing book: ";
					std::getline(std::cin, tempBookID);

					std::cout << "Enter the member ID to change loan to different existing member: ";
					std::getline(std::cin, tempMemberID);

					Book* book = Book::searchBook(tempBookID);
					Member* member = Member::searchMember(tempMemberID);

					if (book != nullptr && member != nullptr && date != nullptr)
					{
						tempBooks.push_back(book);
						tempMembers.push_back(member);

						loans.editLoan(tempBooks, tempMembers, tempDates);

						std::cout << "Loan edited successfully!" << std::endl;
					}
					else
					{
						std::cout << "ERROR: Loan not found. Please check your input." << std::endl;
					}

				}
				else
				{
					std::cout << "ERROR: Loan not found. Please check your input." << std::endl;
				}

			}
			else
			{
				std::cout << "ERROR: Invalid book ID, member ID, or date format. Please check your input." << std::endl;
			}

			std::cout << "Press any key to go back to main menu..." << std::endl;
			std::cin >> userInput;
			addDelay();
			clearScreen();
		}
		// Used to set return date of borrowed books
		else if (userInput == "3e")
		{
			clearScreen();
			loans.displayAllLoans();
			std::string tempBookID;
			std::string tempMemberID;
			std::string tempStartDate;

			std::cout << "Enter the book ID: ";
			std::getline(std::cin, tempBookID);

			std::cout << "Enter the member ID: ";
			std::getline(std::cin, tempMemberID);

			std::cout << "Enter the starting date (YYYY-MM-DD): ";
			std::getline(std::cin, tempStartDate);

			while (true)
			{
				if (Date::isDateConsistent(tempStartDate) == true)
				{
					break;
				}
				else
				{
					std::cout << "ERROR: Invalid value entered for date. Try again." << std::endl;
					std::cout << "Enter the starting date (YYYY-MM-DD): ";
					std::getline(std::cin, tempStartDate);
				}
			}

			// Create vectors to hold book, member, and date instances
			std::vector<Book*> pBooks;
			std::vector<Member*> pMembers;
			std::vector<Date*> pDates;

			// Search for book, member, and date using the given IDs
			Book* book = Book::searchBook(tempBookID);
			Member* member = Member::searchMember(tempMemberID);
			Date* date = Date::searchDate(tempStartDate);

			if (book != nullptr && member != nullptr && date != nullptr)
			{
				pBooks.push_back(book);
				pMembers.push_back(member);
				pDates.push_back(date);

				// Search for the loan in the loan list
				LoanNode* editLoan = loans.searchLoan(pBooks, pMembers, pDates);

				if (editLoan != nullptr)
				{
					std::vector<Date*>& editDate = editLoan->date;  // Get a reference to the loan's date vector
					std::string tempReturnDate;

					std::cout << "Enter the return date (YYYY-MM-DD): ";
					std::getline(std::cin, tempReturnDate);

					while (true)
					{
						if (Date::isDateConsistent(tempReturnDate) == true)
						{
							break;
						}
						else
						{
							std::cout << "ERROR: Invalid value entered for date. Try again." << std::endl;
							std::cout << "Enter the return date (YYYY-MM-DD): ";
							std::getline(std::cin, tempReturnDate);
						}
					}
					// Access the first Date object in the vector and set its return date
					editDate[0]->setReturnDate(tempReturnDate);

					std::cout << "Loan return date set successfully!" << std::endl;
				}
				else
				{
					std::cout << "ERROR: Loan not found. Please check your input." << std::endl;
				}
			}
			else
			{
				std::cout << "ERROR: Invalid book ID, member ID, or date format. Please check your input." << std::endl;
			}

			std::cout << "Press any key to go back to main menu..." << std::endl;
			std::cin >> userInput;
			addDelay();
			clearScreen();
		}
		else if (userInput == "Q" || userInput == "q")
		{
			clearScreen();
			std::cout << "Exit code entered. Program terminated successfully." << std::endl;
			quitProgram = true;
		}
		else
		{
			clearScreen();
			std::cout << "ERROR: Invalid input entered. Please enter a valid option." << std::endl;
			addDelay();
		}
	} while (quitProgram == false);

	return 0;
}
