#include <stdio.h>
#include <stdlib.h>

int main() {
  int amount;
  
  printf("Enter the amount of N: ");
    if (scanf("%d", &amount) != 1 || amount <= 0) {
        printf("error: invalid input\n");
        return 1;
    }

  int *someArray = (int*)malloc(amount * sizeof(int));
  if (someArray == NULL) {
        printf("error in memory allocation\n");
        return 1;
    }
  
  for (int i = 0; i < amount; i++) {
        someArray[i] = (i + 1);
    }
  
  printf("\n%-10s %-15s %-18s\n", "Index", "Value", "Address in Memory");
  printf("--------------------------------------------------\n");
  for (int i = 0; i < amount; i++) {
    printf("%-10d %-15d %-18p\n", i, someArray[i], (void *)&someArray[i]);
  }

    printf("\n--- Analysis of Addresses ---\n");
    printf("Size of int: %zu bytes.\n", sizeof(int));
    
    if (amount > 1) {
        char *addr0 = (char *)&someArray[0];
        char *addr1 = (char *)&someArray[1];
        long long diff_bytes = (long long)addr1 - (long long)addr0;
        
        printf("Address someArray[0]: %p\n", (void *)&someArray[0]);
        printf("Address someArray[1]: %p\n", (void *)&someArray[1]);
        printf("Difference between addresses: %lld bytes.\n", diff_bytes);
    }
  
  free(someArray);
  someArray = NULL;

  return 0;
}