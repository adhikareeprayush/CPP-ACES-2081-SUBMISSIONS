#include <iostream>
#include <vector>
#include <windows.h>
#include <chrono>
#include <thread>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <limits>
#include <conio.h>
using namespace std;


#define COLOR_DEFAULT 7
#define COLOR_TITLE 11
#define COLOR_MENU 10
#define COLOR_INPUT 14
#define COLOR_ERROR 12
#define COLOR_SUCCESS 10
#define COLOR_BOOK_FRAME 9
#define COLOR_CHECKOUT 13


const string TOP_LEFT = "+";
const string TOP_RIGHT = "+";
const string BOTTOM_LEFT = "+";
const string BOTTOM_RIGHT = "+";
const string HORIZONTAL = "-";
const string VERTICAL = "|";
const int BOX_WIDTH = 50;


class Book {

private:
    string id;
    string subject;
    string author;
    string student_id;
    string due_date;
    bool is_available;

public:
    Book(string id = "", string subject = "", string author = "",
         string student_id = "None", string due_date = "Not checked out",
         bool is_available = true)
        : id(id), subject(subject), author(author),
          student_id(student_id), due_date(due_date),
          is_available(is_available) {}

    string getId() const {
        return id;
        }
    string getSubject() const {
        return subject;
        }
    string getAuthor() const {
        return author;
        }
    string getStudentId() const {
        return student_id;
        }
    string getDueDate() const {
        return due_date;
        }
    bool getAvailability() const {
         return is_available;
         }

    void setId(string newId) {
        id = newId;
        }
    void setSubject(string newSubject) {
        subject = newSubject;
        }
    void setAuthor(string newAuthor) {
         author = newAuthor;
         }
    void setStudentId(string newStudentId) {
        student_id = newStudentId;
         }
    void setDueDate(string newDueDate) {
        due_date = newDueDate;
        }
    void setAvailability(bool availability) {
         is_available = availability;
         }

    void display() const {
        cout << VERTICAL << " ID:      " << left << setw(BOX_WIDTH-12) << id << VERTICAL << endl;
        cout << VERTICAL << " Subject: " << left << setw(BOX_WIDTH-12) << subject << VERTICAL << endl;
        cout << VERTICAL << " Author:  " << left << setw(BOX_WIDTH-12) << author << VERTICAL << endl;
        cout << VERTICAL << " Status:  " << left << setw(BOX_WIDTH-12)
             << (is_available ? "AVAILABLE" : "CHECKED OUT") << VERTICAL << endl;

        if (!is_available) {
            cout << VERTICAL << " Borrower:" << left << setw(BOX_WIDTH-12) << student_id << VERTICAL << endl;
            cout << VERTICAL << " Due Date: " << left << setw(BOX_WIDTH-12) << due_date << VERTICAL << endl;

            // Parse due date
            tm due_tm = {};
            istringstream iss(due_date);
            iss >> get_time(&due_tm, "%Y-%m-%d");
            time_t due_time = mktime(&due_tm);
            time_t now = time(0);

            if (due_time != -1) {
                double diff = difftime(due_time, now);
                int days = static_cast<int>(diff / (60 * 60 * 24));

                if (days < 0) {
                    cout << VERTICAL << " Return:  " << left << setw(BOX_WIDTH-12)
                         << "OVERDUE (" + to_string(-days) + " days)" << VERTICAL << endl;
                }
                else {
                    cout << VERTICAL << " Return:  " << left << setw(BOX_WIDTH-12)
                         << "Due in " + to_string(days) + " days" << VERTICAL << endl;
                }
            }
        }
        else
         {
            cout << VERTICAL << " Return:  " << left << setw(BOX_WIDTH-12)
                 << "BOOK IN LIBRARY" << VERTICAL << endl;
        }
    }
};

// UI Functions
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen() {
    system("cls");
    SetConsoleTitle("Library Management System");
}

void drawHorizontalLine() {
    cout << TOP_LEFT << string(BOX_WIDTH-2, HORIZONTAL[0]) << TOP_RIGHT << endl;
}

