#include <omp.h>
#include <stdio.h>

int fib(int n) {
  if (n < 2)
    return n;

  int x, y;

#pragma omp task shared(x) firstprivate(n)
  x = fib(n - 1);

#pragma omp task shared(y) firstprivate(n)
  y = fib(n - 2);

#pragma omp taskwait
  return x + y;
}

int main() {
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  omp_set_num_threads(4);

#pragma omp parallel
  {
#pragma omp single
    {
      for (int i = 0; i < n; i++) {
        printf("fib(%d) = %d (thread %d)\n", i, fib(i), omp_get_thread_num());
      }
    }
  }

  return 0;
}

/*Output:
Enter n: 20
fib(0) = 0 (thread 1)
fib(1) = 1 (thread 1)
fib(2) = 1 (thread 1)
fib(3) = 2 (thread 1)
fib(4) = 3 (thread 1)
fib(5) = 5 (thread 1)
fib(6) = 8 (thread 1)
fib(7) = 13 (thread 1)
fib(8) = 21 (thread 1)
fib(9) = 34 (thread 1)
fib(10) = 55 (thread 1)
fib(11) = 89 (thread 1)
fib(12) = 144 (thread 1)
fib(13) = 233 (thread 1)
fib(14) = 377 (thread 1)
fib(15) = 610 (thread 1)
fib(16) = 987 (thread 1)
fib(17) = 1597 (thread 1)
fib(18) = 2584 (thread 1)
fib(19) = 4181 (thread 1)*/
