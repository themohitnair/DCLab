#include <omp.h>
#include <stdio.h>

int main() {
  int n;

  printf("Enter number of iterations: ");
  scanf("%d", &n);

#pragma omp parallel for schedule(static, 2)
  for (int i = 0; i < n; i++) {
    printf("Thread %d executing iteration %d\n", omp_get_thread_num(), i);
  }

  return 0;
}

/*Output:
Enter number of iterations: 10
Thread 2 executing iteration 4
Thread 2 executing iteration 5
Thread 0 executing iteration 0
Thread 0 executing iteration 1
Thread 4 executing iteration 8
Thread 4 executing iteration 9
Thread 1 executing iteration 2
Thread 1 executing iteration 3
Thread 3 executing iteration 6
Thread 3 executing iteration 7*/