void drawCenteredText(const string& text) {
    int padding = (BOX_WIDTH - text.length() - 2) / 2;
    cout << VERTICAL << string(padding, ' ') << text
         << string(BOX_WIDTH - text.length() - padding - 2, ' ') << VERTICAL << endl;
}

void drawLeftText(const string& text) {
    cout << VERTICAL << " " << left << setw(BOX_WIDTH-3) << text << VERTICAL << endl;
}

void drawHeader(const string& title) {
    setColor(COLOR_TITLE);
    drawHorizontalLine();
    drawCenteredText(title);
    drawHorizontalLine();
    setColor(COLOR_DEFAULT);
}

void drawMenu(const vector<string>& options) {
    setColor(COLOR_MENU);
    drawHorizontalLine();
    for (const auto& option : options) {
        drawLeftText(option);
    }
    drawHorizontalLine();
    cout << VERTICAL << " Select: ";
    setColor(COLOR_INPUT);
}

void drawBookCard(const Book& book) {
    setColor(COLOR_BOOK_FRAME);
    drawHorizontalLine();
    book.display();
    drawHorizontalLine();
    cout << endl;
    setColor(COLOR_DEFAULT);
}

void typewriterEffect(const string& message, int color = COLOR_DEFAULT, int speed = 30) {
    setColor(color);
    for (char c : message) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
    setColor(COLOR_DEFAULT);
}

void showMessage(const string& message, int color = COLOR_DEFAULT, bool newline = true) {
    setColor(color);
    cout << " " << message;
    if (newline) cout << endl;
    setColor(COLOR_DEFAULT);
}

void pressEnterToContinue() {
    cout << "\n Press Enter to continue...";
    // Clear the input buffer completely
    cin.clear();
    // Wait for Enter key
    while (cin.get() != '\n');
}

// Library Class
class Library {
private:
    vector<Book> books;
    const string filename = "library_data.txt";

    string calculateDueDate() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        ltm->tm_mday += 14;
        mktime(ltm);

        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
        return string(buffer);
    }

    void clearInputBuffer() {
        cin.clear();
        while(cin.get() != '\n');
    }

    int getIntegerInput() {
        int value;
        while (!(cin >> value)) {
            clearInputBuffer();
            showMessage("Invalid input! Please enter a number: ", COLOR_ERROR, false);
        }
        clearInputBuffer();
        return value;
    }

    string getStringInput() {
        string input;
        getline(cin, input);
        // Remove any | characters to prevent file format corruption
        input.erase(remove(input.begin(), input.end(), '|'), input.end());
        return input;
    }

