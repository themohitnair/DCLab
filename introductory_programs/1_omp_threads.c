#include <omp.h>
#include <stdio.h>

int main() {
#pragma omp parallel
  {
    printf("Number of thread %d\n", omp_get_thread_num());
  }
}

/* Output:
Number of thread 3
Number of thread 2
Number of thread 9
Number of thread 7
Number of thread 12
Number of thread 13
Number of thread 19
Number of thread 18
Number of thread 14
Number of thread 0
Number of thread 15
Number of thread 10
Number of thread 17
Number of thread 1
Number of thread 8
Number of thread 4
Number of thread 11
Number of thread 16
Number of thread 5
Number of thread 6
*/
