#ifndef LOANLIST_H
#define LOANLIST_H

// Prerequisite dependency
#include "Common.h"
#include "LoanNode.h"

class LoanList
{
private:
	LoanNode* head; // Point to head of node

public:
	// Constructor 
	LoanList();

	// To add new LoanNode to list
	void addLoan(std::vector<Book*> pBooks, std::vector<Member*> pMembers, std::vector<Date*> pDates);

	// To remove a LoanNode from list
	void removeLoan(std::vector<Book*> pBooks, std::vector<Member*> pMembers, std::vector<Date*> pDates);

	// To edit a existing loan
	void editLoan(std::vector<Book*> pBooks, std::vector<Member*> pMembers, std::vector<Date*> pDates);

	// To search for pointer for a specific loan
	LoanNode* searchLoan(std::vector<Book*> pBooks, std::vector<Member*> pMembers, std::vector<Date*> pDates);

	// To check whether if a loan exist
	bool loanExists(std::vector<Book*> pBooks, std::vector<Member*> pMembers, std::vector<Date*> pDates);

	// To display all loans
	void displayAllLoans();

	// Return vector index
	int searchLoanIndex(std::vector<Book*> pBooks, std::vector<Member*> pMembers, std::vector<Date*> pDates);
};

#endif // !LOANLIST_H