public:
    Library() { loadFromFile(); }
    ~Library() { saveToFile(); }

    void loadFromFile() {
        ifstream file(filename);
        if (!file) return;

        books.clear(); // Clear existing books before loading
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, subject, author, student_id, due_date;
            bool is_available;

            getline(ss, id, '|');
            getline(ss, subject, '|');
            getline(ss, author, '|');
            getline(ss, student_id, '|');
            getline(ss, due_date, '|');
            ss >> is_available;

            Book book(id, subject, author, student_id, due_date, is_available);
            books.push_back(book);
        }
    }

    void saveToFile() {
        ofstream file(filename);
        if (!file) {
            showMessage("Error saving data to file!", COLOR_ERROR);
            return;
        }

        for (const Book& book : books) {
            file << book.getId() << "|" << book.getSubject() << "|" << book.getAuthor() << "|"
                 << book.getStudentId() << "|" << book.getDueDate() << "|" << book.getAvailability() << "\n";
        }
    }

    void addBook() {
        clearScreen();
        drawHeader("ADD NEW BOOK");

        cout << VERTICAL << " Enter Book ID: ";
        string id = getStringInput();

        cout << VERTICAL << " Enter Subject: ";
        string subject = getStringInput();

        cout << VERTICAL << " Enter Author: ";
        string author = getStringInput();
        drawHorizontalLine();

        Book newBook(id, subject, author);
        books.push_back(newBook);
        saveToFile();

        typewriterEffect("Book added successfully!", COLOR_SUCCESS);
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    void checkoutBook() {
        string book_id, student_id;
        clearScreen();
        drawHeader("CHECKOUT BOOK");

        cout << VERTICAL << " Enter Book ID: ";
        book_id = getStringInput();

        auto it = find_if(books.begin(), books.end(),
            [&book_id](const Book& b) { return b.getId() == book_id; });

        if (it == books.end()) {
            showMessage("Book not found!", COLOR_ERROR);
            pressEnterToContinue();
            return;
        }

        if (!it->getAvailability()) {
            showMessage("Book already checked out by: " + it->getStudentId(), COLOR_ERROR);
            pressEnterToContinue();
            return;
        }

        cout << VERTICAL << " Enter Student ID: ";
        student_id = getStringInput();
        drawHorizontalLine();

        it->setStudentId(student_id);
        it->setDueDate(calculateDueDate());
        it->setAvailability(false);
        saveToFile();

        typewriterEffect("Book checked out successfully!", COLOR_CHECKOUT);
        typewriterEffect("\nDue Date: " + it->getDueDate(), COLOR_CHECKOUT);
        pressEnterToContinue();
    }

    void returnBook() {
        string book_id;
        clearScreen();
        drawHeader("RETURN BOOK");

        cout << VERTICAL << " Enter Book ID: ";
        book_id = getStringInput();
        drawHorizontalLine();

        auto it = find_if(books.begin(), books.end(),
            [&book_id](const Book& b) { return b.getId() == book_id; });

        if (it == books.end()) {
            showMessage("Book not found!", COLOR_ERROR);
            pressEnterToContinue();
            return;
        }

        if (it->getAvailability()) {
            showMessage("Book wasn't checked out!", COLOR_ERROR);
            pressEnterToContinue();
            return;
        }

        it->setStudentId("None");
        it->setDueDate("Not checked out");
        it->setAvailability(true);
        saveToFile();

        typewriterEffect("Book returned successfully!", COLOR_SUCCESS);
        pressEnterToContinue();
    }

    void searchBook() {
        string book_id;
        clearScreen();
        drawHeader("SEARCH BOOK");

        cout << VERTICAL << " Enter Book ID: ";
        book_id = getStringInput();
        drawHorizontalLine();

        auto it = find_if(books.begin(), books.end(),
            [&book_id](const Book& b) { return b.getId() == book_id; });

        clearScreen();
        if (it != books.end()) {
            drawHeader("BOOK DETAILS");
            drawBookCard(*it);
        } else {
            showMessage("Book not found!", COLOR_ERROR);
        }
        pressEnterToContinue();
    }

    void showAllBooks() {
        clearScreen();
        drawHeader("LIBRARY COLLECTION");

        if (books.empty()) {
            showMessage("No books in collection!", COLOR_ERROR);
        } else {
            for (const Book& book : books) {
                drawBookCard(book);
            }
        }
        pressEnterToContinue();
    }
};

int main() {
    // Console setup for Code::Blocks
    system("mode con: cols=60 lines=30");
    CONSOLE_CURSOR_INFO cursorInfo = {1, false};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    Library library;

    while (true) {
        clearScreen();
        drawHeader("LIBRARY MANAGEMENT SYSTEM");

        vector<string> menu = {
            "1. Add Book",
            "2. Checkout Book",
            "3. Return Book",
            "4. Search Book",
            "5. View All Books",
            "6. Exit"
        };

        drawMenu(menu);

        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.checkoutBook();
                break;
            case 3:
                library.returnBook();
                break;
            case 4:
                library.searchBook();
                break;
            case 5:
                library.showAllBooks();
                break;
            case 6:
                clearScreen();
                drawHeader("THANK YOU!");
                typewriterEffect("Goodbye! Have a nice day!", COLOR_SUCCESS);
                this_thread::sleep_for(chrono::milliseconds(1500));
                return 0;
            default:
                showMessage("Invalid choice! Please try again.", COLOR_ERROR);
                this_thread::sleep_for(chrono::milliseconds(1000));
        }
    }
}
