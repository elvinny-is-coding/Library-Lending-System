#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include "Common.h"

// This section handles user input and display output respectively
void clearScreen();					// Clear screen
void addDelay();					// Used to customize delay for the program before clearing input

void displayLoginScreen();			// Display login screen, allows for user or admin login

void displayMainMenu();				// Display main menu logo, is kept separate since might be reused
void displayMainMenuOptions();		// Display main menu options

void displayBookMenu();				// Display a list of book
void displayBookByGenre();			// Sort and display book by genre

void displayMemberMenu();			// Display a list of member
#endif // !LIBRARYSYSTEM_H
