#ifndef BOOK_H
#define BOOK_H

// Prerequisite header
#include "Common.h"
#include <vector>

// Book Class
class Book
{
private:
	// Book Attributes
	std::string bookID;			// Book ID
	std::string bookName;		// Book Name/Title
	std::string bookGenre;		// Book Genre

	// Keep track of each book address, used for displaying all instance's attribute
	static std::vector<Book*> bookInstances; 
public:
	// Constructor
	Book(std::string bName, int bGenre);

	// To modify book attribute
	void setBookID(int newBookID);
	void setBookName(std::string newBookName);
	void setBookGenre(int newBookGenre);

	// To display book attribute
	std::string getBookID() const;
	std::string getBookName() const;
	std::string getBookGenre() const;

	// Return a list of available book genre
	std::string* getBookGenreList();

	// Validating input for book genre, since book genre must only have predetermined options
	std::string checkBookGenre(int unverifyBookGenre);

	// Determined the book id, based on genre and counter
	std::string calcBookID(int bGenre);

	// Find if the bookID given exist
	static Book* searchBook(const std::string& bookID);

	// Check if there is any book available in library
	static bool isLibraryEmpty();

	// Display all available book with their respective ID, Name and Genre
	static void getAllBook();

	// Display book by genre their respective ID, Name and Genre
	static void getSortByGenreBook(int bGenre);

	// Obtain the value from couter for all book
	static int getBookCounterAll();

	// Obtain the value from counter sorting 
	static int getBookCounterGenre(int bGenre);

	// Function to remove a book object by ID
	static void removeBook(const std::string& bookID);
};

#endif // !BOOK_H


