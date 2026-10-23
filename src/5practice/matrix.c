#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int Rows = 3;
  int Cols = 4;

  int **matrix = (int **)malloc(Rows * sizeof(int *));
  if (matrix == NULL) {
    printf("error of memory allocation for rows\n");
    return 1;
  }

  for (int i = 0; i < Rows; i++) {
    matrix[i] = (int *)malloc(Cols * sizeof(int));
    if (matrix[i] == NULL) {
      printf("error of memory allocation for elements of row %d\n", i);
      return 1;
    }
  }

  for (int i = 0; i < Rows; i++) {
    for (int j = 0; j < Cols; j++) {
      matrix[i][j] = i * Cols + j + 1;
    }
  }

  printf("Resulting matrix:\n");
  for (int i = 0; i < Rows; i++) {
    for (int j = 0; j < Cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("------------------------------------------------------------\n");

  printf("\n%-10s %-10s %-10s %-18s\n", "Row i", "Column j", "Value",
         "Element Address");
  printf("------------------------------------------------------------\n");
  for (int i = 0; i < Rows; i++) {
    for (int j = 0; j < Cols; j++) {
      printf("%-10d %-10d %-10d %-18p\n", i, j, matrix[i][j],
             (void *)&matrix[i][j]);
    }
    printf("------------------------------------------------------------ (End "
           "of row %d)\n",
           i);
  }

  for (int i = 0; i < Rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
  matrix = NULL;

  return 0;
}
