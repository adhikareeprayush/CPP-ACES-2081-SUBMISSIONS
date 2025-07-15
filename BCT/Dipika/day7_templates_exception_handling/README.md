# Day 7 – Templates & Exception Handling

## Objectives
- Write reusable code using templates in C++.
- Handle errors effectively using exception handling mechanisms.

## Topics Covered
- **Function Templates**: Creating generic functions.
- **Class Templates**: Introduction to generic classes.
- **Try-Catch-Throw Exception Model**: Basic exception handling.
- **Catching Multiple Exceptions**: Handling different types of exceptions.
- **Throw and Rethrow**: Throwing and propagating exceptions.

---

## 1. Function Templates

**Function templates** allow you to write generic functions that work with any data type. The `template` keyword is used to define a function that operates on a generic type.

### Example: Function Template for Swapping Two Values
```cpp
#include <iostream>
using namespace std;

// Function template for swapping
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    // Swapping integers
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    // Swapping doubles
    double a = 3.14, b = 2.718;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapValues(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    // Output:
    // Before swap: x = 10, y = 20
    // After swap: x = 20, y = 10
    // Before swap: a = 3.14, b = 2.718
    // After swap: a = 2.718, b = 3.14
    return 0;
}
```

- **Template Syntax**: `template <typename T>` defines a generic type `T`.
- **Usage**: The compiler generates the appropriate function based on the argument types.

---

## 2. Class Templates (Introduction)

**Class templates** allow you to create generic classes that can work with any data type. Like function templates, they use the `template` keyword.

### Example: Class Template for a Generic Pair
```cpp
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    void display() {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};

int main() {
    Pair<int, double> p1(10, 3.14);
    p1.display(); // Output: First: 10, Second: 3.14

    Pair<string, int> p2("Age", 25);
    p2.display(); // Output: First: Age, Second: 25
    return 0;
}
```

- **Key Point**: Class templates are useful for creating reusable data structures like pairs, arrays, or containers.

---

## 3. Try-Catch-Throw Exception Model

**Exception handling** in C++ uses the `try`, `catch`, and `throw` keywords to manage errors gracefully.

- **`try`**: Encloses code that might throw an exception.
- **`throw`**: Signals an error by throwing an exception.
- **`catch`**: Handles the thrown exception.

### Example: Basic Exception Handling
```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        int age;
        cout << "Enter age: ";
        cin >> age;
        if (age < 0) {
            throw "Age cannot be negative!";
        }
        cout << "Age: " << age << endl;
    } catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    return 0;
}
```

- **Output (if age = -5)**:
  ```
  Enter age: -5
  Error: Age cannot be negative!
  ```

---

## 4. Catching Multiple Exceptions

You can use multiple `catch` blocks to handle different types of exceptions.

### Example: Catching Multiple Exceptions
```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        int choice;
        cout << "Enter 1 for string error, 2 for int error: ";
        cin >> choice;
        if (choice == 1) {
            throw "String error occurred!";
        } else if (choice == 2) {
            throw 404;
        } else {
            throw 3.14;
        }
    } catch (const char* msg) {
        cout << "Caught string: " << msg << endl;
    } catch (int e) {
        cout << "Caught integer: " << e << endl;
    } catch (...) { // Catch-all for any other type
        cout << "Caught unknown exception" << endl;
    }
    return 0;
}
```

- **Output (if choice = 2)**:
  ```
  Enter 1 for string error, 2 for int error: 2
  Caught integer: 404
  ```

---

## 5. Throw and Rethrow

You can **throw** an exception to signal an error and **rethrow** an exception to propagate it to an outer `try-catch` block.

### Example: Throw and Rethrow
```cpp
#include <iostream>
using namespace std;

void innerFunction() {
    try {
        throw "Error in inner function!";
    } catch (const char* msg) {
        cout << "Inner catch: " << msg << endl;
        throw; // Rethrow the same exception
    }
}

int main() {
    try {
        innerFunction();
    } catch (const char* msg) {
        cout << "Outer catch: " << msg << endl;
    }
    // Output:
    // Inner catch: Error in inner function!
    // Outer catch: Error in inner function!
    return 0;
}
```

- **Rethrow**: Using `throw;` without an argument rethrows the caught exception.

---

## Hands-On Examples

### 1. Template for Swapping Two Values
```cpp
#include <iostream>
using namespace std;

template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    string s1 = "Hello", s2 = "World";
    cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << endl;
    swapValues(s1, s2);
    cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << endl;

    // Output:
    // Before swap: x = 5, y = 10
    // After swap: x = 10, y = 5
    // Before swap: s1 = Hello, s2 = World
    // After swap: s1 = World, s2 = Hello
    return 0;
}
```

### 2. Exception Handling for Division by Zero
```cpp
#include <iostream>
using namespace std;

double divide(double a, double b) {
    if (b == 0) {
        throw "Division by zero is not allowed!";
    }
    return a / b;
}

int main() {
    try {
        double result = divide(10.0, 0.0);
        cout << "Result: " << result << endl;
    } catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    // Output: Error: Division by zero is not allowed!
    return 0;
}
```

---

## Summary
- **Function Templates**: Enable generic programming for functions.
- **Class Templates**: Allow creation of generic classes (introduced briefly).
- **Exception Handling**: Use `try`, `catch`, and `throw` to manage errors.
- **Multiple Exceptions**: Handle different exception types with multiple `catch` blocks.
- **Throw and Rethrow**: Throw exceptions to signal errors and rethrow to propagate them.

## Practice Questions
1. Create a function template to find the maximum of two values of any type.
2. Implement a class template for a stack that supports push and pop operations.
3. Write a program that handles multiple exceptions for a simple calculator (e.g., division by zero, invalid input).