#include <stdio.h>

int main() {
    char* name = "Hello";
    
    for(int i = 0; i< sizeof(name)+1; i++) {
        printf("%p\n",(name+i));
    }

    return 0;
}