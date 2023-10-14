#include "Book.h"

// Declaring options for book genre
std::string bookGenreOptions[5] = { "Horror","Romance","Sci-Fi","Fantasy","Adventure" };

// Declaring counter for keeping track of book instances 
int bookCounterH = 0;	// Used to count book of Horror genre
int bookCounterR = 0;	// Used to count book of Romance genre
int bookCounterS = 0;	// Used to count book of Sci-Fi genre
int bookCounterF = 0;	// Used to count book of Fantasy genre
int bookCounterA = 0;	// Used to count book of Adventure genre
int bookCounterAll = 0; // Used to count all instances of book created

// Constructor for Book
Book::Book(std::string bName, int bGenre)
{
	// No book naming conventions
	this->bookName = bName;

	// Genre will have predetermined option, using bookGenreOptions
	// Thus book genre is checked
	this->bookGenre = checkBookGenre(bGenre);

	// Depending on the genre, the respective counter is incremented
	switch (bGenre)
	{
	case 0:
		bookCounterH++;
		break;
	case 1:
		bookCounterR++;
		break;
	case 2:
		bookCounterS++;
		break;
	case 3:
		bookCounterF++;
		break;
	case 4:
		bookCounterA++;
		break;
	default:
		// Error message
		std::cout << "ERROR: Genre given is invalid. Programmer faults";
		exit(1);
	}

	// Assign ID based on genre and counter
	this->bookID = calcBookID(bGenre);

	// Vector, used to keep track of instance's address
	bookInstances.push_back(this);

	// Show created book
	std::cout << "The book named, \"" << this->bookName << "\" with the ID \"" << this->bookID << "\" has been sucessfully created." << std::endl;
	std::cout << "You may now browse \"" << this->bookName <<"\" under \"" << this->bookGenre << "\" section" << std::endl;
}

// Setter, to modify attribute of Book
void Book::setBookID(int newBookID)
{
	Book::bookID = newBookID; // Modify book id
}

void Book::setBookName(std::string newBookName)
{
	Book::bookName = newBookName; // Modify book name
}

void Book::setBookGenre(int newBookGenre)
{
	Book::bookName = checkBookGenre(newBookGenre);  // Modify book genre
}

// Getter, to show attribute of Book
std::string Book::getBookID() const
{
	return Book::bookID;	// Show book id
}

std::string Book::getBookName() const
{
	return Book::bookName;	// Show book name
}

std::string Book::getBookGenre() const
{
	return Book::bookGenre;	// Show book genre
}

// Display list of available book genre
std::string* Book::getBookGenreList()
{
	return bookGenreOptions;
}

// Validate book genre, ensure only predetermined option is used
std::string Book::checkBookGenre(int unverifyBookGenre)
{
	// Used to validation, break while loop if genre is valid
	bool bookGenreIsValid = false;

	// Ask user in repeat, if given invalid input
	while (bookGenreIsValid == false)
	{
		// Validate user input
		switch (unverifyBookGenre)
		{
		case 0:
			Book::bookGenre = bookGenreOptions[0];
			bookGenreIsValid = true;
			break;
		case 1:
			Book::bookGenre = bookGenreOptions[1];
			bookGenreIsValid = true;
			break;
		case 2:
			Book::bookGenre = bookGenreOptions[2];
			bookGenreIsValid = true;
			break;
		case 3:
			Book::bookGenre = bookGenreOptions[3];
			bookGenreIsValid = true;
			break;
		case 4:
			Book::bookGenre = bookGenreOptions[4];
			bookGenreIsValid = true;
			break;
		default:
			// Error message
			std::cout << "ERROR: Invalid input, please choose a genre from 0 to " << std::size(bookGenreOptions) - 1 << "\n";

			// Ask user to enter a valid book genre
			std::cout << "Please select a genre for " << getBookGenre() << "\n";

			// Show valid book genre
			getBookGenreList();

			// Added spacing for visual clarify
			std::cout << "\n";

			// User's input
			std::cin >> unverifyBookGenre;
			break;
		}
	}

	// Return valid genre option
	return bookGenreOptions[unverifyBookGenre];
}

// Calculate bookID based on genre and counter, used to assign bookID automatically
std::string Book::calcBookID(int bGenre)
{
	// Depending on the genre, assign respective symbol and counter
	switch (bGenre)
	{
	case 0:
		return "H" + std::to_string(bookCounterH);
	case 1:
		return "R" + std::to_string(bookCounterR);
	case 2:
		return "S" + std::to_string(bookCounterS);
	case 3:
		return "F" + std::to_string(bookCounterF);
	case 4:
		return "A" + std::to_string(bookCounterA);
	default:
		// Error message
		std::cout << "ERROR: Calculation for ID can't be perform since genre given is invalid. Programmer faults";
		exit(1);
	}
}

