#include "LibrarySystem.h"
#include "LoanList.h"
#include "LoanNode.h"
#include "Book.h"
#include "Date.h"
#include "Member.h"
#include <Windows.h>
#include <thread>

// Used to clear screen
void clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}

// Add delay for better transition
void addDelay()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1250)); // Delay program by 1.25 second
}

// LOGIN
void gotoXY(int x, int y)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void gotoXY(int x, int y, const std::string& text)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
    std::cout << text;
}

void Draw(int style, int col, int row, int length, int amount)
{
    int a;
    style = (style - 1) * 6;
    char box[12];

    box[0] = '\xDA';
    box[1] = '\xBF';
    box[2] = '\xC0';
    box[3] = '\xD9';
    box[4] = '\xB3';
    box[5] = '\xC4';

    box[6] = '\xC9';
    box[7] = '\xBB';
    box[8] = '\xCB';
    box[9] = '\xBC';
    box[10] = '\xBA';
    box[11] = '\xCD';

    char t1, tr, b1, br, side, edge;
    t1 = box[style];
    tr = box[style + 1];
    b1 = box[style + 2];
    br = box[style + 3];
    side = box[style + 4];
    edge = box[style + 5];

    std::string Line(length - 2, edge);

    gotoXY(col, row);
    std::cout << t1 << Line << tr;

    for (a = 1; a < amount - 1; a++)
    {
        gotoXY(col, row + a);
        std::cout << side;

        gotoXY(col + length - 1, row + a);
        std::cout << side;
    }

    gotoXY(col, (amount + row) - 1);
    std::cout << b1 << Line << br;
}

void login()
{
    // Login
    std::string username, password;
    int counter = 0;
    do
    {
        if (counter > 10)
        {
            std::cout << std::endl << "ERROR: Maximum retry attemped. Please try again later.";
            exit(1);
        }

        std::cout << "\n\n===== Login =====" << std::endl;
        std::cout << "Enter username: ";
        std::cin >> username;

        std::cout << "Enter password: ";
        std::cin >> password;
        if (username == "librarian2023" && password == "1234")
        {
            std::cout << "Login successful. Welcome " << username << "!" << std::endl;
            addDelay();
            clearScreen();
        }
        else
        {
            std::cout << std::endl << "ERROR: Incorrect username or password."
                << std::endl << "Remaining retry: " << 10 - counter << std::endl;
            counter++;
            addDelay();
        }
    } while (username != "librarian2023" || password != "1234");
}

void forgotPassword()
{
    std::string password = "1234";

    while (true)
    {
        std::string answer;
        std::cout << "Forgot password? (yes/no): ";
        std::cin >> answer;

        if (answer == "yes")
        {
            std::cout << "Answer the security question: What is your favorite color? " << std::endl;
            std::string securityAnswer;
            std::cin >> securityAnswer;

            if (securityAnswer == "blue")
            {
                std::cout << "Your password is: " << password << std::endl;
                std::cout << "Do you want to proceed to login? (yes/no): " << std::endl;
                std::string yesNo;
                std::cin >> yesNo;

                if (yesNo == "yes")
                {
                    system("cls");
                    login();
                    break; // Exit the loop after successful login
                }
                else
                {
                    std::cout << std::endl << "Thank you for using our service." << std::endl;
                    exit(0);
                }
            }
            else
            {
                std::cout << "ERROR: Incorrect answer. Password recovery failed. Please Try Again." << std::endl;
            }
        }
        else if (answer == "no")
        {
            std::cout << "Do you want to proceed to login? (yes/no): ";
            std::string yesNo1;
            std::cin >> yesNo1;

            if (yesNo1 == "yes")
            {
                system("cls");
                login();
                break; // Exit the loop after successful login
            }
            else
            {
                std::cout << "Thank you for using our service.";
                exit(0);
            }
        }
        else
        {
            std::cout << "ERROR: Invalid input, please enter yes or no.";
        }
    }
}

void displayLoginScreen()
{

	int option1 = 0;
	gotoXY(8, 1, "\n\t\tWELCOME TO THE LIBRARY\n");			// Displaying the menu 
	gotoXY(5, 2, "\n\t\tLIBRARIAN LOGIN PAGE\n. ");  		// Displaying log in page and exit page
	gotoXY(5, 6, "|| 1. Login");
	gotoXY(5, 7, "|| 2. Forgot Password");
	Draw(2, 1, 4, 117, 6);									// Creates a 2 lines box around the menu
	Draw(2, 0, 3, 120, 7);									// Creates a 2 line box around the 2 lines box

    do
    {
        std::cout << " Choose an option to proceed." << std::endl;
        std::cout << " Your option: ";
        std::cin >> option1;

        if (option1 == 1)
        {
            login();
        }
        else if (option1 == 2)
        {
            forgotPassword();
        }
        else
        {
            std::cout << " ERROR: Invalid option entered. Please choose between 1 or 2" << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(INTMAX_MAX, '\n');  
        }
    } while (option1 < 1 || option1 > 2);
}
// End of Login


