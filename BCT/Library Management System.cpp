#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 100;

class Book
{
    int id;
    string title, author;
    bool issued;

public:
    Book() : id(0), issued(false) {}
    void input(int bookId)
    {
        id = bookId;
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);
        issued = false;
    }
    void display()
    {
        cout << id << " | " << title << " | " << author << " | " << (issued ? "Issued" : "Available") << endl;
    }
    int getId() { return id; }
    bool isIssued() { return issued; }
    void setIssued(bool val) { issued = val; }

    string getTitle() { return title; }
    string getAuthor() { return author; }
    void setTitle(const string &t) { title = t; }
    void setAuthor(const string &a) { author = a; }
    void setId(int i) { id = i; }
};

class User
{
    string username, password, role;

public:
    void input()
    {
        cout << "Enter username: ";
        getline(cin, username);
        cout << "Enter password: ";
        getline(cin, password);
        cout << "Enter role (admin/member): ";
        getline(cin, role);
    }
    bool checkLogin(const string &u, const string &p)
    {
        return username == u && password == p;
    }
    string getRole() { return role; }
    string getUsername() { return username; }
    string getPassword() { return password; }

    void setUsername(const string &u) { username = u; }
    void setPassword(const string &p) { password = p; }
    void setRole(const string &r) { role = r; }
};

class LibrarySystem
{
    Book books[MAX];
    User users[MAX];
    int bookCount = 0, userCount = 0;

    void saveUsers()
    {
        ofstream fout("users.txt");
        fout << userCount << "\n";
        for (int i = 0; i < userCount; i++)
        {
            fout << users[i].getUsername() << "\n"
                 << users[i].getPassword() << "\n"
                 << users[i].getRole() << "\n";
        }
        fout.close();
    }

    void loadUsers()
    {
        ifstream fin("users.txt");
        if (!fin)
            return;

        fin >> userCount;
        fin.ignore();
        for (int i = 0; i < userCount; i++)
        {
            string u, p, r;
            getline(fin, u);
            getline(fin, p);
            getline(fin, r);
            users[i].setUsername(u);
            users[i].setPassword(p);
            users[i].setRole(r);
        }
        fin.close();
    }

    void saveBooks()
    {
        ofstream fout("books.txt");
        fout << bookCount << "\n";
        for (int i = 0; i < bookCount; i++)
        {
            fout << books[i].getId() << "\n"
                 << books[i].getTitle() << "\n"
                 << books[i].getAuthor() << "\n"
                 << books[i].isIssued() << "\n";
        }
        fout.close();
    }

    void loadBooks()
    {
        ifstream fin("books.txt");
        if (!fin)
            return;

        fin >> bookCount;
        fin.ignore();
        for (int i = 0; i < bookCount; i++)
        {
            int id;
            string title, author;
            bool issued;
            fin >> id;
            fin.ignore();
            getline(fin, title);
            getline(fin, author);
            fin >> issued;
            fin.ignore();

            books[i].setId(id);
            books[i].setTitle(title);
            books[i].setAuthor(author);
            books[i].setIssued(issued);
        }
        fin.close();
    }

    void createDefaultAdminIfNeeded()
    {
        if (userCount == 0)
        {
            cout << "Create default admin user:\n";
            User admin;
            admin.input();
            users[0] = admin;
            userCount = 1;
            saveUsers();
        }
    }

    int stringToInt(const string &s)
    {
        return atoi(s.c_str());
    }

public:
    LibrarySystem()
    {
        loadUsers();
        loadBooks();
        createDefaultAdminIfNeeded();
    }

    int login(string &role)
    {
        string uname, pwd;
        cout << "Username: ";
        getline(cin, uname);
        cout << "Password: ";
        getline(cin, pwd);

        for (int i = 0; i < userCount; i++)
        {
            if (users[i].checkLogin(uname, pwd))
            {
                role = users[i].getRole();
                return i;
            }
        }
        cout << "Invalid login.\n";
        return -1;
    }

    string getUsername(int idx)
    {
        if (idx >= 0 && idx < userCount)
            return users[idx].getUsername();
        return "";
    }

    void addBook()
    {
        if (bookCount >= MAX)
        {
            cout << "Book limit reached.\n";
            return;
        }
        books[bookCount].input(bookCount + 1);
        bookCount++;
        saveBooks();
        cout << "Book added successfully.\n";
    }

    void showBooks()
    {
        cout << "ID | Title | Author | Status\n";
        for (int i = 0; i < bookCount; i++)
            books[i].display();
    }

    void addUser()
    {
        if (userCount >= MAX)
        {
            cout << "User limit reached.\n";
            return;
        }
        users[userCount].input();
        userCount++;
        saveUsers();
        cout << "User added successfully.\n";
    }

    void issueBook(const string &uname)
    {
        string inputId;
        cout << "Enter book ID to issue: ";
        getline(cin, inputId);
        int id = stringToInt(inputId);

        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].getId() == id && !books[i].isIssued())
            {
                books[i].setIssued(true);
                saveBooks();
                cout << "Book issued to " << uname << endl;
                return;
            }
        }
        cout << "Book unavailable or already issued.\n";
    }

    void returnBook()
    {
        string inputId;
        cout << "Enter book ID to return: ";
        getline(cin, inputId);
        int id = stringToInt(inputId);

        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].getId() == id && books[i].isIssued())
            {
                books[i].setIssued(false);
                saveBooks();
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Invalid book ID or book not issued.\n";
    }
};

int main()
{
    LibrarySystem lib;
    string role;
    int idx = lib.login(role);
    if (idx == -1)
        return 0;

    while (true)
    {
        cout << "\n1. View Books\n";
        if (role == "admin")
            cout << "2. Add Book\n3. Add User\n";
        else
            cout << "2. Issue Book\n3. Return Book\n";
        cout << "0. Exit\nChoice: ";

        string choiceStr;
        getline(cin, choiceStr);
        int choice = atoi(choiceStr.c_str());

        if (choice == 0)
            break;
        if (role == "admin")
        {
            if (choice == 1)
                lib.showBooks();
            else if (choice == 2)
                lib.addBook();
            else if (choice == 3)
                lib.addUser();
            else
                cout << "Invalid choice.\n";
        }
        else
        {
            if (choice == 1)
                lib.showBooks();
            else if (choice == 2)
                lib.issueBook(lib.getUsername(idx));
            else if (choice == 3)
                lib.returnBook();
            else
                cout << "Invalid choice.\n";
        }
    }

    cout << "\n--------------------------------------------------\n";
    cout << "Project Developed By:\n";
    cout << " - Anuj Kumar Thakur       (PUR081BCT006)\n";
    cout << " - Bikash Bist             (PUR081BCT012)\n";
    cout << " - Jigyasa Bhattarai       (PUR081BCT024)\n";
    cout << "Course: Library Management System using C++\n";
    cout << "Thank you for using the system!\n";
    cout << "--------------------------------------------------\n";

    return 0;
}
