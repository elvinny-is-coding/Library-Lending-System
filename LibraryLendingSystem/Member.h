#ifndef MEMBER_H
#define MEMBER_H

// Prerequisite header
#include "Common.h"
#include <vector>

// Member class
class Member
{
private:
	// Member attribute
	std::string memberID;					// Member ID
	std::string memberName;					// Member Name
	 
	// Keep track of each member address, used for displaying all instance's attribute
	static std::vector<Member*> memInstances;
public:
	// Constructor
	Member(std::string mName);

	// To modify member attribute
	void setMemberID(std::string newMemberID);
	void setMemberName(std::string newMemberName);

	// To display member attribute
	std::string getMemberID();
	std::string getMemberName();

	// To display all member information
	static void getAllMember();

	// To verify if member ID exist
	static Member* searchMember(const std::string& memID);

	// Check if there is any member available 
	static bool isMemberEmpty();

	// Remove member
	static void removeMember(std::string memID);
};

#endif // !MEMBER_H


