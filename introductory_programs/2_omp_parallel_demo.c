#include <omp.h>
#include <stdio.h>

int main() {
#pragma omp parallel for
  for (int i = 0; i < 10; ++i) {
    printf("iteration %d by thread %d\n", i, omp_get_thread_num());
  }
  return 0;
}

/* Output:
iteration 7 by thread 7
iteration 5 by thread 5
iteration 3 by thread 3
iteration 2 by thread 2
iteration 1 by thread 1
iteration 0 by thread 0
iteration 4 by thread 4
iteration 6 by thread 6
iteration 8 by thread 8
iteration 9 by thread 9
*/