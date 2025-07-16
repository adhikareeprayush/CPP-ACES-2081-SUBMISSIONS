# Day 6 – Operator Overloading & File I/O

## Objectives
- Understand and operator overloading in C++.
- Learn to handle basic file operations for reading and writing data.

## Topics Covered
- **Operator Overloading**: Overloading operators like `+` and `==` as member functions.
- **Friend Function for Overloading**: Using friend functions to overload operators.
- **File I/O**: Using `fstream`, `ifstream`, and `ofstream` for file operations.
- **Opening, Writing, Reading from Text File**: Basic file handling techniques.

---

## 1. Operator Overloading

**Operator overloading** allows you to redefine the behavior of operators (e.g., `+`, `==`) for user-defined types like classes. This makes objects of a class behave like built-in types.

### Overloading Operators as Member Functions
Operators like `+` or `==` can be overloaded as member functions of a class. The left operand is the object calling the function, and the right operand is passed as a parameter.

### Example: Overloading `+` and `==` for a `Complex` Number Class
```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overloading + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloading == operator
    bool operator==(const Complex& other) {
        return (real == other.real && imag == other.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0), c2(1.0, 2.0);
    Complex c3 = c1 + c2; // Uses overloaded + operator
    c3.display(); // Output: 4 + 6i

    if (c1 == c2) // Uses overloaded == operator
        cout << "c1 and c2 are equal" << endl;
    else
        cout << "c1 and c2 are not equal" << endl; // Output: c1 and c2 are not equal
    return 0;
}
```

---

## 2. Friend Function for Overloading

A **friend function** is a non-member function that has access to private and protected members of a class. It is often used for operator overloading when the left operand is not an object of the class (e.g., `cout << obj`).

### Example: Friend Function for Overloading `<<`
```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Friend function to overload << operator
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c(3.0, 4.0);
    cout << c << endl; // Output: 3 + 4i
    return 0;
}
```

- **Friend Function**: Grants `operator<<` access to private members (`real`, `imag`).

---

## 3. File I/O: `fstream`, `ifstream`, `ofstream`

C++ provides three main classes for file operations in the `<fstream>` library:
- **`ofstream`**: Output file stream for writing to files.
- **`ifstream`**: Input file stream for reading from files.
- **`fstream`**: General file stream for both reading and writing.

### Key File Operations
- **Opening a file**: Use `open()` or constructor with modes (`ios::in`, `ios::out`, `ios::app`, etc.).
- **Writing to a file**: Use `<<` operator or `write()`.
- **Reading from a file**: Use `>>` operator, `getline()`, or `read()`.
- **Closing a file**: Use `close()` or rely on destructor.

---

## 4. Opening, Writing, Reading from Text File

### Example: Writing and Reading from a Text File
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Writing to a file
    ofstream outFile("example.txt");
    if (outFile.is_open()) {
        outFile << "Hello, File I/O!\n";
        outFile << "This is a test line.\n";
        outFile.close();
    } else {
        cout << "Unable to open file for writing" << endl;
    }

    // Reading from a file
    ifstream inFile("example.txt");
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading" << endl;
    }
    return 0;
}
```

- **Output** (in `example.txt`):
  ```
  Hello, File I/O!
  This is a test line.
  ```
- **Console Output**:
  ```
  Hello, File I/O!
  This is a test line.
  ```

---

## Hands-On Examples

### 1. Overload `+` for a `Complex` Number Class
```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overloading + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Friend function for << operator
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1(2.5, 3.5), c2(1.5, 2.5);
    Complex c3 = c1 + c2;
    cout << "Sum: " << c3 << endl; // Output: Sum: 4 + 6i
    return 0;
}
```

### 2. Student Record Manager (Write/Read from File)
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    double marks;
public:
    Student(string n = "", int r = 0, double m = 0.0) : name(n), rollNo(r), marks(m) {}

    // Write student data to file
    void writeToFile() {
        ofstream outFile("students.txt", ios::app); // Append mode
        if (outFile.is_open()) {
            outFile << name << "," << rollNo << "," << marks << "\n";
            outFile.close();
        } else {
            cout << "Error opening file for writing" << endl;
        }
    }

    // Read and display all students from file
    static void readFromFile() {
        ifstream inFile("students.txt");
        string line;
        if (inFile.is_open()) {
            cout << "\nStudent Records:\n";
            while (getline(inFile, line)) {
                string name;
                int rollNo;
                double marks;
                size_t pos = 0;
                string token;

                // Parse comma-separated values
                pos = line.find(",");
                name = line.substr(0, pos);
                line.erase(0, pos + 1);

                pos = line.find(",");
                rollNo = stoi(line.substr(0, pos));
                line.erase(0, pos + 1);

                marks = stod(line);

                cout << "Name: " << name << ", Roll No: " << rollNo << ", Marks: " << marks << endl;
            }
            inFile.close();
        } else {
            cout << "Error opening file for reading" << endl;
        }
    }
};

int main() {
    // Create student objects and write to file
    Student s1("Alice", 101, 85.5);
    Student s2("Bob", 102, 90.0);
    s1.writeToFile();
    s2.writeToFile();

    // Read and display all student records
    Student::readFromFile();
    // Output:
    // Student Records:
    // Name: Alice, Roll No: 101, Marks: 85.5
    // Name: Bob, Roll No: 102, Marks: 90
    return 0;
}
```

---

## Summary
- **Operator Overloading**: Redefines operators (`+`, `==`, `<<`) for user-defined classes.
- **Friend Functions**: Allow non-member functions to access private class members for operator overloading.
- **File I/O**: Use `ofstream`, `ifstream`, and `fstream` for writing to and reading from files.
- **File Operations**: Open, write, read, and close text files using standard C++ libraries.

## Practice Questions
1. Overload the `-` operator for the `Complex` class to subtract two complex numbers.
2. Create a class `Point` (x, y coordinates) and overload the `==` operator to compare two points.
3. Extend the `Student` record manager to allow updating a student's marks in the file.