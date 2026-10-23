#include <stdio.h>

int global_status = 404; 

int main() {
    printf("Hello, ELF world! Status: %d\n", global_status);
    return 0;
}
