#include <omp.h>
#include <stdio.h>

int isPrime(int n) {
  if (n < 2)
    return 0;
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n;
  printf("Enter n value: ");
  scanf("%d", &n);

  double start, end, parallel_time, serial_time;

  // Parallel region
  start = omp_get_wtime();

#pragma omp parallel for
  for (int i = 1; i <= n; i++) {
    if (isPrime(i))
      printf("Parallel: Thread %d found %d\n", omp_get_thread_num(), i);
  }

  end = omp_get_wtime();
  parallel_time = end - start;

  // Serial section
  start = omp_get_wtime();

  for (int i = 1; i <= n; i++) {
    if (isPrime(i))
      printf("Serial: %d\n", i);
  }

  end = omp_get_wtime();
  serial_time = end - start;

  printf("\nTime for parallel = %lf seconds\n", parallel_time);
  printf("Time for serial   = %lf seconds\n", serial_time);

  return 0;
}

/*Output:
Enter n value: 10
Parallel: Thread 6 found 7
Parallel: Thread 4 found 5
Parallel: Thread 1 found 2
Parallel: Thread 2 found 3
Serial: 2
Serial: 3
Serial: 5
Serial: 7

Time for parallel = 0.000524 seconds
Time for serial   = 0.000006 seconds*/