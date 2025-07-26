# Day 4 – Classes and Objects

## Objectives
- Understand class-based programming in C++.
- Learn to work with constructors and destructors effectively.

## Topics Covered
- **Defining Classes and Objects**
- **Access Specifiers** (`private`, `public`, `protected`)
- **Member Functions**
- **Constructors** (default, parameterized)
- **Destructors**
- **The `this` Pointer**
- **Static Members**

---

## 1. Defining Classes and Objects

A **class** in C++ is a user-defined data type that acts as a blueprint for creating objects. It encapsulates data (attributes) and functions (methods) that operate on that data. An **object** is an instance of a class.

### Syntax for Defining a Class
```cpp
class ClassName {
public:
    // Data members (variables)
    // Member functions (methods)
};
```

### Example: Creating a Class and Object
```cpp
#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    string brand;
    int speed;

    void display() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Car car1; // Object creation
    car1.brand = "Toyota";
    car1.speed = 120;
    car1.display(); // Output: Brand: Toyota, Speed: 120 km/h
    return 0;
}
```

- **Class**: `Car` is the blueprint with attributes (`brand`, `speed`) and a method (`display`).
- **Object**: `car1` is an instance of the `Car` class.

---

## 2. Access Specifiers

Access specifiers control the visibility and accessibility of class members. C++ provides three access specifiers:

1. **`public`**: Members are accessible from outside the class.
2. **`private`**: Members are accessible only within the class. (Default for class members)
3. **`protected`**: Members are accessible within the class and in derived classes (used in inheritance).

### Example: Access Specifiers
```cpp
#include <iostream>
using namespace std;

class Example {
private:
    int secret = 42; // Only accessible within the class
public:
    int number = 10; // Accessible from outside the class
protected:
    int protectedNum = 100; // Accessible in derived classes
public:
    void showSecret() {
        cout << "Secret: " << secret << endl;
    }
};

int main() {
    Example obj;
    cout << obj.number << endl; // Accessible
    // cout << obj.secret << endl; // Error: secret is private
    obj.showSecret(); // Output: Secret: 42
    return 0;
}
```

---

## 3. Member Functions

Member functions are functions defined within a class that operate on its objects. They can be defined inside or outside the class.

### Defining Member Functions Outside the Class
```cpp
#include <iostream>
using namespace std;

class Rectangle {
public:
    int length, width;
    int area(); // Declaration
};

// Definition outside the class
int Rectangle::area() {
    return length * width;
}

int main() {
    Rectangle rect;
    rect.length = 5;
    rect.width = 3;
    cout << "Area: " << rect.area() << endl; // Output: Area: 15
    return 0;
}
```

- Use the scope resolution operator (`::`) to define member functions outside the class.

---

## 4. Constructors

A **constructor** is a special member function that is automatically called when an object is created. It has the same name as the class and no return type.

### Types of Constructors
1. **Default Constructor**: No parameters.
2. **Parameterized Constructor**: Takes parameters to initialize object data.

### Example: Default and Parameterized Constructors
```cpp
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int rollNo;

    // Default constructor
    Student() {
        name = "Unknown";
        rollNo = 0;
        cout << "Default constructor called!" << endl;
    }

    // Parameterized constructor
    Student(string n, int r) {
        name = n;
        rollNo = r;
        cout << "Parameterized constructor called!" << endl;
    }

    void display() {
        cout << "Name: " << name << ", Roll No: " << rollNo << endl;
    }
};

int main() {
    Student s1; // Calls default constructor
    s1.display(); // Output: Name: Unknown, Roll No: 0

    Student s2("Alice", 101); // Calls parameterized constructor
    s2.display(); // Output: Name: Alice, Roll No: 101
    return 0;
}
```

---

## 5. Destructors

A **destructor** is a special member function called automatically when an object goes out of scope or is explicitly deleted. It has the same name as the class, prefixed with a tilde (`~`), and no parameters or return type.

### Example: Destructor
```cpp
#include <iostream>
using namespace std;

class Test {
public:
    Test() {
        cout << "Constructor called!" << endl;
    }

    ~Test() {
        cout << "Destructor called!" << endl;
    }
};

int main() {
    Test t1; // Constructor called
    // When t1 goes out of scope, destructor is called
    return 0;
}
```

- **Use Case**: Destructors are useful for releasing resources (e.g., memory, file handles).

---

## 6. The `this` Pointer

The **`this` pointer** is an implicit pointer available in non-static member functions. It points to the object that invoked the member function.

### Example: Using `this` Pointer
```cpp
#include <iostream>
using namespace std;

class Box {
public:
    int length;

    void setLength(int length) {
        this->length = length; // Using 'this' to differentiate
    }

    void display() {
        cout << "Length: " << length << endl;
    }
};

int main() {
    Box b;
    b.setLength(10);
    b.display(); // Output: Length: 10
    return 0;
}
```

- **Purpose**: Resolves ambiguity when parameter names match member variable names.

---

## 7. Static Members

**Static members** belong to the class rather than any specific object. They are shared across all objects of the class.

- **Static Data Members**: Declared with the `static` keyword, initialized outside the class.
- **Static Member Functions**: Can only access static data members and do not require an object to be called.

### Example: Static Members
```cpp
#include <iostream>
using namespace std;

class Counter {
public:
    static int count; // Static data member

    Counter() {
        count++;
    }

    static void showCount() { // Static member function
        cout << "Total objects: " << count << endl;
    }
};

// Initialize static member
int Counter::count = 0;

int main() {
    Counter c1, c2, c3;
    Counter::showCount(); // Output: Total objects: 3
    return 0;
}
```

- **Key Points**:
  - Static members are shared across all objects.
  - Static member functions can be called using the class name (`ClassName::function()`).

---

## Summary
- **Classes and Objects**: Classes are blueprints; objects are instances.
- **Access Specifiers**: Control member accessibility (`public`, `private`, `protected`).
- **Member Functions**: Define behavior of the class.
- **Constructors**: Initialize objects (default or parameterized).
- **Destructors**: Clean up resources when objects are destroyed.
- **The `this` Pointer**: Refers to the current object.
- **Static Members**: Shared across all objects of the class.

## Practice Questions
1. Create a `Book` class with private attributes (`title`, `author`, `price`) and public methods to set and display book info.
2. Implement a class with a static member to track the number of objects created.
3. Write a program using a parameterized constructor and destructor to manage a `Person` class.