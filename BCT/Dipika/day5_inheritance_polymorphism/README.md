# Day 5 – Inheritance & Polymorphism

## Objectives
- Implement and explore inheritance in C++.
- Understand and use virtual functions to achieve polymorphism.

## Topics Covered
- **Inheritance**: Single and multilevel inheritance.
- **Base and Derived Class Relationships**
- **Constructor Invocation Order**
- **Polymorphism Basics**
- **Virtual Functions**
- **Abstract Classes** (Pure Virtual Functions)

---

## 1. Inheritance: Single and Multilevel

**Inheritance** allows a class (derived class) to inherit properties and behaviors from another class (base class). This promotes code reusability and establishes a hierarchical relationship.

### Types of Inheritance
1. **Single Inheritance**: A derived class inherits from one base class.
2. **Multilevel Inheritance**: A class is derived from another derived class, forming a chain.

### Example: Single Inheritance
```cpp
#include <iostream>
#include <string>
using namespace std;

class Person { // Base class
public:
    string name;
    int age;

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Teacher : public Person { // Derived class
public:
    string subject;

    void showTeacher() {
        cout << "Name: " << name << ", Subject: " << subject << endl;
    }
};

int main() {
    Teacher t1;
    t1.name = "Alice";
    t1.age = 35;
    t1.subject = "Mathematics";
    t1.display(); // From base class: Name: Alice, Age: 35
    t1.showTeacher(); // From derived class: Name: Alice, Subject: Mathematics
    return 0;
}
```

### Example: Multilevel Inheritance
```cpp
#include <iostream>
#include <string>
using namespace std;

class Person { // Base class
public:
    string name;
    void display() {
        cout << "Name: " << name << endl;
    }
};

class Teacher : public Person { // First derived class
public:
    string subject;
    void showTeacher() {
        cout << "Subject: " << subject << endl;
    }
};

class SeniorTeacher : public Teacher { // Second derived class
public:
    int experience;
    void showSeniorTeacher() {
        cout << "Experience: " << experience << " years" << endl;
    }
};

int main() {
    SeniorTeacher st;
    st.name = "Bob";
    st.subject = "Physics";
    st.experience = 10;
    st.display(); // From Person: Name: Bob
    st.showTeacher(); // From Teacher: Subject: Physics
    st.showSeniorTeacher(); // From SeniorTeacher: Experience: 10 years
    return 0;
}
```

---

## 2. Base and Derived Class Relationships

- **Base Class**: The parent class from which properties are inherited.
- **Derived Class**: The child class that inherits from the base class.
- **Access Specifiers**: Control access to base class members in the derived class (`public`, `private`, `protected`).

### Key Points
- `public` inheritance: Public and protected members of the base class remain accessible in the derived class.
- `private` members of the base class are not directly accessible in the derived class.
- Use access specifiers in the inheritance declaration (e.g., `class Teacher : public Person`).

---

## 3. Constructor Invocation Order

In inheritance, constructors are called in the order from base class to derived class. Destructors are called in the reverse order.

### Example: Constructor Invocation
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor called" << endl;
    }
    ~Base() {
        cout << "Base destructor called" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor called" << endl;
    }
    ~Derived() {
        cout << "Derived destructor called" << endl;
    }
};

int main() {
    Derived d;
    // Output:
    // Base constructor called
    // Derived constructor called
    // Derived destructor called
    // Base destructor called
    return 0;
}
```

- **Order**: Base constructor → Derived constructor → Derived destructor → Base destructor.

---

## 4. Polymorphism Basics

**Polymorphism** allows objects of different classes to be treated as objects of a common base class. It is achieved through:
- Function overriding (same function name in base and derived classes).
- Virtual functions (for runtime polymorphism).

---

## 5. Virtual Functions

A **virtual function** is a member function in the base class that can be overridden in the derived class. Declared with the `virtual` keyword, it enables **runtime polymorphism** using base class pointers or references.

### Example: Virtual Function with Base Class Pointer
```cpp
#include <iostream>
using namespace std;

class Person {
public:
    virtual void display() { // Virtual function
        cout << "I am a Person" << endl;
    }
};

class Teacher : public Person {
public:
    void display() override { // Override base class function
        cout << "I am a Teacher" << endl;
    }
};

int main() {
    Person* p;
    Teacher t;
    p = &t; // Base class pointer pointing to derived class object
    p->display(); // Output: I am a Teacher (due to virtual function)
    return 0;
}
```

- Without `virtual`, the base class function would be called (compile-time binding).
- With `virtual`, the derived class function is called (runtime binding).

---

## 6. Abstract Classes (Pure Virtual Functions)

An **abstract class** is a class that cannot be instantiated and is meant to be inherited. It contains at least one **pure virtual function** (declared with `= 0`).

### Example: Abstract Class
```cpp
#include <iostream>
using namespace std;

class Animal { // Abstract class
public:
    virtual void makeSound() = 0; // Pure virtual function
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    // Animal a; // Error: Cannot instantiate abstract class
    Dog d;
    Cat c;
    d.makeSound(); // Output: Woof!
    c.makeSound(); // Output: Meow!
    return 0;
}
```

- **Pure Virtual Function**: Forces derived classes to provide an implementation.
- **Abstract Class**: Serves as a blueprint for derived classes.

---

## Hands-On Examples

### 1. Base Class `Person`, Derived Class `Teacher`
```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Teacher : public Person {
private:
    string subject;
public:
    Teacher(string n, int a, string s) : Person(n, a), subject(s) {}
    void display() override {
        cout << "Name: " << name << ", Age: " << age << ", Subject: " << subject << endl;
    }
};

int main() {
    Person* p = new Teacher("Alice", 35, "Mathematics");
    p->display(); // Output: Name: Alice, Age: 35, Subject: Mathematics
    delete p;
    return 0;
}
```

### 2. Virtual Function Example with Base Class Pointer
```cpp
#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void start() {
        cout << "Vehicle starting" << endl;
    }
};

class Car : public Vehicle {
public:
    void start() override {
        cout << "Car starting with engine roar!" << endl;
    }
};

int main() {
    Vehicle* v = new Car();
    v->start(); // Output: Car starting with engine roar!
    delete v;
    return 0;
}
```

---

## Summary
- **Inheritance**: Enables code reuse through single and multilevel inheritance.
- **Base and Derived Classes**: Establish parent-child relationships.
- **Constructor Invocation**: Base class constructors are called before derived class constructors.
- **Polymorphism**: Achieved through function overriding and virtual functions.
- **Virtual Functions**: Enable runtime polymorphism using base class pointers/references.
- **Abstract Classes**: Contain pure virtual functions and cannot be instantiated.

## Practice Questions
1. Create a `Vehicle` base class and derive `Car` and `Bike` classes with a virtual `start` function.
2. Implement multilevel inheritance with a chain: `Animal` → `Mammal` → `Dog`.
3. Create an abstract class `Shape` with a pure virtual function `area` and derive `Circle` and `Rectangle` classes to implement it.