// Passing array to a function
#include <iostream>
using namespace std;

void printArray(int* nums, int size) {
    for(int i = 0; i<size; i++) {
        cout << "nums[" << i << "]" << "=" << *(nums + i) << endl;
    }
}


// void printArray(int nums[], int size) {
//     for(int i = 0; i<size; i++) {
//         cout << "nums[" << i << "]" << "=" << nums[i] << endl;
//     }
//  }

int main() {
    int numbers[] = {1,2,3,4,5};
    cout << numbers;
    // int numberOfElement = sizeof(numbers)/ sizeof(int);
    // printArray(numbers, numberOfElement);
    return 0;
}