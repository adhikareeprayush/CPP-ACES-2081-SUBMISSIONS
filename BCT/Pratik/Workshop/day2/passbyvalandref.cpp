//pass by value
void increment(int a) {
    a = a + 1; // This will not affect the original variable,passing by value does not affect the original value
            //When you pass by value, a copy of the variable is made,so any changes inside the function do not impact the original variable outside the function
}

//pass by reference
void incrementByReference(int &a) {
    a=++a; // This will not affect the original variable
           //When you pass by reference (using int &a), the function receives a reference to the original variable, not a copy. Any changes made to a inside the function will directly modify the original variable outside the function.
}