//pass by value
void increment(int a) {
    a = a + 1; // This will not affect the original variable,
}

//pass by reference
void incrementByReference(int &a) {
    a=++a; // This will not affect the original variable
}