// Used to verify if an instance exist, return pointer to instance if yes
Book* Book::searchBook(const std::string& bookID)
{
	// For every instance created
	for (Book* book : bookInstances)
	{
		// If matches book id
		if (book->getBookID() == bookID)
		{
			// Return pointer to book
			return book;
		}
	}
	// If not found, return a nullptr
	return nullptr;
}

// Check if any book instance is created, return true if no book instance exist
bool Book::isLibraryEmpty()
{
	// If no book instance exist
	if (bookInstances.empty() == true)
	{
		return true;
	}
	// If book instance exist
	else if (bookInstances.empty() == false)
	{
		return false;
	}
	else
	{
		// Used for diagnostic
		std::cout << "ERROR: isLibraryEmpty cannot produce a true or false" << std::endl;
		exit(1);
	}
}

// Display all book with its respestive information
void Book::getAllBook()
{
	// Counter to interate over each instances
	int counter = 0;

	// If no book instance exist
	if (bookInstances.empty() == true)
	{
		std::cout << "There are currently no book in the library." << std::endl;
	}
	// If book instances exist
	else if (bookInstances.empty() == false)
	{
		// For every book instance that exist, display book informtion
		for (const auto& instance : bookInstances) {
			std::cout << "BOOK " << std::to_string(counter) << std::endl;
			std::cout << "Book Name: " << instance->bookName << std::endl;
			std::cout << "Book ID: " << instance->bookID << std::endl;
			std::cout << "Book Genre: " << instance->bookGenre << std::endl << std::endl;
			counter++;
		}
	}
	else
	{
		// Used for diagnostic 
		std::cout << "ERROR: getAllBook can't display book due to unexpected reason" << std::endl;
		exit(1);
	}
}

// Sort book by genre
void Book::getSortByGenreBook(int bGenre)
{
	// If no book instances exist
	if (bookInstances.empty()) {
		std::cout << "There are currently no books in the library." << std::endl;
	}
	// If book instance exist
	else {
		// Variable
		bool found = false;	// If instance with specified genre is found
		int counter = 0;	// Used to count how many instance exist

		// For book instance that exist, display book information depending on genre
		for (const auto& instance : bookInstances) {
			if (instance->bookGenre == bookGenreOptions[bGenre]) {
				std::cout << "Instance " << std::to_string(counter) << std::endl;
				std::cout << "Book Name: " << instance->bookName << std::endl;
				std::cout << "Book ID: " << instance->bookID << std::endl;
				std::cout << "Book Genre: " << instance->bookGenre << std::endl << std::endl;

				// Book is found
				found = true;
				// Increment counter
				counter++;
			}
		}
		// If no book can be found within genre
		if (!found) {
			std::cout << "No books found within the specified genre." << std::endl;
		}
	}

}

// Used to obtain int value of how many book instances exist
int Book::getBookCounterAll()
{
	return bookCounterAll;
}

// Used to obtain int value of how many book instances with a specified book genre exist
int Book::getBookCounterGenre(int bGenre)
{
	// Depeding on parameter given
	switch (bGenre)
	{
	case 0:
		return bookCounterH;
	case 1:
		return bookCounterR;
	case 2:
		return bookCounterS;
	case 3:
		return bookCounterF;
	case 4:
		return bookCounterA;
	default:
		// Used for diagnostic
		std::cout << "ERROR: Genre given is invalid. Check getBookCounterGenre()";
		exit(1);
	}
}

// Delete a book instance
void Book::removeBook(const std::string& bBookID)
{
	// Variable
	bool found = false;			// If instances is found
	std::string removeGenreStr;	// Which genre is the instance
	int removeGenreNum = 0;		// Decrement genre counter

	// Find the book object with the given ID
	for (auto it = bookInstances.begin(); it != bookInstances.end(); ++it)
	{
		// If the instance with the book ID is found
		if ((*it)->bookID == bBookID)
		{
			// Assign the genre of the book that will be remove
			removeGenreStr = (*it)->bookGenre; 

			// Find the index of the genre using predefined array
			for (int index = 0; index < 5; index++) 
				if (removeGenreStr == bookGenreOptions[index])  
				{
					// Assign the index
					removeGenreNum = index;   
				}

			// Erase the book object from the vector
			delete* it;
			bookInstances.erase(it);
			found = true;
			break;  // Exit the loop after removing the book
		}
	}
	
	// Depending on the genre, the respective counter is decremented
	switch (removeGenreNum)
	{
	case 0:
		bookCounterH--;
		break;
	case 1:
		bookCounterR--;
		break;
	case 2:
		bookCounterS--;
		break;
	case 3:
		bookCounterF--;
		break;
	case 4:
		bookCounterA--;
		break;
	default:
		// Error message
		std::cout << "ERROR: Genre given is invalid. Check removeBook()";
		exit(1);
	}

	// Check for the book ID and handles the case when the ID is not found
	if (found == true)
	{
		std::cout << "Book with ID " << bBookID << " has been removed." << std::endl;
	}
	else
	{
		std::cout << "Book with ID " << bBookID << " not found." << std::endl;
	}
}


