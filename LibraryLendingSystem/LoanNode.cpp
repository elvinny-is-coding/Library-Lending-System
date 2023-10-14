#include "LoanNode.h"

LoanNode::LoanNode(std::vector<Book*> pBook, std::vector<Member*> pMember, std::vector<Date*> pDate)
{
	this->book = pBook;			// Point to book
	this->member = pMember;		// Point to member
	this->date = pDate;			// Point to date
	LNnext = nullptr;			// Point to next node
}
