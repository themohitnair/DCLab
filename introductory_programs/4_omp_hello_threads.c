#include <omp.h>
#include <stdio.h>

int main() {
  int iam, np;
#pragma omp parallel default(shared) private(iam, np)
  {
    int np = omp_get_num_threads();
    int iam = omp_get_thread_num();
    printf("hello from thread %d out of %d\n", iam, np);
  }
}

/* Output:
hello from thread 1 out of 20
hello from thread 2 out of 20
hello from thread 10 out of 20
hello from thread 4 out of 20
hello from thread 7 out of 20
hello from thread 12 out of 20
hello from thread 19 out of 20
hello from thread 14 out of 20
hello from thread 0 out of 20
hello from thread 16 out of 20
hello from thread 17 out of 20
hello from thread 18 out of 20
hello from thread 9 out of 20
hello from thread 8 out of 20
hello from thread 6 out of 20
hello from thread 5 out of 20
hello from thread 3 out of 20
hello from thread 15 out of 20
hello from thread 13 out of 20
hello from thread 11 out of 20
*/