#include <iostream>
using namespace std;

int main() {
    int nums[] = {1,2,3,4,5};

    for(int i = 0; i<sizeof(nums)/sizeof(nums[0]); i++) {
        cout << "nums[" << i << "] = " << *(nums + i) << endl;
    }    

    return 0;
}