#include <omp.h>
#include <stdio.h>

int main() {
  int n = 8;
  int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  int sum = 0;
#pragma omp parallel for reduction(+ : sum)
  for (int i = 0; i < n; ++i) {
    sum += a[i];
  }
  printf("sum=%d\n", sum);
  return 0;
}
