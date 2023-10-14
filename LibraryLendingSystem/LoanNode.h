#ifndef LOANNODE_H
#define LOANNODE_H

#include "Book.h"
#include "Member.h"
#include "Date.h"

struct LoanNode
{
public:
	// Pointer to each class member
	std::vector<Book*> book;
	std::vector<Member*> member;
	std::vector<Date*> date;
	LoanNode* LNnext;

	// Constructor
	LoanNode(std::vector<Book*> pBook, std::vector<Member*> pMember, std::vector<Date*> pDate);
};


#endif // !LOANNODE_H

