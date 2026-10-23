#include <stdio.h>

// Функция для подсчета чисел
// Принимает:
// - arr: сам массив чисел
// - size: размер массива
// - divisor: параметр (делитель), на который должны делиться числа
// - out_odd_count: указатель, куда запишем количество нечетных чисел
// - out_div_count: указатель, куда запишем количество чисел, делящихся на
// divisor
void count_numbers(int *arr, int size, int divisor, int *out_odd_count,
                   int *out_div_count) {
  *out_odd_count = 0;
  *out_div_count = 0;

  if (divisor == 0) {
    printf("invalid divisor\n");
    return;
  }

  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 != 0) {
      (*out_odd_count)++;
    }

    if (arr[i] % divisor == 0) {
      (*out_div_count)++;
    }
  }
}

int main() {
  int someArray[] = {12, 5, 8, 15, 21, 30, 7};
  int size = sizeof(someArray) / sizeof(someArray[0]);
  int divisor = 5;
  int odd_res = 0;
  int div_res = 0;

  count_numbers(someArray, size, divisor, &odd_res, &div_res);

  printf("Original array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", someArray[i]);
  }
  printf("\nDivisor: %d\n\n", divisor);

  printf("Result --->\n");
  printf("Count of odd numbers: %d\n", odd_res);
  printf("Count of numbers divisible by %d: %d\n", divisor, div_res);

  return 0;
}