// Main menu
void displayMainMenu()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "\033[33m";

    std::cout << "    __    _ __                             __                   ___                _____            __               " << std::endl;
    std::cout << "   / /   (_) /_  _________ ________ __    / /   ___  ____  ____/ (_)___  ____ _   / ___/__  _______/ /____  ____ ___" << std::endl;
    std::cout << "  / /   / / __ \\/ ___/ __ `/ ___/ / / /   / /   / _ \\/ __ \\/ __  / / __ \\/ __ `/   \\__ \\/ / / / ___/ __/ _ \\/ __ `__ \\" << std::endl;
    std::cout << " / /___/ / /_// /  / /_/ / /  / /_/ /   / /___/  __/ / / / /_/ / / / / / /_/ /   ___/ / /_/ (__  ) /_/  __/ / / / / /" << std::endl;
    std::cout << "/_____/_/_.__/_/   \\__,_/_/   \\__, /   /_____/\\___/_/ /_/\\__,_/_/_/ /_/\\__, /   /____/\\__, /____/\\__/\\___/_/ /_/ /_/" << std::endl;
    std::cout << "                             /____/                                   /____/         /____/                         " << std::endl;
    std::cout << "\n";
        // Num refers to the index
    // Action refers to the action that will be taken upon command entered
    // Description tells user about the action result
    // Command refers to what input is needed to excecute action
}

void displayMainMenuOptions()
{
    std::string action;
    void gotoXY(int x, int y);
    void gotoXY(int x, int y, const std::string & text);
    void Draw(int style, int col, int row, int length, int amount);
    gotoXY(8, 11, "COMMAND \tACTION \t\t\tDESCRIPTION\n\n");

    gotoXY(8, 12, "1a \t\tDisplay books \t\tDisplay all available books. \n");
    gotoXY(8, 13, "1b \t\tFilter by genre \tSort and display available books by genre. \n");
    gotoXY(8, 14, "1c \t\tAdd book \t\tAdd a new book to the library. \n");
    gotoXY(8, 15, "1d \t\tRemove Book \t\tRemoves an existing book from library. \n\n");

    gotoXY(8, 17, "2a \t\tDisplay member \t\tDisplay all available members. \n");
    gotoXY(8, 18, "2b \t\tAdd member \t\tAdd a new member. \n");
    gotoXY(8, 19, "2c \t\tRemove member \t\tRemoves an existing member. \n\n");

    gotoXY(8, 21, "3a \t\tDisplay all loan\tDisplay all available loans. \n");
    gotoXY(8, 22, "3b \t\tAdd loan \t\tKeep track of library patrons information when borrowing books. \n");
    gotoXY(8, 23, "3c \t\tRemove loan \t\tRemoves an existing loan.\n");
    gotoXY(8, 24, "3d \t\tEdit loan \t\tConfigure an existing loan. \n");
    gotoXY(8, 25, "3e \t\tReturn loan \t\tKeep track of library patrons return date of borrowed books. \n\n\n");

    gotoXY(8, 26, "q/Q \t\tExit program \t\tExit the program. \n\n");
    Draw(2, 1, 8, 117, 22);		// Creates a 2 lines box around the menu
}

void displayBookMenu()
{
    clearScreen();
    std::cout << "All Book that are currently available: " << std::endl << std::endl;
    Book::getAllBook();
}

// Display book by genre, show counter on how many different genre book exist
void displayBookByGenre()
{
    clearScreen();
    int bookGenreInput = 0;

    do {
        std::cout << "Choose a category from the following genre list" << std::endl;
        std::cout << "by entering their respective number." << std::endl << std::endl; // Added two endl for spacing
        std::cout << "0. Horror - Counter: " << Book::getBookCounterGenre(0) << std::endl;
        std::cout << "1. Romance - Counter: " << Book::getBookCounterGenre(1) << std::endl;
        std::cout << "2. Sci-Fi - Counter: " << Book::getBookCounterGenre(2) << std::endl;
        std::cout << "3. Fantasy - Counter: " << Book::getBookCounterGenre(3) << std::endl;
        std::cout << "4. Adventure - Counter: " << Book::getBookCounterGenre(4) << std::endl << std::endl;
        std::cout << "Enter you chosen category: ";
        std::cin >> bookGenreInput;
        if (std::cin.fail() || bookGenreInput > 4 || bookGenreInput < 0)
        {
            std::cout << std::endl << "ERROR: Invalid input. Please choosen between 0 to 4." << std::endl;
            std::cin.clear();
            std::cin.ignore(INTMAX_MAX, '\n');
            addDelay();
            clearScreen();
        }
        else
        {
            break;
        }
    } while (true);
    Book::getSortByGenreBook(bookGenreInput);
}

// Display member list
void displayMemberMenu()
{
    clearScreen();
    std::cout << "All Member that are currently available: " << std::endl << std::endl;
    Member::getAllMember();
}



