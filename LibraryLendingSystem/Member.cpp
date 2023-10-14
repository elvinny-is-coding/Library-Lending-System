#include "Member.h"
#include <vector>

// Declaring counter to keep track of member object instances
int counterMembers = 0;

// Constructor
Member::Member(std::string mName)
{
	// Assign valid name to memberName
	this->memberName = mName;

	// Assign ID to member based on counterMember
	this->memberID = "M" + std::to_string(counterMembers);

	// Vector, used to keep track of instance's address
	memInstances.push_back(this);

	// Show created member
	std::cout << "The member named, \"" << this->getMemberName() << "\" with the ID \"" << this->getMemberID() << "\" has been sucessfully created." << std::endl;

	// Increment counter
	counterMembers++;
}

// Setter, To modify member value
void Member::setMemberID(std::string newMemberID)
{
	Member::memberID = newMemberID;
}

void Member::setMemberName(std::string newMemberName)
{
	Member::memberName = newMemberName;
}

// Getter, to display member value
std::string Member::getMemberID()
{
	return Member::memberID; 
}

std::string Member::getMemberName()
{
	return Member::memberName;
}

// Display all available member information
void Member::getAllMember()
{
	int counter = 0;
	if (memInstances.empty() == true)
	{
		std::cout << "There are currently no member." << std::endl;
	}
	else if (memInstances.empty() == false)
	{
		for (const auto& instance : memInstances) {
			std::cout << "MEMBER " << std::to_string(counter) << std::endl;
			std::cout << "Member Name: " << instance->memberName << std::endl;
			std::cout << "Member ID: " << instance->memberID << std::endl;
			counter++;
		}
	}
	else
	{
		std::cout << "ERROR: getAllMember can't display book due to unexpected reason" << std::endl;
		exit(1);
	}
}

// Search if specified member instances exist, return pointer to instance if does
Member* Member::searchMember(const std::string& memID)
{
	// For every member instances that exist
	for (Member* member : memInstances)
	{
		// If the ID given matches the ID found
		if (member->getMemberID() == memID)
		{
			// Return a pointer to the member instance
			return member;
		}
	}
	// If not found, return nullptr
	return nullptr;
}

// Check if any member instances exist. If member list is empty, return true
bool Member::isMemberEmpty()
{
	// If member instances does not exist
	if (memInstances.empty() == true)
	{
		return true;
	}
	// If member instances exist
	else if (memInstances.empty() == false)
	{
		return false;
	}
	// Used for diagnostic
	else
	{
		std::cout << "ERROR: isMemberEmpty cannot produce a true or false" << std::endl;
		exit(1);
	}
}

// Removes an existing member instances
void Member::removeMember(std::string memID)
{
	// Keep track whether if the specified ID matches an existing ID
	bool found = false;

	// Find the book object with the given ID
	for (auto it = memInstances.begin(); it != memInstances.end(); ++it)
	{
		if ((*it)->memberID == memID)
		{
			// Erase the book object from the vector
			delete* it;
			memInstances.erase(it);
			found = true;
			break;  // Exit the loop after removing the book
		}
	}
	counterMembers--;
}


