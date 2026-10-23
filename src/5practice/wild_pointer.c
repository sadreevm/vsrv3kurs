#include <stdio.h>

int main() {
  // int test = 5;
  // int *wPtr = &test;

  int *wPtr;

  if (wPtr != NULL) {
    printf("Value pointed by wild pointer is :%d\n", *wPtr);
  } else {
    printf("Warning: Pointer is Not Initialized!\n");
  }
  return 0;
}