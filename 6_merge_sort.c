#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];
  for (i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}

void merge_sort_parallel(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
#pragma omp parallel sections
    {
#pragma omp section
      merge_sort_parallel(arr, l, m);
#pragma omp section
      merge_sort_parallel(arr, m + 1, r);
    }
    merge(arr, l, m, r);
  }
}

void merge_sort_serial(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    merge_sort_serial(arr, l, m);
    merge_sort_serial(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main() {
  int array_size = 10;
  int arr[array_size];
  for (int i = 0; i < array_size; ++i) {
    arr[i] = rand() % 1000;
  }

  double start = omp_get_wtime();
  merge_sort_serial(arr, 0, array_size - 1);
  double end = omp_get_wtime();
  double val = end - start;
  printf("Time for serial is %f\n", val);

  start = omp_get_wtime();
  merge_sort_parallel(arr, 0, array_size - 1);
  end = omp_get_wtime();
  val = end - start;
  printf("Time for parallel is %f\n", val);

  for (int i = 0; i < array_size; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}