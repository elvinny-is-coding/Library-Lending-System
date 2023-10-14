#include "LoanList.h"
#include "LibrarySystem.h"

// Parameters:
//   pBook - The book that is being loaned.
//   pMember - The member who is borrowing the book.
//   pDate - The date that the book is being loaned.

LoanList::LoanList() : head(nullptr)
{}

// Add a node to the linked list
void LoanList::addLoan(std::vector<Book*> pBooks, std::vector<Member*> pMembers, std::vector<Date*> pDates)
{
	// Create a new LoanNode object
	LoanNode* newNode = new LoanNode(pBooks, pMembers, pDates);

	// Check if list is empty
	if (head == nullptr)
	{
		// If list is empty, add new node to the head
		head = newNode;
	}
	else
	{
		// If the list is not empty, iterate through the list
		LoanNode* current = head;
		while (current->LNnext != nullptr)
		{
			// Iterate until end of list
			current = current->LNnext;
		}
		// Append new node to the list
		current->LNnext = newNode;
	}
}

// Removes a loan from the linked list
void LoanList::removeLoan(std::vector<Book*> pBooks, std::vector<Member*> pMembers, std::vector<Date*> pDates)
{
	LoanNode* current = head;
	LoanNode* previous = nullptr;

	// If current node address is not a nullptr
	while (current != nullptr)
	{
		// Iterate through the linked list, looking for the loan that matches the parameters.
		if (current->book == pBooks && current->member == pMembers)
		{
			if (previous == nullptr)
			{
				head = current->LNnext;
			}
			else
			{
				previous->LNnext = current->LNnext;
			}
			// When the loan is found, remove it from the list.
			delete current;
			break;
		}
		previous = current;
		current = current->LNnext;
	}
}

// Edit an existing loan
void LoanList::editLoan(std::vector<Book*> pBooks, std::vector<Member*> pMembers, std::vector<Date*> pDates)
{
	LoanNode* current = head;

	// Check if the loan is not found
	if (current == nullptr)
	{
		// Loan not found, so print a message and return
		std::cout << "Loan not found\n";
		return;
	}

	// Update the loan's book
	current->book = pBooks;

	// Update the loan's member
	current->member = pMembers;

	// Update the loan's date
	current->date = pDates;
}


// Returns a pointer to a LoanNode object, or nullptr if the loan is not found
LoanNode* LoanList::searchLoan(std::vector<Book*> pBooks, std::vector<Member*> pMembers, std::vector<Date*> pDates)
{
	// Initialize current to point to the head of the list
	LoanNode* current = head;
	
	// Check if list is empty
	if (head == nullptr)
	{
		std::cout << "List is empty\n";
		return nullptr;
	}
	// Traverse the list and display each node
	while (current != nullptr)
	{
		// Check if the current node's book, member, and date match the values passed to the function
		if (current->book == pBooks && current->member == pMembers && current->date == pDates)
		{
			// The loan was found, so return a pointer to the current node
			return current;
		}
		// Move on to the next node
		current = current->LNnext;
	}
	// The loan was not found, so return nullptr
	return nullptr;
}


// Check if a loan exists
bool LoanList::loanExists(std::vector<Book*> pBooks, std::vector<Member*> pMembers, std::vector<Date*> pDates)
{
	// Search for the loan
	LoanNode* loan = searchLoan(pBooks, pMembers, pDates);

	// Return true if the loan is found, false otherwise
	return (loan != nullptr);
}

// Display all available loans
void LoanList::displayAllLoans()
{
	// Variable
	LoanNode* current = head;	// Point to head of list
	int counter = 0;			// Counter to count loan instances
	
	clearScreen();

	// If no loan instances exist
	if (current == nullptr)
	{
		std::cout << "No loans found" << std::endl;
		return;
	}

	std::cout << "All available loans: " << std::endl;

	// If loan instances exist, display information regarding loan
	while (current != nullptr)
	{
		std::cout << "LOAN " << counter << ": " << std::endl;

		std::cout << "Member Name: ";
		for (size_t i = 0; i < current->book.size(); i++)
		{
			std::cout << current->member[i]->getMemberName() << std::endl;
		}
		std::cout << "Member ID: ";
		for (size_t i = 0; i < current->book.size(); i++)
		{
			std::cout << current->member[i]->getMemberID() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "Book Name: ";
		for (size_t i = 0; i < current->book.size(); i++)
		{
			std::cout << current->book[i]->getBookName() << std::endl;
		}
		std::cout << "Book ID: ";
		for (size_t i = 0; i < current->book.size(); i++)
		{
			std::cout << current->book[i]->getBookID() << std::endl;
		}
		std::cout << "Book Genre: ";
		for (size_t i = 0; i < current->book.size(); i++)
		{
			std::cout << current->book[i]->getBookGenre() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "Loan Date: ";
		for (size_t i = 0; i < current->book.size(); i++)
		{
			std::cout << current->date[i]->getLoanDate() << std::endl;
		}
		std::cout << "Due Date: ";
		for (size_t i = 0; i < current->book.size(); i++)
		{
			std::cout << current->date[i]->getDueDate() << std::endl;
		}
		std::cout << "Return Date: ";
		for (size_t i = 0; i < current->book.size(); i++)
		{
			if (current->date[i]->getReturnDate() == "0000-00-00")
			{
				std::cout << "This member has yet to return book." << std::endl;
			}
			else
			{
				std::cout << current->date[i]->getReturnDate() << std::endl;
			}
		}

		std::cout << std::endl << std::endl;

		counter++;

		// Point to next instance
		current = current->LNnext;
	}
}

// Returns the index of the vector where the loan is found, or -1 if the loan is not found
int LoanList::searchLoanIndex(std::vector<Book*> pBooks, std::vector<Member*> pMembers, std::vector<Date*> pDates)
{
	// Initialize index to -1 (not found)
	int index = -1;
	int temp = 0;

	LoanNode* current = head;	// Point to head of list

	// Check if list is empty
	if (head == nullptr)
	{
		std::cout << "List is empty\n";
		return -1;
	}

	// Traverse the list and search for the loan
	while (current != nullptr)
	{
		// Check if the current node's book, member, and date match the values passed to the function
		if (current->book == pBooks && current->member == pMembers && current->date == pDates)
		{
			// The loan was found, so update the index and break the loop
			index = temp;
			break;
		}
		temp++;
	}
	return index;
}
